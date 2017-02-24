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
#include <chrono>

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

const int MAX = 1e5 + 10;
int n, m;
bool room[MAX];
pair<int, int> bt[MAX];

class StronglyConnectedComponentDecomposition {
private:
    std::vector<bool> used;
    std::vector<std::vector<int>> graph, revgraph;
    std::vector<int> comp;
    std::vector<int> sortNode;

    void dfs(int now) {
        this->used[now] = true;
        for (const int e : this->graph[now]) {
            if (!this->used[e]) dfs(e);
        }
        this->sortNode.emplace_back(now);
        return;
    }
    void dfs2(int now, int cnt) {
        this->used[now] = true;
        for (const int e : this->revgraph[now]) {
            if (!this->used[e]) dfs2(e, cnt);
        }
        this->comp[now] = cnt;
        return;
    }
public:
    StronglyConnectedComponentDecomposition() {}
    StronglyConnectedComponentDecomposition(const int n) : used(n, false), graph(n), revgraph(n), comp(n, 0) {}
    void resize(const int n) {
         this->used.resize(n, false);
         this->graph.resize(n);
         this->revgraph.resize(n);
         this->comp.resize(n, 0);
    }
    void addEdge(const int from, const int to) {
        this->graph[from].emplace_back(to);
        this->revgraph[to].emplace_back(from);
        return;
    }
    int solve() {
        std::fill(std::begin(this->used), std::end(this->used), false);
        for (int i = 0; i < (int)this->used.size(); i++) {
            if (!used[i]) dfs(i);
        }
        std::fill(std::begin(this->used), std::end(this->used), false);
        std::reverse(std::begin(this->sortNode), std::end(this->sortNode));
        int res = 0;
        for (const int n : this->sortNode) {
            if (!this->used[n]) dfs2(n, res++);
        }
        return res;
    }
    std::vector<int> getComp() {
        return this->comp;
    }
    bool same(const int a, const int b) {
        return this->comp[a] == this->comp[b];
    }
};

// need SCC Library!!!!
class Two_Sat {
private:
    StronglyConnectedComponentDecomposition scc;
    int sz;
public:
    Two_Sat(const int n) : scc(n * 2), sz(n) {}
    Two_Sat() {}
    void addLogic(const int a, const bool ab, const int b, const int bb) {
        this->scc.addEdge(a + (ab ? 0 : this->sz), b + (bb ? 0 : this->sz));
        this->scc.addEdge(b + (bb ? 0 : this->sz), a + (ab ? 0 : this->sz));
    }
    bool calcSatisfy() {
        this->scc.solve();
        for (int i = 0; i < this->sz; i++) {
            if (this->scc.same(i, i + this->sz)) return false;
        }
        return true;
    }
};

int main(void) {
    fill(bt, bt + MAX, make_pair(-1, -1));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        room[i] = b;
    }
    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            int b; scanf("%d", &b);
            b--;
            if (bt[b].first == -1) bt[b].first = i;
            else bt[b].second = i;
        }
    }
    Two_Sat ts(m);
    for (int i = 0; i < n; i++) {
        if (room[i]) {
            ts.addLogic(bt[i].first, true, bt[i].second, true);
            ts.addLogic(bt[i].first, false, bt[i].second, false);
        } else {
            ts.addLogic(bt[i].first, true, bt[i].second, false);
            ts.addLogic(bt[i].first, false, bt[i].second, true);
        }
    }
    puts(ts.calcSatisfy() ? "YES" : "NO");
}
