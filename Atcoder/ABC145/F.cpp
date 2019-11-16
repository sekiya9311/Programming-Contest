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
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 333;
int N, K;
LL H[MAX];
LL dp[MAX][MAX][MAX];

int main(void) {
    cin >> N >> K;
    REP(i, N) {
        cin >> H[i + 1];
    }

    if (N == K) {
        cout << 0 << endl;
        return 0;
    }
    if (N == K + 1) {
        cout << *min_element(H, H + N) << endl;
        return 0;
    }

    H[0] = 0;
    N++;

    REP(i, MAX) REP(j, MAX) REP(k, MAX) {
        dp[i][j][k] = LLINF;
    }
    dp[1][0][0] = 0;
    FOR(i, 1, N) {
        REP(j, K + 1) {
            REP(k, i + 1) {
                if (dp[i][j][k] == LLINF) continue;

                chmin(dp[i + 1][j][i], dp[i][j][k] + max(H[i] - H[k], 0LL));
                chmin(dp[i + 1][j + 1][k], dp[i][j][k]);
            }
        }
    }

    LL ans = LLINF;
    REP(j, K + 1) REP(k, N) {
        chmin(ans, dp[N][j][k]);
    }
    cout << ans << endl;
}
