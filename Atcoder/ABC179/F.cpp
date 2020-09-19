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

// 区間変更，区間最小値
template<typename T = int,
        typename ctype = std::less<T>,
        T LIM = (std::is_same<ctype, std::less<T>>::value ?
                 std::numeric_limits<T>::max() : std::numeric_limits<T>::min())>
class range_update_query_minmax {
private:
    std::vector<T> data, lazy;
    std::vector<bool> valid, lazyFlag;
    ctype comp;
    const T initVal;
    int sz;
    void push(int k) {
        if (this->lazyFlag[k]) {
            this->valid[k] = true;
            this->data[k] = this->lazy[k];
            if ((k << 1) + 2 < (sz << 1) - 1) {
                this->lazy[(k << 1) + 1] = this->lazy[(k << 1) + 2] = this->lazy[k];
                this->lazyFlag[(k << 1) + 1] = this->lazyFlag[(k << 1) + 2] = true;
            }
            this->lazyFlag[k] = false;
        }
    }
    void update(int l, int r, int L, int R, int k, T val) {
        this->push(k);
        if (L <= l && r <= R) {
            this->lazy[k] = val;
            this->lazyFlag[k] = true;
            this->push(k);
        } else if (r < L || R < l) {
            return;
        } else if (r - l > 1) {
            const int mid = (l + r) >> 1;
            this->update(l, mid, L, R, (k << 1) + 1, val);
            this->update(mid, r, L, R, (k << 1) + 2, val);
            data[k] = std::min(data[(k << 1) + 1], data[(k << 1) + 2], comp);
        }
    }
    T query(int l, int r, int L, int R, int k) {
        this->push(k);
        if (L <= l && r <= R) {
            return this->data[k];
        } else if (r <= L || R <= l) {
            return this->initVal;
        } else {
            const int mid = (l + r) >> 1;
            T left = this->query(l, mid, L, R, (k << 1) + 1);
            T right = this->query(mid, r, L, R, (k << 1) + 2);
            return std::min(left, right, comp);
        }
    }
public:
    range_update_query_minmax(const int n, T initval = LIM) : initVal(initval) {
        this->sz = 1;
        while (this->sz < n) {
            this->sz <<= 1;
        }
        this->data.resize((this->sz << 1) - 1, this->initVal);
        this->lazy.resize((this->sz << 1) - 1);
        this->valid.resize((this->sz << 1) - 1, false);
        this->lazyFlag.resize((this->sz << 1) - 1, false);
    }
    void update(int l, int r, T val) {
        this->update(0, sz, l, r, 0, val);
    }
    T query(int l, int r) {
        return this->query(0, sz, l, r, 0);
    }
};

struct query_type {
    int type;
    int x;
};

const int MAX = 2e5 + 10;
LL N, Q;
query_type query[MAX];
range_update_query_minmax<int> h(MAX), w(MAX);

void solve() {
    cin >> N >> Q;
    REP(i, Q) {
        cin >> query[i].type >> query[i].x;
        query[i].x--;
    }
    h.update(0, MAX - 1, N - 1);
    w.update(0, MAX - 1, N - 1);

    LL white = 0;
    REP(i, Q) {
        if (query[i].type == 1) {
            const auto v = h.query(query[i].x, query[i].x + 1);
            white += v - 1;
            if (w.query(0, 1) >= query[i].x) {
                w.update(0, v, query[i].x);
            }
        } else {
            const auto v = w.query(query[i].x, query[i].x + 1);
            white += v - 1;
            if (h.query(0, 1) >= query[i].x) {
                h.update(0, v, query[i].x);
            }
        }
    }

    cout << (N - 2) * (N - 2) - white << endl;
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
