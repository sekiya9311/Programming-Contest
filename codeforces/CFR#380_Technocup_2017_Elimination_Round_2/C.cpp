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
#include <chrono>
#include <random>

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

LL n, k, s, t;
VL c, v;
VL g;

bool check(LL tank) {
    LL tsum = 0;
    FOR(i, 1, g.size()) {
        LL seg = g[i] - g[i - 1];
        //cout << seg << " " << tsum << endl;
        if (tank < seg) return false;
        if (seg * 2 <= tank) {
            tsum += seg;
        } else {
            tsum += seg * 2 - (tank - seg);
        }
    }
    return tsum <= t;
}

int main(void) {
    scanf("%lld%lld%lld%lld", &n, &k, &s, &t);
    c.resize(n);
    v.resize(n);
    REP(i, n) {
        scanf("%lld%lld", &c[i], &v[i]);
    }
    g.resize(k + 1);
    REP(i, k) {
        scanf("%lld", &g[i]);
    }
    g[k] = s;
    g.EB(0);
    SORT(g);
    if (!check(*max_element(ALL(v)))) {
        cout << -1 << endl;
        return 0;
    }
    int high = 2 * 1e9 + 5, low = 0;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (check(mid)) high = mid;
        else low = mid;
    }
    set<int> se;
    REP(i, n) {
        if (high <= v[i]) se.insert(c[i]);
    }
    cout << *se.begin() << endl;
    return 0;
}
