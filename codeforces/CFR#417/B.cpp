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

int N, M;
string room[20];
int dp[110][20];

int main(void) {
    cin >> N >> M;
    bool ex = false;
    REP(i, N) {
        cin >> room[i];
        REP(j, M + 2) ex |= (room[i][j] == '1');
    }
    if (!ex) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, 110) REP(j, 20) dp[i][j] = INF;
    dp[0][N] = 0;
    int last1 = INF, last2 = INF;
    RREP(i, N) {
        bool f = false;
        int last = -1;
        int last2 = INF;
        REP(j, M + 2) {
            if (room[i][j] == '1') {
                last = j;
            }
        }
        bool p = (i + 1 != N);
        if (last != -1) {
            chmin(dp[0][i], dp[0][i + 1] + last + last + p);
            chmin(dp[M + 1][i], dp[0][i + 1] + last + (M + 1 - last) + p);
            chmin(last2, dp[0][i + 1] + last + p);
        } else {
            dp[0][i] = dp[0][i + 1] + p;
            dp[M + 1][i] = dp[M + 1][i + 1] + p;
            continue;
        }
        last = INF;
        RREP(j, M + 2) {
            if (room[i][j] == '1') {
                last = j;
            }
        }
        if (last != INF) {
            chmin(dp[0][i], dp[M + 1][i + 1] + p + (M + 1 - last) + last);
            chmin(dp[M + 1][i], dp[M + 1][i + 1] + p + (M + 1 - last) + (M + 1 - last));
            chmin(last2, dp[M + 1][i + 1] + p + (M + 1 - last));
        }
        if (last2 != INF) last1 = last2;
        
        // REP(i, N) REP(j, M + 2) {
        //     cout << dp[j][i] << " ";
        //     if (j == M + 1) cout << endl;
        // }cout<<endl;
    }
    cout << last1 << endl;
}
