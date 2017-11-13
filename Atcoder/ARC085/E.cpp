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

class Dinic {
private:
    struct edge {
        int to, rev;    //行き先，逆辺(のid)
        long long cap;  //容量
        edge(int _to, int _rev, long long _cap) {
            this->to = _to;
            this->rev = _rev;
            this->cap = _cap;
        }
    };
    std::vector<std::vector<edge>> G;
    std::vector<int> dist;   //sからの距離
    std::vector<int> iter;   //どこまで調べ終わったか
    //sからの最短経路探索(distに格納)
    void bfs(int s) {
        std::fill(std::begin(dist), std::end(dist), -1);
        std::queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            const int now = q.front(); q.pop();
            for (const edge& el : G[now]) {
                if (el.cap > 0 && dist[el.to] < 0) {
                    dist[el.to] = dist[now] + 1;
                    q.push(el.to);
                }
            }
        }
    }
    long long dfs(int v, int t, long long f) {
        if (v == t) return f;
        for (int &id = iter[v]; id < G[v].size(); id++) {
            edge &el = G[v][id];
            if (el.cap <= 0 || dist[v] >= dist[el.to]) {
                continue;
            }
            const long long d = dfs(el.to, t, std::min(f, el.cap));
            if (d > 0) {
                el.cap -= d;
                G[el.to][el.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
public:
    const static long long inf = 1e18;
    Dinic() {}
    Dinic(const int n) {
        G.resize(n);
        dist.resize(n, -1);
        iter.resize(n, 0);
    }
    void add_edge(int from, int to, long long cap) {
        G[from].emplace_back(edge(to, G[to].size(), cap));
        G[to].emplace_back(edge(from, G[from].size() - 1, 0));
    }
    long long max_flow(int s, int t) {
        if (s == t) return 0;
        long long flow = 0;
        while (true) {
            bfs(s);
            if (dist[t] < 0) return flow;
            std::fill(std::begin(iter), std::end(iter), 0);
            long long f = dfs(s, t, inf);
            if (f > 0) flow += f;
        }
    }
};

const int MAX = 111;
const int s = 0, t = MAX - 1;
int N;
LL a[MAX];
Dinic d(MAX);

int main(void) {
    cin >> N;
    REP(i, N) {
        cin >> a[i];
    }
    LL sum = 0;
    REP(i, N) {
        int p = i + 1;
        if (a[i] > 0) {
            sum += a[i];
            // この辺を切った場合，i + 1番目の宝石は壊す
            //  := (a[i] > 0) の宝石が得られなくなるので sum から a[i] 減少
            d.add_edge(p, t, a[i]);
        } else {
            // この辺を切った場合，i + 1番目の宝石は壊さない
            //  := (a[i] <= 0) の宝石を取るので sum から a[i] 減少
            d.add_edge(s, p, -a[i]);
        }
        // 倍数と無限大でつなぐ（切れない）
        while (p <= N) {
            d.add_edge(i + 1, p, d.inf);
            p += i + 1;
        }
    }
    // sum := 取りうる可能性のある最高スコア

    cout << sum - d.max_flow(s, t) << endl;
}
