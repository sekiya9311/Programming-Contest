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

struct State {
    pair<short, short> now;
    short vecid;
    short tid;
    State(short x, short y, short vid, short id) {
        now = MP(x, y);
        vecid = vid;
        tid = id;
    }
};

const int vx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int vy[] = {1, 0, -1, 1, -1, 1, 0, -1};
//{0:左上，1:左，2:左下，3:上，4:下，5:右上，6:右，7:右下}

const int SIZE = 512;
const int MAX_V = 7;
//const int MAX_LEVEL = 7;
const int MAX_N = 35;
int N;
VI t;
bool board[SIZE][SIZE];
bool used[SIZE][SIZE][MAX_N][MAX_V];

int main(void) {
    scanf("%d", &N);
    t.resize(N);
    REP(i, N) scanf("%d", &t[i]);
    REP(i, SIZE) REP(j, SIZE) {
        board[i][j] = false;
        REP(k, MAX_V) REP(m, MAX_N) used[i][j][m][k] = false;
    }
    queue<State> q;
    q.push(State(SIZE / 2, SIZE / 2, 3, 0));
    auto qpush = [&](State nowState, short v1, short v2) {
        nowState.vecid = v1;
        if (!used[nowState.now.second][nowState.now.first][nowState.tid][nowState.vecid]) q.push(nowState);
        used[nowState.now.second][nowState.now.first][nowState.tid][nowState.vecid] = true;
        nowState.vecid = v2;
        if (!used[nowState.now.second][nowState.now.first][nowState.tid][nowState.vecid]) q.push(nowState);
        used[nowState.now.second][nowState.now.first][nowState.tid][nowState.vecid] = true;
    };
    while (!q.empty()) {
        State now = q.front(); q.pop();
        short x, y, vid;
        tie(x, y) = now.now;
        vid = now.vecid;
        REP(i, t[now.tid]) {
            x += vx[vid];
            y += vy[vid];
            board[y][x] = true;
        }
        //DEBUG(x)DEBUG(y)
        now.now = MP(x, y);
        now.tid++;
        if (now.tid == N) continue;
        if (vid == 0) {
            qpush(now, 1, 3);
        } else if (vid == 1) {
            qpush(now, 0, 2);
        } else if (vid == 2) {
            qpush(now, 1, 4);
        } else if (vid == 3) {
            qpush(now, 0, 5);
        } else if (vid == 4) {
            qpush(now, 2, 7);
        } else if (vid == 5) {
            qpush(now, 3, 6);
        } else if (vid == 6) {
            qpush(now, 5, 7);
        } else if (vid == 7) {
            qpush(now, 4, 6);
        }
    }
    int ans = 0;
    REP(i, SIZE) REP(j, SIZE) ans += board[i][j];
    printf("%d\n", ans);
}
