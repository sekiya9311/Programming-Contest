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
LL N, L, R;
LL a[MAX], p[MAX];
LL ans[MAX]; //b[i]
set<LL> cset;

LL check(LL A, LL B, LL C) {
    LL high = INF, low = -INF;
    while (high - low > 1) {
        LL mid = (high + low) / 2;
        if (A + mid - B > C) high = mid;
        else low = mid;
    }
    return high;
}

int main(void) {
    scanf("%lld%lld%lld", &N, &L, &R);
    REP(i, N) scanf("%lld", a + i);
    REP(i, N) scanf("%lld", p + i);
    REP(i, N) if (p[i] > R) {
        puts("-1");
        return 0;
    }
    priority_queue<PLL, VT<PLL>, greater<PLL>> pq;
    REP(i, N) pq.push(MP(p[i], i));
    LL mi = -INF, ma = INF;// about C
    LL pre = L, prec = -LLINF;
    while (!pq.empty()) {
        LL i, num;
        tie(num, i) = pq.top(); pq.pop();
        ans[i] = pre;
        if (ans[i] - a[i] <= prec) {
            ans[i] += check(ans[i], a[i], prec);
        }
        prec = ans[i] - a[i];
    }
    REP(i, N) {
        if (!(L <= ans[i] && ans[i] <= R)) {
            puts("-1");
            return 0;
        }
    }
    REP(i, N) {
        printf("%lld%c", ans[i], (i + 1 == N ? '\n' : ' '));
    }
}
