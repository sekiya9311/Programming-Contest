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

const int MID = 60 * 12;
const int DAY = MID * 2;
const int MAX = MID + 10;
int AC, AJ;
PII CD[MAX], JK[MAX];
int C[MAX], D[MAX];
int J[MAX], K[MAX];
int dp[MAX][MAX][2][2];
bool tim[2][DAY];
// (cam time, jam time, now, start)

void solve(int testNum) {
    REP(i, MAX) REP(j, MAX) REP(k, 2) REP(l, 2) dp[i][j][k][l] = INF;
    memset(tim, false, sizeof(tim));
    scanf("%d%d", &AC, &AJ);
    REP(i, AC) {
        scanf("%d%d", C + i, D + i);
        CD[i] = MP(C[i], D[i]);
    }
    REP(i, AJ) {
        scanf("%d%d", J + i, K + i);
        JK[i] = MP(J[i], K[i]);
    }
    sort(CD, CD + AC);
    sort(JK, JK + AJ);
    REP(i, AC) {
        tie(C[i], D[i]) = CD[i];
        FOR(j, C[i], D[i]) {
            tim[0][j] = true;
        }
    }
    REP(i, AJ) {
        tie(J[i], K[i]) = JK[i];
        FOR(j, J[i], K[i]) {
            tim[1][j] = true;
        }
    }
    if (!tim[0][0]) {
        dp[0][0][0][0] = 0;
    }
    if (!tim[1][0]) {
        dp[0][0][1][1] = 0;
    }

    REP(l, 2) {
        REP(i, MID + 1) REP(j, MID + 1) {
            REP(k, 2) {
                if (!tim[k][i + j]) {
                    chmin(dp[i + (k == 0)][j + (k != 0)][0][l], dp[i][j][k][l] + (k != 0));
                    chmin(dp[i + (k == 0)][j + (k != 0)][1][l], dp[i][j][k][l] + (k == 0));
                }
            }
        }
    }

    int ans = INF;
    REP(i, 2) {
        chmin(ans, dp[MID][MID][i][i]);
    }

    cout << "Case #" << testNum << ": " << ans << endl;
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
