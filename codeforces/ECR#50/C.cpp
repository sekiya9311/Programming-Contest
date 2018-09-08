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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

void foo(string &str) {
    REVERSE(str);
    while (str.size() < 18) {
        str += '0';
    }
    //REVERSE(str);
}

LL dp[20][4][2];// [dig][count (not zero)][less than val]

LL calc(string val) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    REP(i, val.length()) {
        const int D = val[i] - '0';
        REP(j, 4) REP(k, 2) REP(d, (k ? 10 : D + 1)) {
            if ((j + (d != 0)) < 4) {
                dp[i + 1][j + (d != 0)][k || d < D] += dp[i][j][k];
            }
        }
    }
    return dp[val.size()][0][1] + dp[val.size()][1][1] + dp[val.size()][2][1] + dp[val.size()][3][1];
}

int main(void) {
    int T;
    scanf("%d", &T);
    REP(i, T) {
        string l_str, r_str;
        {
            LL l, r;
            scanf("%lld%lld", &l, &r);
            l_str = to_string(l);
            r_str = to_string(r + 1);
        }
        printf("%lld\n", calc(r_str) - calc(l_str));
    }
}
