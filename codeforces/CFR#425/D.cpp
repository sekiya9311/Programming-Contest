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

class LowestCommonAncester {
private:
    using costType = int;
    std::vector<std::vector<std::pair<int, costType>>> graph;
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;
    std::vector<costType> cost;
    static const int MAX_LOG = 20;
    bool valid = false;
    int LCA(int u, int v) {
        if (this->depth[u] > this->depth[v]) {
            swap(u, v);
        }
        // uとvの深さを合わせる
        for (int k = 0; k < this->MAX_LOG; ++k) {
            if (((this->depth[v] - this->depth[u]) >> k) & 1) {
                v = this->parent[k][v];
            }
        }
        if (u == v) return u;
        // 二分探索でぶつかる所までもっていく
        for (int k = this->MAX_LOG - 1; k >= 0; --k) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    void dfs(const int now, const int par, const int nowDepth, const costType nowCost) {
        depth[now] = nowDepth;
        parent[0][now] = par;
        cost[now] = nowCost;
        for (auto &&e : graph[now]) {
            if (e.first != par) {
                dfs(e.first, now, nowDepth + 1, nowCost + e.second);
            }
        }
    }
public:
    LowestCommonAncester() {}
    LowestCommonAncester(const std::vector<std::vector<pair<int, int>>> &graph_)
    : graph(graph_), parent(this->MAX_LOG, std::vector<int>(graph_.size(), 0)),
    depth(graph_.size(), 0), cost(graph_.size(), 0) {this->valid = false;}
    LowestCommonAncester(const std::vector<pair<int, int>> *graph_, int size_)
    : parent(this->MAX_LOG, std::vector<int>(size_, 0)), depth(size_, 0), cost(size_, 0) {
        graph.resize(size_);
        for (int i = 0; i < size_; ++i) {
            this->graph[i] = graph_[i];
        }
        this->valid = false;
    }
    LowestCommonAncester(const int n)
    : graph(n), parent(this->MAX_LOG, std::vector<int>(n, 0)), depth(n, 0), cost(n, 0) {this->valid = false;}

    void addEdge(const int a, const int b, const costType c) {
        this->graph[a].emplace_back(make_pair(b, c));
        this->graph[b].emplace_back(make_pair(a, c));
        this->valid = false;
    }
    void calcInit() {
        dfs(0, -1, 0, 0);
        for (int k = 0; k + 1 < this->MAX_LOG; ++k) {
            for (int v = 0; v < graph.size(); ++v) {
                if (this-> parent[k][v] == -1) {
                    this->parent[k + 1][v] = -1;
                } else {
                    this->parent[k + 1][v] = this->parent[k][this->parent[k][v]];
                }
            }
        }
        this->valid = true;
    }
    int get(const int a, const int b) {
        // うまく書けよ♪
        const int lca = this->LCA(a, b);
        return depth[a] + depth[b] - 2 * depth[lca];
    }
    int getLca(const int a, const int b) {
        return this->LCA(a, b);
    }
};

const int MAX = 1e5 + 10;
int n, q;
int p[MAX];
int a[MAX], b[MAX], c[MAX];
LowestCommonAncester lca;

int calc(int s, int t, int f) {
    VI v{lca.get(s, t), lca.get(t, f), lca.get(f, s)};
    return (v[0] + v[1] - v[2]) / 2 + 1;
}

int main(void) {
    scanf("%d%d", &n, &q);
    lca = LowestCommonAncester(n);
    REP(i, n - 1) {
        scanf("%d", p + i);
        lca.addEdge(i + 1, --p[i], 1);
    }    
    lca.calcInit();
    REP(i, q) {
        scanf("%d%d%d", a + i, b + i, c + i);
        --a[i];--b[i];--c[i];
    }
    REP(i, q) {
        VI v{a[i], b[i], c[i]};
        SORT(v);
        int ans = 0;
        do {
            chmax(ans, calc(v[0], v[1], v[2]));
        } while (next_permutation(ALL(v)));
        printf("%d\n", ans);
    }
}
