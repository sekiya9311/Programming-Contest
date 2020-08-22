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

const int dx4[] = {0, 0, -1, 1};
const int dy4[] = {1, -1, 0, 0};

const int MAX = 1e3 + 10;
int H, W;
int Ch, Dh;
int Cw, Dw;
string S[MAX];
int mi[MAX][MAX];

bool inside(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

void solve() {
    cin >> H >> W;
    cin >> Ch >> Cw;
    Ch--; Cw--;
    cin >> Dh >> Dw;
    Dh--; Dw--;
    REP(i, H) cin >> S[i];

    REP(i, MAX) REP(j, MAX) mi[i][j] = INF;
    mi[Ch][Cw] = 0;
    priority_queue<pair<int, PII>, VT<pair<int, PII>>, greater<>> que;
    que.emplace(0, MP(Ch, Cw));

    while (!que.empty()) {
        const auto el = que.top();
        const auto cur_h = el.second.first;
        const auto cur_w = el.second.second;
        const auto cost = el.first;
        que.pop();
        if (mi[cur_h][cur_w] < cost) {
            continue;
        }

        REP(d, 4) {
            const auto nh = cur_h + dx4[d];
            const auto nw = cur_w + dy4[d];
            if (!inside(nh, nw)) continue;
            if (S[nh][nw] == '#') continue;
            if (mi[nh][nw] <= cost) continue;
            mi[nh][nw] = cost;
            que.emplace(cost, MP(nh, nw));
        }

        FOR(x, -2, 3) FOR(y, -2, 3) {
                if (x == 0 && y == 0) continue;
                const auto nh = cur_h + x;
                const auto nw = cur_w + y;
                if (!inside(nh, nw)) continue;
                if (S[nh][nw] == '#') continue;
                if (mi[nh][nw] <= cost + 1) continue;;
                mi[nh][nw] = cost + 1;
                que.emplace(cost + 1, MP(nh, nw));
        }
    }

    if (mi[Dh][Dw] == INF) cout << -1 << endl;
    else cout << mi[Dh][Dw] << endl;
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
