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

template<typename value_type>
class SegmentTree {
private:
    const int n;
    std::vector<value_type> st;
    std::function<value_type(value_type, value_type)> func;
    value_type initVal;
    value_type query(int l, int r, int k, int L, int R) {
        if (R <= l || r <= L) return initVal;
        if (l <= L && R <= r) return st[k];
        value_type res = initVal;
        int h = (L + R) >> 1;
        if (l < h) res = func(res, query(l, r, (k << 1) + 1, L, h));
        if (h < r) res = func(res, query(l, r, (k << 1) + 2, h, R));
        return res;
    }
    void update(int id, value_type el, int k, int L, int R) {
        if (id < L || R <= id) return;
        if (L + 1 == R && id == L) {
            st[k] = el;
            return;
        }
        int h = (L + R) >> 1;
        update(id, el, (k << 1) + 1, L, h);
        update(id, el, (k << 1) + 2, h, R);
        st[k] = func(st[(k << 1) + 1], st[(k << 1) + 2]);
    }
public:
    SegmentTree() : n(-1) {}
    SegmentTree(int _n,
                value_type _initVal,
                std::function<value_type(value_type, value_type)> _func)
        : n(_n), initVal(_initVal), st(_n << 2, _initVal), func(_func){}
    //範囲 [l, r) !!!!!
    value_type query(int l, int r) {
        assert(this->n != -1 && 0 <= l && r <= this->n && l <= r);
        return query(l, r, 0, 0, n);
    }
    void update(int id, value_type el) {
        assert(this->n != -1 && id < this->n);
        update(id, el, 0, 0, n);
    }
};

struct node {
    int v;
    LL cost;
    node(int _v, LL _c) {
        v = _v;
        cost = _c;
    }
};

VL dijkstra(const VT<VT<node>>& G, int S) {
    priority_queue<pair<LL, int>, VT<pair<LL, int>>, greater<pair<LL, int>>> pq;
    VL ret(G.size(), LLINF);
    pq.emplace(0, S);
    ret[S] = 0;
    while (!pq.empty()) {
        LL cost;
        int now;
        tie(cost, now) = pq.top();
        pq.pop();
        if (ret[now] < cost) {
            continue;
        }
        FORE(e, G[now]) {
            const LL next_cost = cost + e.cost;
            if (ret[e.v] > next_cost) {
                ret[e.v] = next_cost;
                pq.emplace(next_cost, e.v);
            }
        }
    }
    return ret;
}

int main(void) {
    int N, M, S, T;
    scanf("%d%d%d%d", &N, &M, &S, &T);
    S--;T--;
    VT<VT<node>> Ggo(N), Gback(N);
    REP(i, M) {
        int u, v;
        LL a, b;
        scanf("%d%d%lld%lld", &u, &v, &a, &b);
        u--;v--;
        Ggo[u].EB(v, a);
        Ggo[v].EB(u, a);
        Gback[u].EB(v, b);
        Gback[v].EB(u, b);
    }
    auto go = dijkstra(Ggo, S);
    auto back = dijkstra(Gback, T);
    SegmentTree<LL> seg(N, LLINF, std::min);
    REP(i, N) {
        seg.update(i, go[i] + back[i]);
    }
    REP(i, N) {
        printf("%lld\n", (LL)1e15 - seg.query(i, N));
    }
}
