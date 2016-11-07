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
vector<set<int>> graph;
VPII edge; //(min, max)
PII edef = MP(-INF, INF);
bool ng = false;
VI ans;

void dfs(int nowPoint, int backPoint) {
    PII &e = edge[nowPoint];
    FORE(el, graph[nowPoint]) {
        if (el == backPoint) continue;
        dfs(el, nowPoint);
        if (e.first != e.second) {
            e.first = max(e.first, edge[el].first - 1);
            e.second = min(e.second, edge[el].second + 1);
        } else {
            int num = e.first;
            if (!(edge[el].first - 1 <= num && num <= edge[el].second + 1)) {
                ng = true;
            }
        }
        if (e.first > e.second) ng = true;
    }
}

void dfs2(int nowPoint, int backPoint, bool isOdd) {
    PII &e = edge[nowPoint];
    if (e.first == e.second) {
        ans[nowPoint] = e.first;
        if (e.first % 2 != isOdd) {
            ng = true;
        }
    } else {
        if (backPoint != -1) {
            int backnum = ans[backPoint];
            if (backnum + 1 <= e.second && (backnum + 1) %2 == isOdd) {
                ans[nowPoint] = backnum + 1;
            } else if (backnum - 1 >= e.first && (backnum - 1) % 2 == isOdd) {
                ans[nowPoint] = backnum - 1;
            } else {
                ng = true;
            }
        }
    }
    FORE(el, graph[nowPoint]) {
        if (el == backPoint) continue;
        dfs2(el, nowPoint, !isOdd);
    }
}

int main(void) {
    scanf("%d", &N);
    graph.resize(N);
    edge.resize(N, edef);
    ans.resize(N, 0);
    REP(i, N - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    scanf("%d", &K);
    VPII vp(K);
    REP(i, K) {
        int v, p;
        scanf("%d%d", &v, &p);
        v--;
        edge[v] = MP(p, p);
        vp[i] = MP(v, p);
    }
    dfs(vp[0].first, -1);
    dfs2(vp[0].first, -1, vp[0].second % 2);
    if (ng) {
        cout << "No" << endl;
        return 0;
    } else {
        cout << "Yes" << endl;
    }
    FORE(el, ans) {
        printf("%d\n", el);
    }
}
