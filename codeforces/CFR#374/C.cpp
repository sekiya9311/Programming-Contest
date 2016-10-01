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
#define RREP(i, a) for (int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for (int (i) = (a) - 1; (i) >= (b); (i)--)
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
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define EB emplace_back
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;

/* NOT AC  */

int n, m, T;
VI graph[5010];
int cost[5010][5010];
set <int> muri;

list <int> dfs(int nowPoint, int nowCost) {
    list <int> res;
    if (nowPoint == n - 1) {
        res.emplace_front(nowPoint);
        return res;
    }
    FORE(el, graph[nowPoint]) {
        if (FIND(muri, el)) continue;
        int reCost = nowCost + cost[nowPoint][el];
        if (reCost > T) continue;
        auto buf = dfs(el, reCost);
        if (buf.size() && buf.back() != n - 1) {
            muri.insert(el);
            continue;
        } else if (buf.size() == 0) {
            continue;
        }
        if (res.size() < buf.size()) {
            res = buf;
        }
    }
    if (res.size() && res.back() != n - 1) {
        muri.insert(nowPoint);
        res.clear();
    } else if (res.size() && res.back() == n - 1) {
        res.emplace_front(nowPoint);
    } else if (res.size() == 0) {
        muri.insert(nowPoint);
    }
    return res;
}

int main(void) {
    scanf("%d%d%d", &n, &m, &T);
    REP(i, m) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;b--;
        graph[a].EB(b);
        cost[a][b] = c;
    }
    auto ans = dfs(0, 0);
    cout << ans.size() << endl;
    FORE(el, ans) {
        printf("%d ", el + 1);
    }
    printf("\n");
}
