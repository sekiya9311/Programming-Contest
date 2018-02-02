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

class UnionFind {
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
    UnionFind() : size_(-1) {}
    UnionFind(const int n)
        : uni(n, -1), size_(n) {
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
        if (a == b) {
            return false;
        }
        this->size_--;
        if (this->uni[a] > this->uni[b]) {
            std::swap(a, b);
        }
        this->uni[a] += this->uni[b];
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

const int MAX = 200010;
int n, m;
unordered_set<int> G[MAX];
PII in_idx[MAX];
int ans[MAX];
UnionFind uf(MAX);
VI put;
bool vis[MAX];

// 入力でつながってるやつ　　→　連結か非連結かわからない
// 入力でつながってないやつ　→　絶対連結!!

int main(void) {
    {   // input
        scanf("%d%d", &n, &m);
        REP(i, m) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;b--;
            G[a].emplace(b);
            G[b].emplace(a);
        }
    }

    {   // calculate
        REP(i, n) {
            in_idx[i] = {(int)G[i].size(), i};
        }
        sort(in_idx, in_idx + n);
        REP(idx, n) {
            int i = in_idx[idx].second;
            if (vis[i]) continue;
            REP(j, n) {
                if (G[i].count(j) == 0 && !uf.same(i, j)) {
                    uf.unite(i, j);
                    vis[j] = true;
                }
            }
        }
    }

    {   // print answer
        memset(ans, -1, sizeof(ans));
        REP(i, n) {
            if (ans[uf.find(i)] == -1) {
                ans[uf.find(i)] = uf.size(i);
            }
        }
        REP(i, n) {
            if (ans[i] != -1) {
                put.EB(ans[i]);
            }
        }
        SORT(put);
        printf("%d\n", (int)put.size());
        REP(i, put.size()) {
            printf("%d%c", put[i], (i + 1 == (int)put.size()) ? '\n' : ' ');
        }
    }
}
