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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 1111;
const long double PI = acos(-1);
int N, K;
tuple<LL, LL, LL> RH[MAX];
LL dp[MAX][MAX];
LL R[MAX], H[MAX], ln[MAX];
// (現半径idx, 現枚数)

void solve(int testNum) {
    scanf("%d%d", &N, &K);
    REP(i, N) {
        int R, H;
        scanf("%d%d", &R, &H);
        RH[i] = make_tuple(R, H, (1ll * R * 2 * H));
    }
    sort(RH, RH + N);
    reverse(RH, RH + N);
    long long ans = 0;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    REP(i, N) {
        tie(R[i], H[i], ln[i]) = RH[i];
        dp[i][1] = ln[i] + R[i] * R[i];
    }
    REP(i, N) {
        FOR(j, i + 1, N) {
            REP(k, K) {
                if (dp[i][k] != -1) {
                    chmax(dp[j][k + 1], dp[i][k] + ln[j]);
                }
            }
        }
    }
    REP(i, MAX) REP(j, MAX) chmax(ans, dp[i][j]);
    cout << "Case #" << testNum << ": " << fixed << setprecision(10) << PI * ans << endl;
}

int main(void) {
    if (freopen("out.txt", "w", stdout) == NULL) {
        cerr << "file open failed" << endl;
        exit(1);
    }
	int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
