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

template<int mod>
class modCalc {
private:
    const int defnum = -1;
public:
    modCalc() { }
    int add(int a, int b) {
        a += b;
        while (a >= mod) a -= mod;
        return a;
    }
    int mul(int a, int b) {
        return (long long)a * b % mod;
    }
    int pow(int a, int p) {
        int res = 1;
        while (p > 0) {
            if (p & 1) res = this->mul(res, a);
            a = this->mul(a, a);
            p >>= 1;
        }
        return res;
    }
    int inverse(int a) {
        return this->pow(a, mod - 2);
    }
};

const int MAX = 55;
modCalc<MOD> mc;
int memoFact[MAX], memoInvFact[MAX];

int fact(int n) {
    if (memoFact[n] != -1) return memoFact[n];
    return memoFact[n] = (n == 0 ? 1 : mc.mul(n, fact(n - 1)));
}

int invFact(int n) {
    if (memoInvFact[n] != -1) return memoInvFact[n];
    return memoInvFact[n] = mc.inverse(fact(n));
}

LL comb(LL n, LL r) {
    //if (n < r) return 0;
    return mc.mul(mc.mul(fact(n), invFact(r)), invFact(n - r));
}

// M個の物をN人で分ける
LL combWithRepetition(LL M, LL N) {
    return comb(M + N - 1, N - 1);
}

//最初に呼んで♪
void init() {
    memset(memoFact, -1, sizeof(memoFact));
    memset(memoInvFact, -1, sizeof(memoInvFact));
    for (int i = 0; i < MAX; i++) {
        fact(i);
        invFact(i);
    }
}

class MappingABC2 {
public:
    vector<int> t;
    int L;

    int countStrings(vector<int> _t) {
        //memset(dp, 0, sizeof(dp));
        init();
        this->t = _t;
        L = t.size();
        set<int> se;
        REP(i, L) se.insert(t[i]);
        if (se.size() < 3) return 0;
        se.clear();
        LL res = 0;

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

ifstream data("MappingABC2.sample");

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

bool do_test(vector<int> t, int __expected) {
    time_t startClock = clock();
    MappingABC2 *instance = new MappingABC2();
    int __result = instance->countStrings(t);
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
        vector<int> t;
        from_stream(t);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;

        cout << "===== Testcase #" << cases - 1 << " =====" << endl;
        if (do_test(t, __answer)) {
            passed++;
        }
    }
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - 1485015960;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}

}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "MappingABC2 (1000 Points)" << endl << endl;
    return greed_tester::run_test();
}
// CUT end
