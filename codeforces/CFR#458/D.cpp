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
#include <random>
#include <chrono>

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

template<typename type = int>
class SegTreeGCD {
private:
    const int n;
    std::vector<type> st;
    const type LIM = 0;
    inline type query(int l, int r, int k, int L, int R) {
        if (R <= l || r <= L) return LIM;
        if (l <= L && R <= r) return st[k];
        type res = LIM;
        type h = (L + R) >> 1;
        if (l < h) {
            res = query(l, r, (k << 1) + 1, L, h);
        }
        if (h < r) {
            type rRet = query(l, r, (k << 1) + 2, h, R);
            if (rRet != LIM) {
                if (res == LIM) {
                    res = rRet;
                } else {
                    res = __gcd(res, rRet);
                }
            }
        }
        return res;
    }
    inline bool valid_query(int l, int r, int k, int L, int R, int cond) {
        if (R <= l || r <= L) return true;
        if (l <= L && R <= r) return st[k] % cond == 0;
        bool res = true;
        int h = (L + R) >> 1;
        return valid_query(l, r, (k << 1) + 2, h, R, cond) && valid_query(l, r, (k << 1) + 1, L, h, cond);
    }
    inline void update(int id, type el, int k, int L, int R) {
        if (id < L || R <= id) return;
        if (L + 1 == R && id == L) {
            st[k] = el;
            return;
        }
        int h = (L + R) >> 1;
        update(id, el, (k << 1) + 1, L, h);
        update(id, el, (k << 1) + 2, h, R);
        st[k] = __gcd(st[(k << 1) + 2], st[(k << 1) + 1]);
    }
public:
    SegTreeGCD() : n(-1) {}
    SegTreeGCD(int _n) : n(_n), st(_n << 2, LIM){}
    //範囲 [l, r) !!!!!
    inline type query(int l, int r) {
        return this->query(l, r, 0, 0, n);
    }
    // gcd が cond の倍数になるか
    inline type valid_query(int l, int r, int cond) {
        return this->valid_query(l, r, 0, 0, n, cond);
    }
    inline void update(int id, type el) {
        update(id, el, 0, 0, n);
    }
};

const int MAX_A = 5e5 + 10;
int n;
int q;
SegTreeGCD<int> seg(MAX_A);

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        int a;
        scanf("%d", &a);
        seg.update(i, a);
    }
    scanf("%d", &q);
    while (q--) {
        int l, r, x = -1;
        {
            int qVal;
            scanf("%d", &qVal);
            if (qVal == 1) {
                scanf("%d%d%d", &l, &r, &x);
            } else {
                scanf("%d%d", &l, &r);
            }
        }
        if (x != -1) {
            if (l == r || seg.valid_query(l - 1, r, x)) {
                puts("YES");
            } else {
                int low = l, high = r + 1;
                while (high - low > 1) {
                    const int mid = (high + low) >> 1;
                    if (seg.valid_query(l - 1, mid - 1, x)) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                puts(seg.valid_query(low, r, x) ? "YES" : "NO");
            }
        } else {
            seg.update(l - 1, r);
        }
    }
}
