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
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

// UnionFind,素集合データ構造,DisjointSet

template<typename weight_type = int>
class union_find {
    static_assert(
        std::is_arithmetic<weight_type>::value,
        "Invalid weight type");
private:
    std::vector<int> uni;
    std::vector<int> edge_count_;
    std::vector<weight_type> weights;
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
    union_find() : uni(0), edge_count_(0), weights(0), size_(-1) {}
    union_find(const int n)
        : uni(n, -1), edge_count_(n), weights(n), size_(n) {
        this->check(n - 1);
    }
    union_find(const std::vector<weight_type> &_weights)
        : uni(_weights.size(), -1), edge_count_(_weights.size()),
        weights(_weights), size_(_weights.size()) {
        this->check((int)_weights.size() - 1);
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
        this->edge_count_[a]++;
        if (a == b) {
            return false;
        }
        this->size_--;
        if (this->uni[a] > this->uni[b]) {
            std::swap(a, b);
        }
        this->uni[a] += this->uni[b];
        this->weights[a] += this->weights[b];
        this->edge_count_[a] += this->edge_count_[b];
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
    const int edge_count(const int a) {
        this->check(a);
        return this->edge_count_[this->find(a)];
    }
    const weight_type weight(const int a) {
        this->check(a);
        return this->weights[this->find(a)];
    }
};

const int MAX = 150010;
int N;
int x[MAX], y[MAX];
union_find<> uf;

VI G[MAX];
int ans[MAX];

pair<int, int> edges[MAX];

int main(void) {
    scanf("%d", &N);
    uf = union_find<>(N);
    REP(i, N - 1) {
        scanf("%d%d", x + i, y + i);
        x[i]--;
        y[i]--;
    }
    REP(i, N) {
        edges[i] = {i, i};
    }
    REP(i, N - 1) {
        const int x_par = uf.find(x[i]);
        const int y_par = uf.find(y[i]);
        uf.unite(x_par, y_par);
        const int new_par = uf.find(x[i]);
        int l1 = edges[x_par].first;
        int l2 = edges[x_par].second;
        int r1 = edges[y_par].first;
        int r2 = edges[y_par].second;
        int l;
        if (G[l1].size() == 2) l = l2;
        else l = l1;
        int r;
        if (G[r1].size() == 2) r = r2;
        else r = r1;
        edges[new_par] = {l == l1 ? l2 : l1, r == r1 ? r2 : r1};
        G[l].EB(r);
        G[r].EB(l);
    }
    int now = -1;
    REP(i, N) if (G[i].size() == 1) {
        now = i;
        break;
    }
    ans[0] = now;
    int prev = -1;
    REP(i, N - 1) {
        FORE(e, G[now]) if (prev != e) {
            prev = now;
            now = e;
            break;
        }
        ans[i + 1] = now;
    }
    REP(i, N) printf("%d%c", ans[i] + 1, (i + 1 == N ? '\n' : ' '));
}
