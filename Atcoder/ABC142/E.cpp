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

const int MAX_N = 13;
const int MAX_M = 1e3 + 10;
int N, M;
int a[MAX_M], b[MAX_M];
int c[MAX_M][MAX_N];
LL dp[MAX_M][1 << MAX_N];

int main(void) {
    cin >> N >> M;
    REP(i, M) {
        cin >> a[i] >> b[i];
        REP(j, b[i]) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    REP(i, MAX_M) FOR(j, 1, (1 << MAX_N)) dp[i][j] = LLINF;

    REP(i, M) {
        int bit = 0;
        REP(j, b[i]) bit |= (1 << c[i][j]);

        REP(j, (1 << N)) {
            if (dp[i][j] == LLINF) continue;
            chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i + 1][j | bit], dp[i][j] + a[i]);
        }
    }

    if (dp[M][(1 << N) - 1] == LLINF) cout << -1 << endl;
    else cout << dp[M][(1 << N) - 1] << endl;
}
