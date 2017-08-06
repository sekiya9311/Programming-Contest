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

template<typename type = int,
typename ctype = std::less<type>,
type LIM = (std::is_same<ctype, std::less<type>>::value ?
std::numeric_limits<type>::max() :
std::numeric_limits<type>::min())>
class SegTreeRMQ {  //デフォでminimum
private:
    int n;
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
        if (id < L || R <= id) return;
        if (L + 1 == R && id == L) {
            st[k] = el;
            return;
        }
        int h = (L + R) >> 1;
        update(id, el, (k << 1) + 1, L, h);
        update(id, el, (k << 1) + 2, h, R);
        st[k] = std::min(st[(k << 1) + 2], st[(k << 1) + 1], comp);
    }
public:
    SegTreeRMQ() : n(-1) {}
    SegTreeRMQ(int _n, type initval = LIM) : n(_n), st(_n << 2, initval){}
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

const int MAX = 2e5 + 10;
int n;
int p[MAX];
int a[MAX];
priority_queue<PII, VPII, greater<PII>> pq;
SegTreeRMQ<int> seg[2];
int rev[MAX];
int cnt = 0;
VI G[MAX];
PII ans[MAX];

// 既に隣り合っているか、偶数個離れたやつとしかペアになれない

// [l, r)
void dfs(int l, int r) {
    //cerr << l << " " << r << endl;
    const int get1 = seg[l % 2].query(l, r);
    const int get1Idx = rev[get1];
    const int get2 = seg[(l + 1) % 2].query(get1Idx + 1, r);
    const int get2Idx = rev[get2];
    const int now = cnt++;
    ans[now] = MP(get1, get2);
    if (get1Idx - l > 0) {
        G[now].EB(cnt);
        dfs(l, get1Idx);
    }
    if (get2Idx - (get1Idx + 1) > 0) {
        G[now].EB(cnt);
        dfs(get1Idx + 1, get2Idx);
    }
    if (r - (get2Idx + 1) > 0) {
        G[now].EB(cnt);
        dfs(get2Idx + 1, r);
    }

}

int main(void) {
    REP(i, 2) {
        seg[i] = SegTreeRMQ<int>(MAX);
    }
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", p + i);
        seg[i % 2].update(i, p[i]);
        rev[p[i]] = i;
    }
    dfs(0, n);
    int now = 0;
    pq.push(MP(ans[0].first, 0));
    cnt = 0;
    while (!pq.empty()) {
        const PII now = pq.top();   pq.pop();
        //DEBUG(now.second)
        cnt += 2;
        printf("%d %d%c", ans[now.second].first, ans[now.second].second, (cnt == n ? '\n' : ' '));
        FORE(e, G[now.second]) {
            pq.push(MP(ans[e].first, e));
        }
    }
}
