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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int H, W;
string S[22];
int vis[22][22];

bool inside(int h, int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int calc(PII st) {
    if (S[st.first][st.second] == '#') return -1;
    queue<pair<PII, int>> que;
    memset(vis, -1, sizeof(vis));

    que.emplace(st, 0);
    while (!que.empty()) {
        const auto state = que.front();
        que.pop();

        const int ch = state.first.first;
        const int cw = state.first.second;
        if (vis[ch][cw] != -1) continue;
        vis[ch][cw] = state.second;

        REP(d, 4) {
            const int nh = ch + dx[d];
            const int nw = cw + dy[d];
            if (!inside(nh, nw) || vis[nh][nw] != -1 || S[nh][nw] == '#') continue;
            que.emplace(MP(nh, nw), state.second + 1);
        }
    }

    int res = 0;
    REP(i, H) REP(j, W) {
        chmax(res, vis[i][j]);
    }
    return res;
}

int main(void) {
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }

    int ans = 0;
    REP(i, H) {
        REP(j, W) {
            chmax(ans, calc({i, j}));
        }
    }

    cout << ans << endl;
}
