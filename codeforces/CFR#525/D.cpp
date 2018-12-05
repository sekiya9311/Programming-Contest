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
#include <functional>

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

int ask(int c, int d) {
    cout << "? " << c << " " << d << endl;
    int in;
    cin >> in;
    return in;
}

void final_answer(int a, int b) {
    cout << "! " << a << " " << b << endl;
    exit(0);
}

const int MAX_BIT = 30;

// aとかaaとか間違えやすいのでやめましょうね～

int main(void) {
    int a = 0, b = 0;
    int mm = ask(0, 0);

    RREP(i, MAX_BIT) {
        const int aa = ask(a | (1 << i), b);
        const int bb = ask(a, b | (1 << i));
        //    : aa , bb
        // 0 0: 1 0, 0 1
        // 0 1: 1 1, 0 0
        // 1 0: 0 0, 1 1
        // 1 1: 0 1, 1 0
        if (aa == 1 && bb == -1) {

        } else if (aa == -1 && bb == 1) {
            a |= (1 << i);
            b |= (1 << i);
        } else {
            if (mm == 1) {
                a |= (1 << i);
            } else {
                b |= (1 << i);
            }
            mm = aa;
        }
    }

    final_answer(a, b);
}
