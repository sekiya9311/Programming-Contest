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

const int MAX = 1e3 + 10;
char strbuf[MAX];
int N;
string S;
int a[26];

LL dp[MAX], dp2[MAX];
LL ans[3];

int main(void) {
    memset(ans, -1, sizeof(ans));
    scanf("%d", &N);
    scanf("%s", strbuf);
    S = strbuf;
    REP(i, 26) scanf("%d", a + i);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    REP(i, MAX) dp2[i] = i;
    REP(i, N) {
        int line = INF;
        FOR(j, i, N) {
            chmin(line, a[S[j] - 'a']);
            if (j - i + 1  <= line) {
                (dp[j + 1] += dp[i]) %= MOD;
                chmax<LL>(ans[1], j - i + 1);
                chmin(dp2[j + 1], dp2[i] + 1);
            }
        }
    }
    ans[0] = dp[N];
    ans[2] = dp2[N];
    REP(i, 3) printf("%lld\n", ans[i]);
}
