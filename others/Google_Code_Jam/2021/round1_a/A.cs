using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.Http;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace ProgrammingContestTemplateByDotNetCore
{
    #region "Input and Output Classes"

    class Scanner : IDisposable
    {
        private readonly Queue<string> _buffer;
        private readonly char[] _sep;
        private readonly TextReader _reader;

        public Scanner(TextReader reader = null, char[] sep = null)
        {
            _buffer = new Queue<string>();
            _sep = sep ?? new[] {' '};
            _reader = reader ?? Console.In;
        }

        public Scanner(string path, char[] sep = null)
            : this(new StreamReader(path), sep)
        {
        }

        private void CheckBuffer()
        {
            if (_buffer.Any() || _reader.Peek() == -1)
                return;

            string str = string.Empty;
            for (;
                string.IsNullOrWhiteSpace(str);
                str = _reader.ReadLine())
            {
            }

            var values = str.Split(_sep)
                .Where(s => !string.IsNullOrWhiteSpace(s));
            foreach (var item in values)
            {
                _buffer.Enqueue(item);
            }
        }

        public string Next()
        {
            CheckBuffer();
            return _buffer.Dequeue();
        }

        public string[] GetStringArray(int count)
            => GetTArray(count, x => x.Next());

        public int NextInt() => int.Parse(Next());

        public int[] GetIntArray(int count)
            => GetTArray(count, x => x.NextInt());

        public long NextLong() => long.Parse(Next());

        public long[] GetLongArray(int count)
            => GetTArray(count, x => x.NextLong());

        public double NextDouble() => double.Parse(Next());

        public double[] GetDoubleArray(int count)
            => GetTArray(count, x => x.NextDouble());

        public decimal NextDecimal() => decimal.Parse(Next());

        public decimal[] GetDecimalArray(int count)
            => GetTArray(count, x => x.NextDecimal());

        public BigInteger NextBigInt() => BigInteger.Parse(Next());

        public BigInteger[] GetBigIntArray(int count)
            => GetTArray(count, x => x.NextBigInt());

        public T GetT<T>(Func<Scanner, T> func) => func(this);

        public T[] GetTArray<T>(int count, Func<Scanner, T> func)
            => Enumerable.Range(0, count)
                .Select(e => GetT(func))
                .ToArray();

        public bool IsEnd
        {
            get
            {
                CheckBuffer();
                return !_buffer.Any();
            }
        }

        public void Dispose()
        {
            if (!_reader.Equals(Console.In))
                _reader.Dispose();
        }
    }

    class Writer : IDisposable
    {
        private readonly TextWriter _writer;
        private readonly StringBuilder _cache;
        private readonly bool _isReactive;

        public Writer(TextWriter writer = null, bool isReactive = false)
        {
            _writer = writer ?? Console.Out;
            _isReactive = isReactive;
            if (!_isReactive)
                _cache = new StringBuilder();
        }

        public Writer(string path)
            : this(new StreamWriter(path))
        {
        }

        public Writer(bool isReactive)
            : this(null, isReactive)
        {
        }

        public void Write(object value)
        {
            if (_isReactive)
            {
                _writer.Write(value);
                _writer.Flush();
            }
            else
            {
                _cache.Append(value);
            }
        }

        public void WriteFormat(string format, params object[] values)
        {
            var value = string.Format(format, values);
            Write(value);
        }

        public void WriteLine(object value = null)
        {
            Write($"{value}{Environment.NewLine}");
        }

        public void WriteLine(string format, params object[] values)
        {
            WriteFormat($"{format}{Environment.NewLine}", values);
        }

        public void Dispose()
        {
            if (!_isReactive)
            {
                _writer.Write(_cache);
                _writer.Flush();
            }

            if (!_writer.Equals(Console.Out))
            {
                _writer.Dispose();
            }
        }
    }

    public static class Extensions
    {
        public static void Set<TKey, TValue>(
            this IDictionary<TKey, TValue> source,
            TKey key, TValue value)
        {
            if (source.ContainsKey(key))
                source[key] = value;
            else
                source.Add(key, value);
        }

        public static void Update<TKey, TValue>(
            this IDictionary<TKey, TValue> source,
            TKey key, Func<TValue, TValue> update)
        {
            if (!source.ContainsKey(key))
                source.Add(key, default(TValue));
            source[key] = update(source[key]);
        }
    }

    #endregion

    class MainClass : IDisposable
    {
        #region "Template"

        /// <summary> 入力を受け取る </summary>
        private readonly Scanner sc;

        /// <summary> 出力を行う </summary>
        private readonly Writer wr;

        private const string _inputFile = "input.txt";
        private const string _outFile = "output.txt";

        static void Main(string[] args)
        {
            using (new MainClass())
            {
            }
        }

        public MainClass()
        {
            wr = new Writer(_isReactive);
            // TODO: ファイルに出力したい場合はこっち → wr = new Writer(_outFile);

#if DEBUG
            // 手元では、ファイルから入力を受け取る
            sc = new Scanner(_inputFile);
#else
            // 提出時、標準入力から受け取る
            sc = new Scanner();
#endif

            Solve();
        }

        public void Dispose()
        {
            sc?.Dispose();
            wr?.Dispose();
        }

        #endregion


        bool Check(string l, string r)
        {
            if (l.Length < r.Length) return true;
            if (l.Length > r.Length) return false;
            for (int i = 0; i < l.Length; i++)
            {
                if (l[i] < r[i]) return true;
                if (l[i] > r[i]) return false;
            }
            return false;
        }

        void Solve()
        {
            var T = sc.NextInt();

            for (int tmp = 0; tmp < T; tmp++)
            {
                var N = sc.NextInt();
                var X = new string[N];
                for (int i = 0; i < N; i++)
                {
                    X[i] = sc.NextInt().ToString();
                }

                int ans = 0;
                for (int i = 1; i < N; i++)
                {
                    if (Check(X[i - 1], X[i])) continue;
                    if (X[i - 1].Length == X[i].Length)
                    {
                        X[i] += "0";
                        ans++;
                    }
                    else if (X[i - 1].Length > X[i].Length)
                    {
                        var sub = X[i - 1].Substring(0, X[i].Length);
                        var cmp = sub.CompareTo(X[i]);
                        if (cmp < 0)
                        {
                            var l = X[i - 1].Length - X[i].Length;
                            X[i] += new string('0', l);
                            ans += l;
                        }
                        else if (cmp == 0)
                        {
                            var nokori = X[i - 1].Substring(X[i].Length).ToCharArray();
                            if (nokori.All(c => c == '9'))
                            {
                                var l = X[i - 1].Length - X[i].Length + 1;
                                X[i] += new string('0', l);
                                ans += l;
                            }
                            else
                            {
                                bool carry = false;
                                int j = nokori.Length - 1;
                                do
                                {
                                    nokori[j]++;
                                    if (nokori[j] > '9')
                                    {
                                        nokori[j] = '0';
                                        carry = true;
                                    }
                                    else
                                    {
                                        carry = false;
                                    }
                                    j--;
                                } while (carry);

                                X[i] += new string(nokori);
                                ans += nokori.Length;
                            }
                        }
                        else
                        {
                            var l = X[i - 1].Length - X[i].Length + 1;
                            X[i] += new string('0', l);
                            ans += l;
                        }
                    }

                    if (!Check(X[i - 1], X[i]))
                    {
                        throw new Exception();
                    }
                }
                
                wr.WriteLine($"Case #{tmp + 1}: {ans}");
#if DEBUG
                wr.WriteLine(string.Join(" ", X));
#endif
            }
        }
        
        /// <summary>
        /// TODO: リアクティブ問題か否かを指定してね♪
        /// </summary>
        private const bool _isReactive = false;
    }
}
