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

template<typename type = int,
typename ctype = std::less<type>,
type LIM = (std::is_same<ctype, std::less<type>>::value ?
std::numeric_limits<type>::max() :
std::numeric_limits<type>::min())>
class segment_tree_rmq {
private:
    const int n;
    std::vector<type> st;
    ctype comp;
    type query(int l, int r, int k, int L, int R) {
        if (R <= l || r <= L) return LIM;
        if (l <= L && R <= r) return st[k];
        type res = LIM;
        int h = (L + R) >> 1;
        if (l < h) res = std::min(res, query(l, r, (k << 1) + 1, L, h), comp);
        if (h < r) res = std::min(res, query(l, r, (k << 1) + 2, h, R), comp);
        return res;
    }
    void update(int id, type el, int k, int L, int R) {
        if (id < L || R <= id) {
            return;
        }
        if (L + 1 == R && id == L) {
            st[k] = el;
            return;
        }
        const int h = (L + R) >> 1;
        update(id, el, (k << 1) + 1, L, h);
        update(id, el, (k << 1) + 2, h, R);
        st[k] = std::min(st[(k << 1) + 2], st[(k << 1) + 1], comp);
    }
public:
    segment_tree_rmq() : n(-1) {}
    segment_tree_rmq(int _n, type initval = LIM) : n(_n), st(_n << 2, initval){}
    //範囲 [l, r) !!!!!
    type query(int l, int r) {
        assert(this->n != -1 && 0 <= l && r <= this->n && l <= r);
        return query(l, r, 0, 0, n);
    }
    void update(int id, type el) {
        assert(this->n != -1 && id < this->n);
        update(id, el, 0, 0, n);
    }
};

const int MAX = 1e5 + 10;
int N, M;
map<int, VT<pair<int, LL>>> edges;
segment_tree_rmq<LL> seg(MAX, LLINF);

int main(void) {
    cin >> N >> M;
    REP(i, M) {
        int l, r, c;
        cin >> l >> r >> c;
        l--; r--;
        edges[r].EB(l, c);
    }

    seg.update(0, 0);
    FORE(e, edges) {
        const int right = e.first;
        LL nxt = LLINF;
        FORE(edge, e.second) {
            chmin(nxt, seg.query(edge.first, right) + edge.second);
        }
        seg.update(right, nxt);
    }

    const auto ans = seg.query(N - 1, N);
    cout << (ans == LLINF ? -1 : ans) << endl;
}
