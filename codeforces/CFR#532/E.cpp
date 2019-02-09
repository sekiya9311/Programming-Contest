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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

//トポロジカルソート
// O(|V|+|E|)

class topological_sort {
private:
    std::vector<bool> is;
    std::vector<std::vector<int>> g;
    std::vector<int> t_sort;
    std::vector<int> in_cnt;
    void dfs(int now) {
        if (is[now]) return;
        is[now] = true;
        for (auto &&el : g[now]) {
            dfs(el);
        }
        t_sort.emplace_back(now);
    }
public:
    topological_sort() {}
    topological_sort(const int N) {
        is.resize(N);
        g.resize(N);
        in_cnt.resize(N);
    }
    std::vector<int> dfs_tsort() {
        for (int i = 0; i < (int) g.size(); i++) {
            dfs(i);
        }
        std::reverse(std::begin(t_sort), std::end(t_sort));
        return t_sort;
    }
    void add_edge(int src, int dst) {
        g[src].emplace_back(dst);
        in_cnt[dst]++;
    }
    std::vector<int> bfs_tsort() {
        std::queue<int> q;
        for (int i = 0; i < (int) in_cnt.size(); i++) {
            if (in_cnt[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto now = q.front(); q.pop();
            t_sort.emplace_back(now);
            for (auto &&el : g[now]) {
                if (--in_cnt[el] == 0) {
                    q.push(el);
                }
            }
        }

        if (std::any_of(std::begin(in_cnt),
                        std::end(in_cnt),
                        [](int i) {return i > 0;})) {
            return std::vector<int>();
        }
        return t_sort;
    }
};

const int MAX = 1e5 + 10;
int N, M;
int u[MAX], v[MAX];
LL c[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, M) {
        scanf("%d%d%lld", u + i, v + i, c + i);
        u[i]--;
        v[i]--;
    }
    LL ok = INF + 1, ng = -1;
    while (ok - ng > 1) {
        const auto mid = (ok + ng) / 2;
        topological_sort ts(N);
        REP(i, M) {
            if (c[i] > mid) {
                ts.add_edge(u[i], v[i]);
            }
        }
        if (ts.bfs_tsort().size()) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    topological_sort ts(N);
    REP(i, M) if (c[i] > ok) {
        ts.add_edge(u[i], v[i]);
    }
    auto ts_res = ts.bfs_tsort();
    VI ord(N);
    {
        int tmp = 0;
        FORE(e, ts_res) ord[e] = tmp++;
    }
    VI ans;
    REP(i, M) if (ord[u[i]] > ord[v[i]]) {
        ans.EB(i);
    }
    printf("%lld %d\n", ok, (int)ans.size());
    REP(i, (int)ans.size()) {
        printf("%d%c", ans[i] + 1, " \n"[i + 1 == (int)ans.size()]);
    }
}
