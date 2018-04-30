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

const int MAX = 1e5 + 10;
LL n,m;
int cl,ce,v;
LL l[MAX], e[MAX];
int q;
LL x1[MAX], y1[MAX], x2[MAX], y2[MAX];
set<LL> kaidan, elev;

int main(void) {
    scanf("%lld%lld", &n, &m);
    scanf("%d%d%d", &cl, &ce, &v);
    REP(i, cl) scanf("%lld", l + i), l[i]--;
    REP(i, cl) kaidan.emplace(l[i]);
    REP(i, ce) scanf("%lld", e + i), e[i]--;
    REP(i, ce) elev.emplace(e[i]);
    scanf("%d", &q);
    REP(i, q) {
        scanf("%lld%lld%lld%lld", x1 + i, y1 + i, x2 + i, y2 + i);
        x1[i]--;y1[i]--;
        x2[i]--;y2[i]--;
    }
    REP(i, q) {
        LL ans = LLINF;
        if (x1[i] == x2[i]) {
            ans = llabs(y2[i] - y1[i]);
        } else {
            {
                // kaidan
                auto it = kaidan.lower_bound(y1[i]);
                if (it != begin(kaidan)) {
                    auto pit = prev(it);
                    chmin(ans, llabs(x2[i] - x1[i]) + llabs(y1[i] - *pit) + llabs(y2[i] - *pit));
                }
                if (it != end(kaidan) && next(it) != end(kaidan)) {
                    auto nit = next(it);
                    chmin(ans, llabs(x2[i] - x1[i]) + llabs(y1[i] - *nit) + llabs(y2[i] - *nit));
                }
                if (it != end(kaidan)) {
                    chmin(ans, llabs(x2[i] - x1[i]) + llabs(y1[i] - *it) + llabs(y2[i] - *it));
                }
            }
            {
                // elevetor
                auto it = elev.lower_bound(y1[i]);
                if (it != begin(elev)) {
                    auto pit = prev(it);
                    chmin(ans, llabs(x2[i] - x1[i]) / v + (llabs(x2[i] - x1[i]) % v != 0) + llabs(y1[i] - *pit) + llabs(y2[i] - *pit));
                }
                if (it != end(elev) && next(it) != end(elev)) {
                    auto nit = next(it);
                    chmin(ans, llabs(x2[i] - x1[i]) / v + (llabs(x2[i] - x1[i]) % v != 0) + llabs(y1[i] - *nit) + llabs(y2[i] - *nit));
                }
                if (it != end(elev)) {
                    chmin(ans, llabs(x2[i] - x1[i]) / v + (llabs(x2[i] - x1[i]) % v != 0) + llabs(y1[i] - *it) + llabs(y2[i] - *it));
                }
            }
        }
        printf("%lld\n", ans);
    }
}
