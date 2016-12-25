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

int N, K;
VL a;
VL asump, asumm, asum;

int main(void) {
    scanf("%d%d", &N, &K);
    a.resize(N);
    for_each(ALL(a), [](LL &e){scanf("%lld", &e);});
    asump.resize(N + 1, 0);
    asumm.resize(N + 1, 0);
    asum.resize(N + 1, 0);
    FOR(i, 1, N + 1) {
        asum[i] = asum[i - 1] + a[i - 1];
        asump[i] = asump[i - 1] + (a[i - 1] >= 0 ? a[i - 1] : 0);
        asumm[i] = asumm[i - 1] + (a[i - 1] < 0 ? a[i - 1] : 0);
    }
    LL ans = 0;
    REP(i, N - K + 1) {
        LL buf = asum[i + K] - asum[i];
        buf = max(buf, 0ll);
        buf = buf + asump[N] - asump[i + K] + asump[i];
        ans = max(ans, buf);
    }
    cout << ans << endl;
}
