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

void solve() {
    int N;
    cin >> N;
    VL X(N), Y(N);
    VI Z(N);
    REP(i, N) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
    const int MAX = 1e5 + 10;
    const auto sum = accumulate(ALL(Z), 0);
    // dp[i][議席数] = 最小の奪う数
    VVL dp(N + 1, VL(MAX, LLINF));
    dp[0][0] = 0;
    REP(i, N) {
        const auto half = (X[i] + Y[i] + 1) / 2;
        const auto cur = max(0LL, half- X[i]);
        REP(j, MAX) {
            if (dp[i][j] == LLINF) {
                continue;
            }
            chmin(dp[i + 1][j], dp[i][j]);
            if (j + Z[i] >= MAX) {
                continue;
            }
            chmin(dp[i + 1][j + Z[i]], dp[i][j] + cur);
        }
    }

    LL ans = LLINF;
    FOR(i, (sum + 1) / 2, MAX) {
        chmin(ans, dp[N][i]);
    }
    cout << ans << "\n";
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
