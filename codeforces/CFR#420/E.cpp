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

// REP(i, 15) {
//     REP(j, 15) {
//         // (a, i) から (b, j) まで行く方法
//     }
// }

// dp[0][0] = 1;
// REP(i, 1e4) {
//     REP(j, 15) {
//         if (j == 0) {
//             add(dp[i + 1][j], dp[i][j]);
//             add(dp[i + 1][j + 1], dp[i][j]);
//         } else if (j == 14) {
//             add(dp[i + 1][j], dp[i][j]);
//             add(dp[i + 1][j - 1], dp[i][j]);
//         } else {
//             add(dp[i + 1][j], dp[i][j]);
//             add(dp[i + 1][j + 1], dp[i][j]);
//             add(dp[i + 1][j - 1], dp[i][j]);
//         }
//     }
// }
// cout << dp[1e4][0] << endl;

inline void add(int &a, int b) {
    a = ((long long)a + b) % MOD;
}

const int MAX = 111;
LL N, K;
LL a[MAX], b[MAX], c[MAX];
int dp[(int)1e4 + 10][22];

int main(void) {
    // scanf("%lld%lld", &N, &K);
    // RPE(i, N) {
    //     scanf("%lld%lld%lld", a + i, b + i, c + i);
    // }
    dp[0][0] = 1;
    REP(i, 10) {
        REP(j, 15) {
            if (j == 0) {
                add(dp[i + 1][j], dp[i][j]);
                add(dp[i + 1][j + 1], dp[i][j]);
            } else if (j == 14) {
                add(dp[i + 1][j], dp[i][j]);
                add(dp[i + 1][j - 1], dp[i][j]);
            } else {
                add(dp[i + 1][j], dp[i][j]);
                add(dp[i + 1][j + 1], dp[i][j]);
                add(dp[i + 1][j - 1], dp[i][j]);
            }
        }
    }
    REP(j, 15) {
        REP(i, 10 + 1) cout << dp[i][j] << " ";
        cout << endl;
    }
}
