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
#define GREATER(T) T, VT<T>, greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

// UnionFind,素集合データ構造,DisjointSet

template<typename weight_type = int>
class union_find {
private:
    const std::function<void(int, int)> noop = [](int aa, int bb){};

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
        return unite(a, b, noop);
    }
    bool unite(int a, int b, const std::function<void(int, int)> &f) {
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
        f(a, b);
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


const int dx4[] = {0, 0, -1, 1};
const int dy4[] = {1, -1, 0, 0};
const string DIR = "><^v";
const char EMPTY = '.';
const char BLOCK = '#';
const char START = 'S';
const char GOAL = 'G';
const char DAME = '!';

void solve() {
    int H, W;
    cin >> H >> W;
    VT<string> G(H);
    REP(i, H) {
        cin >> G[i];
    }

    REP(i, H) {
        bool dame = false;
        REP(j, W) {
            if (G[i][j] == '>') {
                dame = true;
                continue;
            }
            if (dame && (G[i][j] == EMPTY || G[i][j] == DAME)) {
                G[i][j] = DAME;
                continue;
            }
            dame = false;
        }
    }
    REP(i, H) {
        bool dame = false;
        RREP(j, W) {
            if (G[i][j] == '<') {
                dame = true;
                continue;
            }
            if (dame && (G[i][j] == EMPTY || G[i][j] == DAME)) {
                G[i][j] = DAME;
                continue;
            }
            dame = false;
        }
    }
    REP(j, W) {
        bool dame = false;
        REP(i, H) {
            if (G[i][j] == 'v') {
                dame = true;
                continue;
            }
            if (dame && (G[i][j] == EMPTY || G[i][j] == DAME)) {
                G[i][j] = DAME;
                continue;
            }
            dame = false;
        }
    }
    REP(j, W) {
        bool dame = false;
        RREP(i, H) {
            if (G[i][j] == '^') {
                dame = true;
                continue;
            }
            if (dame && (G[i][j] == EMPTY || G[i][j] == DAME)) {
                G[i][j] = DAME;
                continue;
            }
            dame = false;
        }
    }

    VVI memo(H, VI(W, INF));
    VT<VT<bool>> vis(H, VT<bool>(W, false));
    queue<PII> que;
    REP(i, H) REP(j, W) {
        if(G[i][j] == START) {
            memo[i][j] = 0;
            que.emplace(i, j);
        }
    }
    while (!que.empty()) {
        const auto cur = que.front();
        que.pop();
        if (vis[cur.first][cur.second]) {
            continue;
        }
        vis[cur.first][cur.second] = true;
        REP(i, 4) {
            const auto nxt_x = cur.first + dx4[i];
            const auto nxt_y = cur.second + dy4[i];
            if (nxt_x < 0 || nxt_x >= H || nxt_y < 0 || nxt_y >= W) {
                continue;
            }
            if (memo[nxt_x][nxt_y] != INF) {
                continue;
            }
            if (G[nxt_x][nxt_y] != EMPTY && G[nxt_x][nxt_y] != GOAL) {
                continue;
            }
            memo[nxt_x][nxt_y] = memo[cur.first][cur.second] + 1;
            que.emplace(nxt_x, nxt_y);
        }
    }
    REP(i, H) REP(j, W) {
        if (G[i][j] == GOAL) {
            cout << (memo[i][j] == INF ? -1 : memo[i][j]) << "\n";
            return;
        }
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
