#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

class BuildingStrings {
public:
    int K;
    const int oneScore = 26 * 50;
    vector<string> findAny(int _K) {
        this->K = _K;
        vector<string> res;
        string buf = "";
        REP(j, 26) buf += (char)('a' + j);
        while (buf.length() != 50) buf += 'z';
        REP(i, 50) res.EB(buf);
        int now = oneScore * 50;
        while (K < now) {
            res.pop_back();
            now -= oneScore;
        }
        while (now != K) {
            if (K - now <= 50) {
                res.EB(string(K - now, 'z'));
                now += K - now;
            } else {
                int nokori = K - now;
                PII p;
                int bufnum = INF;
                FOR(i, 1, 51) {
                    FOR(j, 1, min(i, 26) + 1) {
                        if (i * j > nokori) break;
                        if (chmin(bufnum, abs(nokori - i * j))) {
                            p = MP(i, j);
                        }
                    }
                }
                buf = string(p.first, 'a');
                REP(j, p.second) buf[j] = 'a' + j;
                res.EB(buf);
                now += p.first * p.second;
            }
        }
        assert(res.size() != 0);
        return res;
    }
};

// CUT begin
#ifdef int
#undef int
#endif
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>

namespace greed_tester {
using namespace std;

ifstream data("BuildingStrings.sample");

enum Color { RED, GREEN };
string color_string(string s, Color c){
#ifdef _MSC_VER
    return s;
#else
    switch(c){
        return s;
    case RED:
        return "\e[31m\e[1m" + s + "\e[0m";
    case GREEN:
        return "\e[32m\e[1m" + s + "\e[0m";
    default:
        return s;
    }
#endif
}

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < (int)ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int K, vector<string> __expected) {
    time_t startClock = clock();
    BuildingStrings *instance = new BuildingStrings();
    vector<string> __result = instance->findAny(K);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << color_string("PASSED!", GREEN) << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "Result   : " << color_string("FAILED!", RED)   << " (" << elapsed << " seconds)" << endl;
        cout << "Expected : " << to_string(__expected) << endl;
        cout << "Received : " << to_string(__result) << endl;
        return false;
    }
}

int run_test() {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int K;
        from_stream(K);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;

        cout << "===== Testcase #" << cases - 1 << " =====" << endl;
        if (do_test(K, __answer)) {
            passed++;
        }
    }
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - 1486647703;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}

}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "BuildingStrings (500 Points)" << endl << endl;
    return greed_tester::run_test();
}
// CUT end
