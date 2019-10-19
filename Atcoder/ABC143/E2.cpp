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

const int MAX_N = 333;
const int MAX_M = MAX_N * MAX_N;

struct state {
    int cur_point;
    int gas;
    int supply_cnt;
    state() {}
    state(int a, int b, int c)
        : cur_point(a), gas(b), supply_cnt(c) {}

    bool operator>(const state &other) const {
        if (supply_cnt == other.supply_cnt) return gas < other.gas;
        return supply_cnt > other.supply_cnt;
    }
    bool operator>=(const state &other) const {
        if (supply_cnt == other.supply_cnt) return gas <= other.gas;
        return supply_cnt >= other.supply_cnt;
    }

    bool operator<(const state &other) const {
        return !(*this >= other);
    }
    bool operator<=(const state &other) const {
        return !(*this > other);
    }
};

int N, M, L;
VPII G[MAX_N];
state dist[MAX_N][MAX_N];

int Q;
int s[MAX_M], t[MAX_M];

void calc(int s) {
    priority_queue<state, VT<state>, greater<state>> pq;
    dist[s][s] = state(s, L, 0);

    pq.emplace(s, L, 0);
    while (!pq.empty()) {
        const auto cur = pq.top();
        pq.pop();

        if (cur > dist[s][cur.cur_point]) continue;

        FORE(nxt, G[cur.cur_point]) {
            const auto nxt_p = nxt.first;
            const auto nxt_dist = nxt.second;

            const int nxt_cnt = cur.supply_cnt + (cur.gas - nxt_dist < 0);
            const auto nxt_gas = (nxt_cnt == cur.supply_cnt ? cur.gas : L) - nxt_dist;

            state nxt_state(nxt_p, nxt_gas, nxt_cnt);
            if (nxt_state >= dist[s][nxt_p]) {
                continue;
            }
            dist[s][nxt_p] = nxt_state;

            pq.emplace(nxt_state);
        }
    }
}

int main(void) {
    cin >> N >> M >> L;
    REP(i, N) REP(j, N) dist[i][j] = state(INF, INF, INF);
    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;

        if (c > L) continue;

        G[a].EB(b, c);
        G[b].EB(a, c);
    }

    REP(i, N) calc(i);

    cin >> Q;
    REP(i, Q) {
        cin >> s[i] >> t[i];
        s[i]--;t[i]--;
    }

    REP(i, Q) {
        if (dist[s[i]][t[i]].supply_cnt < INF) cout << dist[s[i]][t[i]].supply_cnt << endl;
        else cout << -1 << endl;
    }
}
