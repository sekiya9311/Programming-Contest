import math

def get_int(): return int(input())
def get_float(): return float(input())
def get_line(): return input().split()
def get_lines(v): return [get_line() for _ in range(v)]
def get_int_line(): return list(map(int, get_line()))
def get_int_lines(v): return [get_int_line() for _ in range(v)]
def get_float_line(): return list(map(float, get_line()))
def get_float_lines(v): return [get_float_line() for _ in range(v)]

def index_of(lst, val):
  l = len(lst)
  for i in range(l):
    if (lst[i] == val):
      return i
  return -1

ALPHA = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def convert_str(primes, lst):
  ret = ''
  for val in lst:
    ret += ALPHA[index_of(primes, val)]
  return ret

def solve(problem_num):
    N, L = get_int_line()
    v = get_int_line()

    prime_set = set()
    for i in range(L - 1):
      if (v[i] == v[i + 1]):
        continue
      g = math.gcd(v[i], v[i + 1])
      prime_set.add(g)
      prime_set.add(v[i] // g)
      prime_set.add(v[i + 1] // g)

    primes = list(sorted(prime_set))
    ans_val_left = []
    ans_val_right = []
    st = -1
    l = -1
    r = -1
    for i in range(L - 1):
      if (v[i] != v[i + 1]):
        st = i
        tmp = math.gcd(v[i], v[i + 1])
        l, r = [v[i] // tmp, v[i + 1] // tmp]
        ans_val_right.extend([l, tmp, r])
        break
    
    for i in range(st, 0, -1):
      # left
      l = v[i] // l
      ans_val_left.append(l)

    for i in range(st + 2, L):
      # right
      r = v[i] // r
      ans_val_right.append(r)

    ans_val_left.reverse()
    ans_val = ans_val_left + ans_val_right

    ans = convert_str(primes, ans_val)
    print('Case #%d: %s' % (problem_num, ans))


T = get_int()
for problem_num in range(T):
    solve(problem_num + 1)
