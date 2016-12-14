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

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const string ng = "Impossible";
int N;
VI a;
VVI graph;
VL score;
LL ans = -LLINF;

LL dfs(int now, int prev) {
    LL res = a[now];
    FORE(e, graph[now]) if (e != prev) {
        res += dfs(e, now);
    }
    return score[now] = res;
}

void dfs2(int now, int prev) {
    LL &nowScore = score[now];
    FORE(e, graph[now]) if (e != prev) {
        dfs2(e, now);
        nowScore = max(nowScore, score[e]);
    }
}

void dfs3(int now, int prev) {
    VL vec;
    FORE(e, graph[now]) if (e != prev) {
        dfs3(e, now);
        vec.EB(score[e]);
    }
    RSORT(vec);
    if (vec.size() >= 2) {
        ans = max(ans, vec[0] + vec[1]);
    }
}

int main(void) {
    scanf("%d", &N);
    a.resize(N);
    REP(i, N) scanf("%d", &a[i]);
    graph.resize(N);
    REP(i, N - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        graph[u].EB(v);
        graph[v].EB(u);
    }
    if (N <= 2) {
        cout << ng << endl;
        return 0;
    }
    score.resize(N);
    dfs(0, -1);
    dfs2(0, -1);
    dfs3(0, -1);
    if (ans == -LLINF) {
        cout << ng << endl;
    } else {
        cout << ans << endl;
    }
}
