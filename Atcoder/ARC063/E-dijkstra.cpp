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
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N, K;
vector<VPII> graph; //(cost, next)
VI cost;
bool ng = false;

VI dijkstra() {
    VI res(N + 1, INF);
    priority_queue<PII, VPII, greater<PII>> pq;
    pq.push({0, N});
    res[N] = 0;
    while (!pq.empty()) {
        int dist, now;
        tie(dist, now) = pq.top();pq.pop();
        if (res[now] < dist) continue;
        FORE(e, graph[now]) {
            int nd, nxt;
            tie(nd, nxt) = e;
            if (res[nxt] <= dist + nd) continue;
            res[nxt] = dist + nd;
            pq.push({res[nxt], nxt});
        }
    }
    return res;
}

int main(void) {
    scanf("%d", &N);
    graph.resize(N + 1);
    cost.resize(N);
    REP(i, N - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        graph[a].EB(MP(1, b));
        graph[b].EB(MP(1, a));
    }
    scanf("%d", &K);
    VI vv(K);
    REP(i, K) {
        int v, p;
        scanf("%d%d", &v, &p);
        v--;
        cost[v] = p;
        vv[i] = v;
        graph[N].EB(MP(p, v));
    }
    VI res = dijkstra();
    FORE(e, vv) {
        if (res[e] != cost[e]) {
            ng = true;
        }
    }
    REP(i, N) FORE(e, graph[i]) {
        if (abs(res[i] - res[e.second]) != 1) {
            //cerr << i + 1 << " " << e.second + 1 << endl;
            ng = true;
        }
    }
    if (ng) {
        cout << "No" << endl;
        return 0;
    } else {
        cout << "Yes" << endl;
    }
    REP(i, N) {
        printf("%d\n", res[i]);
    }
}
