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
const long double EPS = 1e-9;

int n;
bool inside(int h, int w) {
    return 0 <= h && h < n && 0 <= w && w < n;
}

int bfs(int nh, int nw) {
    VT<VT<bool>> vis(n, VT<bool>(n, false));
    VT<VT<bool>> master(n, VT<bool>(n, false));
    int dw[] = {-nw, -nw, -nh, -nh, nh, nh, nw, nw};
    int dh[] = {-nh, nh, -nw, nw, -nw, nw, -nh, nh};
    vis[0][0] = true;
    REP(cnt, 100) {
        VT<VT<bool>> _vis(n, VT<bool>(n, false));
        VT<VT<bool>> _master = master;
        REP(i, n) REP(j, n) {
            if (vis[i][j]) {
                REP(dir, 8) {
                    const int h = i + dh[dir];
                    const int w = j + dw[dir];
                    if (inside(h, w)) {
                        _vis[h][w] = true;
                    }
                }
            }
            _master[i][j] = (_vis[i][j] || _master[i][j]);
        }
        if (_master == master) return -1;
        vis = _vis;
        if (vis[n - 1][n - 1]) return cnt + 1;
    }
    return -1;
}

int main(void) {
    cin >> n;
    VVI ans(n - 1, VI(n - 1));
    FOR(i, 1, n) FOR(j, i, n) {
        ans[i - 1][j - 1] = ans[j - 1][i - 1] = bfs(i, j);
    }
    REP(i, n - 1) {
        REP(j, n - 1) {
            printf("%d%c", ans[i][j], (j + 2 == n ? '\n' : ' '));
        }
    }
}
