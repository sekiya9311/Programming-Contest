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

const int MAX = 5050;
int N, K;
int a[MAX];
bool dp[MAX][MAX];
int abuf[MAX];

bool check(const int limit) {
    if (limit < 0) {
        return false;
    }
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    REP(i, N) {
        REP(j, K) {
            if (abuf[i] + j <= K) {
                dp[i + 1][abuf[i] + j] |= dp[i][j];
            }
            dp[i + 1][j] |= dp[i][j];
        }
    }
    FOR(i, limit, K + (limit == 0)) if (dp[N][i]) {
        return false;
    }
    return true;
}

int main(void) {
    scanf("%d%d", &N, &K);
    a[0] = 0;
    REP(i, N) {
        scanf("%d", a + i + 1);
    }
    sort(a, a + N + 1);
    if (accumulate(a, a + N + 1, 0ll) < K) {
        cout << N << endl;
        return 0;
    }
    int low = 0, high = N;
    while (high - low > 1) {
        const int mid = (high + low) / 2;
        //DEBUG(mid)
        int id = 0;
        REP(i, N + 1) if (i != mid) {
            abuf[id++] = a[i];
        }
        (check(K - a[mid]) ? low : high) = mid;
    }
    cout << low << endl;
}
