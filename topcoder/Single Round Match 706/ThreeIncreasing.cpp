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

class ThreeIncreasing {
public:
    int a;
    int b;
    int c;
    int minEaten(int _a, int _b, int _c) {
        this->a = _a;
        this->b = _b;
        this->c = _c;
        int ans = 0;
        if (a < b && b < c) return 0;
        if (b <= 1 || c <= 2) return -1;
        if (b >= c) {
            ans += b - c + 1;
            b = c - 1;
        }
        if (a >= b) {
            ans += a - b + 1;
            a = b - 1;
        }

        return ans;
        return -1;
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

ifstream data("ThreeIncreasing.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int a, int b, int c, int __expected) {
    time_t startClock = clock();
    ThreeIncreasing *instance = new ThreeIncreasing();
    int __result = instance->minEaten(a, b, c);
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
        int a;
        from_stream(a);
        int b;
        from_stream(b);
        int c;
        from_stream(c);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;

        cout << "===== Testcase #" << cases - 1 << " =====" << endl;
        if (do_test(a, b, c, __answer)) {
            passed++;
        }
    }
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - 1485014397;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}

}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "ThreeIncreasing (250 Points)" << endl << endl;
    return greed_tester::run_test();
}
// CUT end
