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

const int MAX = 1111;
string N;
int K;
LL dp[MAX][MAX][2];
LL memo[MAX];

LL dfs(LL cnt) {
    if (memo[cnt] > -1) {
        return memo[cnt];
    }
    return memo[cnt] = dfs(__builtin_popcountll(cnt)) + 1;
}

int main(void) {
    memset(memo, -1, sizeof(memo));
    memo[1] = 0;
    cin >> N >> K;
    const int L = N.length();
    if (N == "1") {
        if (K) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    } else if (K == 0) {
        cout << 1 << endl;
        return 0;
    }
    dp[0][0][0] = 1;
    REP(i, L) {
        const int D = N[i] - '0';
        REP(cnt, i + 1) {
            REP(j, 2) {
                REP(d, (j ? 2 : D + 1)) {
                    (dp[i + 1][cnt + d][j || d < D] += dp[i][cnt][j]) %= MOD;
                }
            }
        }
    }
    LL ans = 0;
    FOR(i, 1, L + 1) {
        //DEBUG(dfs(i))
        if (dfs(i) + 1 == K) {
            (ans += dp[L][i][0] + dp[L][i][1]) %= MOD;
        }
    }
    if (K == 1) ans--;
    (ans += MOD) %= MOD;
    cout << ans << endl;
}
