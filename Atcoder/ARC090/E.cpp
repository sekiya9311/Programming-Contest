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

// pair<min cost, route count>
template<typename T = int>
pair<vector<T>, vector<long long>> dijkstra(vector<pair<int, T>> G[], int size, int st, const T inf) {
    priority_queue<pair<T, pair<int, int>>, vector<pair<T, pair<int, int>>>, greater<pair<T, pair<int, int>>>> pq;
    pq.push({0, {st, -1}});
    vector<T> dist(size, inf);
    vector<long long> cnt(size, 0);
    while (!pq.empty()) {
        const auto now = pq.top();
        pq.pop();
        if (dist[now.second.first] < now.first) {
            continue;
        } else if (dist[now.second.first] >= now.first) {
            assert(dist[now.second.first] == now.first || dist[now.second.first] == inf);
            (cnt[now.second.first] += now.second.second == -1 ? 1 : cnt[now.second.second]) %= MOD;
            if (dist[now.second.first] == now.first) {
                continue;
            }
        }
        dist[now.second.first] = now.first;
        for (auto nxt : G[now.second.first]) {
            const T nextCost = dist[now.second.first] + nxt.second;
            pq.push(make_pair(nextCost, make_pair(nxt.first, now.second.first)));
        }
    }
    return {dist, cnt};
}

const int MAX = 1e5 + 10;
int N, M;
int S, T;
LL min_cost;
VL min_s, min_t;
VL s_route_cnt, t_route_cnt;
vector<pair<int, LL>> G[MAX];
map<PII, LL> route_cnt[2];
LL node_cnt[MAX][2];
LL min_cost_cnt[2];

// ぶつかる可能性があるのは一箇所(二所以上あったら最短路にならないはず)
// && ちょうど半分のところ(どっちかに時間が偏ってたらそれも最短路にはならないはず)

int main(void) {
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    S--;T--;
    REP(i, M) {
        int u, v;
        LL d;
        scanf("%d%d%lld", &u, &v, &d);
        u--;v--;
        G[u].EB(MP(v, d));
        G[v].EB(MP(u, d));
    }
    tie(min_s, s_route_cnt) = dijkstra<LL>(G, N, S, LLINF);
    tie(min_t, t_route_cnt) = dijkstra<LL>(G, N, T, LLINF);
    assert(min_s[T] == min_t[S]);
    min_cost = min_s[T];
    {
        {// S - T count
            const int idx = 0;
            queue<pair<int, LL>> q;
            VT<bool> visited(N, false);
            q.emplace(MP(T, min_cost));
            while (!q.empty()) {
                int now;
                LL now_cost;
                tie(now, now_cost) = q.front();
                q.pop();
                if (visited[now]) {
                    continue;
                }
                visited[now] = true;
                if (now_cost == 0) {
                    (min_cost_cnt[idx] += t_route_cnt[now]) %= MOD;
                }
                if (now_cost * 2 == min_cost) {
                    (node_cnt[now][idx] += t_route_cnt[now]) %= MOD;
                }
                FORE(e, G[now]) {
                    if (now_cost - e.second == min_s[e.first]) {
                        q.emplace(MP(e.first, now_cost - e.second));
                        if (now_cost * 2 > min_cost && (now_cost - e.second) * 2 < min_cost) {
                            (route_cnt[idx][MP(min(e.first, now), max(e.first, now))] += t_route_cnt[now]) %= MOD;
                        }
                    }
                }
            }
        }
        {// T - S count
            const int idx = 1;
            queue<pair<int, LL>> q;
            VT<bool> visited(N, false);
            q.emplace(MP(S, min_cost));
            while (!q.empty()) {
                int now;
                LL now_cost;
                tie(now, now_cost) = q.front();
                q.pop();
                if (visited[now]) {
                    continue;
                }
                visited[now] = true;
                if (now_cost == 0) {
                    (min_cost_cnt[idx] += s_route_cnt[now]) %= MOD;
                }
                if (now_cost * 2 == min_cost) {
                    (node_cnt[now][idx] += s_route_cnt[now]) %= MOD;
                }
                FORE(e, G[now]) {
                    if (now_cost - e.second == min_t[e.first]) {
                        q.emplace(MP(e.first, now_cost - e.second));
                        if (now_cost * 2 > min_cost && (now_cost - e.second) * 2 < min_cost) {
                            (route_cnt[idx][MP(min(e.first, now), max(e.first, now))] += s_route_cnt[now]) %= MOD;
                        }
                    }
                }
            }
        }
        LL ans = 1ll * min_cost_cnt[0] * min_cost_cnt[1] % MOD;
        REP(i, N) {
            ans = ans - ((((node_cnt[i][0] % MOD) * (node_cnt[i][0] % MOD) % MOD)) % MOD * ((node_cnt[i][1] % MOD) * (node_cnt[i][1] % MOD) % MOD) % MOD) + MOD;
            ans %= MOD;
        }
        FORE(e, route_cnt[0]) {
            if (route_cnt[1].count(e.first)) {
                ans = ans - (((e.second % MOD) * (e.second % MOD) % MOD) * ((route_cnt[1][e.first] % MOD) * (route_cnt[1][e.first] % MOD) % MOD) % MOD) + MOD;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
}
