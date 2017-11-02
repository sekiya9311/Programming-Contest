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

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

LL n, m, k;
LL x, s;
VL a, b, c, d;

int main(void) {
    scanf("%lld%lld%lld", &n, &m, &k);
    scanf("%lld%lld", &x, &s);
    a.resize(m + 1);
    b.resize(m + 1);
    c.resize(k + 1);
    d.resize(k + 1);
    REP(i, m) scanf("%lld", &a[i + 1]);
    REP(i, m) scanf("%lld", &b[i + 1]);
    REP(i, k) scanf("%lld", &c[i + 1]);
    REP(i, k) scanf("%lld", &d[i + 1]);
    a[0] = x; b[0] = 0;
    c[0] = 0; d[0] = 0;
    LL ans = x * n;
    REP(i, m + 1) {
        //1つ目のタイプi番目使用
        int high = k + 1, low = 0;
        LL canUseCost = s - b[i];
        if (canUseCost < 0) continue;
        int useTwoTypeIdx = 0;
        useTwoTypeIdx = distance(begin(d), upper_bound(ALL(d), canUseCost)) - 1;
        LL buf = a[i] * (n - c[useTwoTypeIdx]);
        ans = min(ans, buf);
    }
    printf("%lld\n", ans);
}
