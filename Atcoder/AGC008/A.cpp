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

LL x, y;

int main(void) {
    cin >> x >> y;
    LL ans = INF;
    if (-x == y) {
        cout << 1 << endl;
        return 0;
    }
    if (x < 0 && y < 0) {
        if (x > y) {
            ans = llabs(llabs(x) - llabs(y)) + 2;
            ans = min(ans, -y - x + 1);
        } else {
            ans = min(ans, y - x);
        }
    } else if (x < 0) {
        if (-x > y) {
            ans = y - x;
            ans = min(ans, -x - y + 1);
        } else {
            ans = y + x + 1;
        }
    } else if (y < 0) {
        if (x < -y) {
            ans = llabs(x + y) + 1;
        } else {
            ans = 1 + y + x;
        }
    } else {
        if (x < y) {
            ans = y - x;
        } else {
            ans = 1 + y + x;
            ans = min(ans, -y + x + 2);
        }
    }
    cout << ans << endl;
}
