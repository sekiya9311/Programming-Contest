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

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e18;
#define int LL

/** NOT AC **/

LL n, m, L, s, t;
vector<VPII> graph;
LL dijkstra() {
    LL res = LLINF;
    vector <LL> minCost(n, LLINF);
    priority_queue<PLL,vector<PLL>,greater<PLL> > q;
    q.push(MP(0, s));
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        LL pos = now.second, cost = now.first;
        if (pos == t) {
            res = min(res, cost);
        }
        if (minCost[pos] == LLINF) minCost[pos] = cost;
        else continue;
        FORE(el, graph[pos]) {
            q.push(MP(el.second + cost, el.first));
        }
    }
    return res;
}

signed main(void) {
    cin >> n >> m >> L >> s >>t;
    graph = vector<VPII>(n);
    vector <tuple<int, int, int>> ans(m);
    REP(i, m) {
        int a, b, cost;
        scanf("%lld%lld%lld", &a, &b, &cost);
        //cout << a << " " << b << " " << cost << endl;
        ans[i] = make_tuple(a, b, cost);
        graph[a].emplace_back(b, cost);
        graph[b].emplace_back(a, cost);
        //cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
    }
    LL ret = dijkstra();
    if (ret > L) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    LL lc = L - ret;
    LL cnt = 0;
    REP(i, m) {
        if (get<2>(ans[i]) == 0) {
            cnt++;
        }
    }
    REP(i, m) {
        if (get<2>(ans[i]) == 0) {
            if (--cnt) {
                ans[i] = make_tuple(get<0>(ans[i]), get<1>(ans[i]), 1);
                lc--;
            } else {
                ans[i] = make_tuple(get<0>(ans[i]), get<1>(ans[i]), lc);
            }
        }
        printf("%lld %lld %lld\n", get<0>(ans[i]), get<1>(ans[i]), get<2>(ans[i]));
    }
}
