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

const int MAX = 1e5 + 10;
int N, M;
LL a[MAX];
VI G[MAX];
UnionFind uf;
priority_queue<LL, VL, greater<LL>> pq[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    uf = UnionFind(N);
    REP(i, N) {
        scanf("%lld", a + i);
    }
    REP(i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].EB(y);
        G[y].EB(x);
        uf.unite(x, y);
    }
    {
        if ((uf.group_size() - 1) * 2 > N) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (uf.group_size() == 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    REP(i, N) {
        pq[uf.find(i)].push(a[i]);
    }
    VL ans;
    priority_queue<LL, VL, greater<LL>> all;
    REP(i, N) {
        if (!pq[i].empty()) {
            ans.EB(pq[i].top());
            pq[uf.find(i)].pop();
            while (!pq[i].empty()) {
                all.emplace(pq[i].top());
                pq[i].pop();
            }
        }
    }
    while (ans.size() < (uf.group_size() - 1) * 2) {
        if (all.empty()) {
            cout << "Impossible" << endl;
            return 0;
        }
        ans.EB(all.top());
        all.pop();
    }
    cout << accumulate(ALL(ans), 0LL) << endl;
}
