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
// UnionFind,素集合データ構造,DisjointSet

class union_find {
private:
    std::vector<int> uni;
    int size_;
    const void check(const int n) const {
        if (this->group_size() < 0) {
            assert(false);
        }
        if (!(0 <= n && n < this->all_size())) {
            assert(false);
        }
    }
public:
    std::vector<int> cnt;
    std::vector<LL> cost;
    union_find() : size_(-1) {}
    union_find(const int n)
        : uni(n, -1), size_(n), cnt(n), cost(n) {
        this->check(n - 1);
    }
    bool same(const int a, const int b) {
        this->check(a);
        this->check(b);
        return this->find(a) == this->find(b);
    }
    int find(const int a) {
        this->check(a);
        return this->uni[a] < 0 ?
                a :
            this->uni[a] = this->find(this->uni[a]);
    }
    bool unite(int a, int b) {
        a = this->find(a);
        b = this->find(b);
        cnt[a]++;
        if (a == b) {
            return false;
        }
        this->size_--;
        if (this->uni[a] > this->uni[b]) {
            std::swap(a, b);
        }
        this->uni[a] += this->uni[b];
        cnt[a] += cnt[b];
        cost[a] += cost[b];
        this->uni[b] = a;
        return true;
    }
    const int group_size() const {
        return this->size_;
    }
    const int all_size() const {
        return this->uni.size();
    }
    const int size(const int a) {
        this->check(a);
        return -this->uni[this->find(a)];
    }
};

const int MAX = 1e5 + 10;
int N, M;
LL X[MAX];
VT<pair<int, LL>> G[MAX];
VT<pair<LL, PII>> edges;

int main(void) {
    cin >> N >> M;
    REP(i, N) {
        cin >> X[i];
    }
    REP(i, M) {
        int a, b;
        LL y;
        cin >> a >> b >> y;
        a--;b--;
        G[a].EB(b, y);
        G[b].EB(a, y);
        edges.EB(MP(y, MP(a, b)));
    }
    SORT(edges);

    int live = 0;
    union_find uf(N);
    REP(i, N) uf.cost[i] = X[i];
    FORE(e, edges) {
        uf.unite(e.second.first, e.second.second);
        const int par = uf.find(e.second.first);
        if (uf.cost[par] >= e.first) {
            live += uf.cnt[par];
            uf.cnt[par] = 0;
        }
    }
    cout << M - live << endl;
}
