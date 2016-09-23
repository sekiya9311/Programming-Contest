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

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a)-1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a)-1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cout<< C <<endl;
#define VI vector <int>
#define VII vector <VI>
#define VL vector <LL>
#define VLL vector <VL>
#define VD vector <double>
#define VDD vector <VD>
#define PII pair <int, int>
#define PDD pair <double, double>
#define PLL pair <LL, LL>
#define VPII vector <PII>
#define ALL(a) ((a).begin(), (a).end())
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, e) (s.find(e) != s.end())
#define EB emplace_back

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e14;
#define int LL

LL n, m, L, s, t;
vector<VPII> graph_min, graph_max, graph_m;

LL dijkstra(vector<VPII> graph) {
    LL res = LLINF;
    vector <LL> minCost(n, LLINF);
    minCost[s] = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL>> q;
    q.push(MP(0, s));
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        LL pos = now.second, cost = now.first;
        if (pos == t) {
            res = min(res, cost);
        }
        FORE(el, graph[pos]) {
            LL nxtCost = el.second + cost;
            LL nxtPnt = el.first;
            if (minCost[nxtPnt] <= nxtCost) continue;
            minCost[nxtPnt] = nxtCost;
            q.push(MP(nxtCost, nxtPnt));
        }
    }
    return res;
}

signed main(void) {
    cin >> n >> m >> L >> s >>t;
    graph_min = vector<VPII>(n);
    graph_max = vector<VPII>(n);
    vector <tuple <int, int, int>> ans(m);
    VPII zero;  //zero_edge
    REP(i, m) {
        int a, b, cost;
        scanf("%lld%lld%lld", &a, &b, &cost);
        ans[i] = make_tuple(a, b, cost);
        graph_min[a].EB(MP(b, ((cost == 0)?1:cost)));
        graph_min[b].EB(MP(a, ((cost == 0)?1:cost)));
        graph_max[a].EB(MP(b, ((cost == 0)?LLINF:cost)));
        graph_max[b].EB(MP(a, ((cost == 0)?LLINF:cost)));
        if (cost == 0) zero.EB(a, b);
    }
    LL ret_min = dijkstra(graph_min);
    LL ret_max = dijkstra(graph_max);
    if (!(ret_min <= L && L <= ret_max)) {
        cout << "NO" << endl;
        return 0;
    }
    graph_m = graph_max;
    PII ansp = MP(0, 0);
    LL ansc = 0;
    set<PII> se;
    if (L < ret_max) FORE(p, zero) {
        FORE(el, graph_m[p.first]) {
            if (el.first == p.second) {
                el.second = 1;
                break;
            }
        }
        FORE(el, graph_m[p.second]) {
            if (el.first == p.first) {
                el.second = 1;
                break;
            }
        }
        LL ret = dijkstra(graph_m);
        if (ret <= L) {
            ansp = p;
            ansc = 1 + L - ret;
            break;
        }
        se.insert(p);
    }
    cout << "YES" << endl;
    FORE(el, ans) {
        if (get<2>(el) == 0) {
            if (ansp == MP(get<0>(el), get<1>(el))) el = make_tuple(get<0>(el), get<1>(el), ansc);
            else if (FIND(se, MP(get<0>(el), get<1>(el)))) el = make_tuple(get<0>(el), get<1>(el), 1);
            else el = make_tuple(get<0>(el), get<1>(el), LLINF);
        }
        printf("%lld %lld %lld\n", get<0>(el), get<1>(el), get<2>(el));
    }
}
