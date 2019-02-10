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

const int MAX = 5555;
int N;
int c[MAX];
int dp[MAX][MAX];

int dfs(int l, int r) {
    if (dp[l][r] < INF) {
        return dp[l][r];
    }
    auto &ret = dp[l][r];
    if (l + 1 <= r - 1) {
        int cnt = 1;
        if (c[l] != c[r]) {
            cnt++;
        }
        chmin(ret, dfs(l + 1, r - 1) + cnt);
    }
    if (l + 1 <= r) {
        int cnt = 0;
        if (c[l] != c[l + 1]) {
            cnt++;
        }
        chmin(ret, dfs(l + 1, r) + cnt);
    }
    if (l <= r - 1) {
        int cnt = 0;
        if (c[r] != c[r - 1]) {
            cnt++;
        }
        chmin(ret, dfs(l, r - 1) + cnt);
    }
    return ret;
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", c + i);
    }
    REP(i, MAX) {
        REP(j, MAX) {
            if (i != j) dp[i][j] = INF;
            else dp[i][j] = 0;
        }
    }
    cout << dfs(0, N - 1) << endl;
}
