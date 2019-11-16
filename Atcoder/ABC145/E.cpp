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
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 3333;
int N, T;
PII foods[MAX];
int dp[MAX][MAX];

int main(void) {
    cin >> N >> T;
    REP(i, N) {
        cin >> foods[i].first >> foods[i].second;
    }
    sort(foods, foods + N, [](const PII &l, const PII &r) {
        if (l.first == r.first) return l.second > r.second;
        else return l.first < r.first;
    });

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    REP(i, N) {
        //DEBUG(foods[i].second)
        REP(j, T + 1) if (dp[i][j] != -1) {
            chmax(dp[i + 1][j], dp[i][j]);
            if (j < T) {
                chmax(dp[i + 1][min(j + foods[i].first, T)], dp[i][j] + foods[i].second);
            }
        }
    }

    int ans = 0;
    REP(i, T + 1) {
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
}
