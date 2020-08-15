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

const int MAX = 3333;
LL mp[MAX][MAX];
LL dp[MAX][MAX][4];
int R, C, K;

void solve() {
    cin >> R >> C >> K;
    LL sum = 0;
    REP(i, K) {
        int r, c, v;
        cin >> r >> c >> v;
        mp[r - 1][c - 1] = v;
        sum += v;
    }
    DEBUG(sum)

    REP(i, MAX) REP(j, MAX) REP(k, 4) dp[i][j][k] = -LLINF;
    dp[0][0][0] = 0;

    REP(_, 4) REP(i, R) REP(j, C) REP(k, 4) {
        if (dp[i][j][k] == -LLINF) continue;

        if (i < R) chmax(dp[i + 1][j][0], dp[i][j][k]);
        if (j < C) chmax(dp[i][j + 1][k], dp[i][j][k]);

        if (mp[i][j] > 0 && k < 3) {
            if (i < R) chmax(dp[i + 1][j][0], dp[i][j][k] + mp[i][j]);
            if (j < C) chmax(dp[i][j + 1][k + 1], dp[i][j][k] + mp[i][j]);
        }
    }

    LL ans = 0;
    REP(i, 4) {
        chmax(ans, dp[R][C - 1][i]);
        chmax(ans, dp[R - 1][C][i]);
    }

    cout << ans << endl;
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
