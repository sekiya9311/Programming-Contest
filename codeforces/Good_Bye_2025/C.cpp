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
#define GREATER(T) T, VT<T>, greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 2e5 + 10;
LL a[MAX];
LL dp[MAX][3][2]; // dp[idx][p/n/exclude][excluded]

void solve2() {
    int N;
    cin >> N;
    REP(i, N) cin >> a[i];

    REP(j, 2) dp[0][j][0] = 0;
    REP(i, N) {
        REP(j, 3) {
            if (i == 0 && j == 1) continue;
            if (i + 1 == N && j == 0) continue;
            if (j == 2) {
                dp[i + 1][j][1] = max(dp[i + 1][j][1], max(dp[i][0][0], dp[i][1][0]));
            } else {
                const auto add = j == 0 ? a[i] : -a[i];
                REP(k, 2) {
                    if (k == 1 && j == 0) continue;
                    if (i == 1 && k == 1 && j == 0) continue;
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], max(dp[i][0][k] + add, dp[i][1][k] + add));
                    if (dp[i][2][k] != -LLINF) {
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][2][k] + add);
                    }
                }
            }

            // DEBUG(i)
            // DEBUG(a[i])
            // DEBUG((j == 0 ? "P" : j == 1 ? "N" : "E"))
            // DEBUG(dp[i + 1][j][0]);
            // DEBUG(dp[i + 1][j][1]);
            // cerr<<endl;
        }
        // cerr<<endl;cerr<<endl;cerr<<endl;
    }
    cout << max(dp[N][0][1], max(dp[N][1][1], dp[N][2][1])) << "\n";
    REP(i, N + 1) REP(j, 3) REP(k, 2) dp[i][j][k] = -LLINF;
}

void solve() {
    REP(i, MAX) REP(j, 3) REP(k, 2) dp[i][j][k] = -LLINF;
    int N;
    cin >> N;
    REP(i, N) {
        solve2();
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
