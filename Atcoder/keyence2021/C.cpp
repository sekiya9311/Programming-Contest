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
#define GREATER(T) T, VT<T>, greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = 998244353;
const LL LLINF = 1e18;

long long pow_mod(long long a, long long b, long long mod) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret = (a * ret) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}

const int MAX = 5050;
int H, W, K;
LL pow_mod_memo[MAX * MAX];
LL inv_pow_mod_memo[MAX  * MAX];
LL dp[MAX][MAX];
int first_use_free_mass_cnt[MAX][MAX];
char mass[MAX][MAX];

bool free_mass(int h, int w) { return mass[h][w] == 'Z'; }
bool right_mass(int h, int w) { return mass[h][w] == 'R'; }
bool down_mass(int h, int w) { return mass[h][w] == 'D'; }
bool right_and_down_mass(int h, int w) { return mass[h][w] == 'X'; }
LL calc_inv_pow_mod(int i) {
    if (inv_pow_mod_memo[i] != -1) return inv_pow_mod_memo[i];
    return inv_pow_mod_memo[i] = pow_mod(pow_mod_memo[i], MOD - 2, MOD);
}

LL dfs(int h, int w, int use_free_mass_cnt) {
    if (h >= H || w >= W) return 0;
    if (dp[h][w] != -1) {
        const auto tmp = use_free_mass_cnt - first_use_free_mass_cnt[h][w];
        auto res = dp[h][w];
        if (tmp > 0) {
            (res *= calc_inv_pow_mod(tmp)) %= MOD;
        } else if (tmp < 0) {
            (res *= pow_mod_memo[-tmp]) %= MOD;
        }
        return res;
    }
    if (h == H - 1 && w == W - 1) {
        return pow_mod_memo[H * W - use_free_mass_cnt - K];
    }

    const bool free = free_mass(h, w);
    LL ret = 0;

    if (right_and_down_mass(h, w) || free) {
        (ret += dfs(h, w + 1, use_free_mass_cnt + free)) %= MOD;
        (ret += dfs(h + 1, w, use_free_mass_cnt + free)) %= MOD;
    }
    if (right_mass(h, w) || free) {
        (ret += dfs(h, w + 1, use_free_mass_cnt + free)) %= MOD;
    }
    if (down_mass(h, w) || free) {
        (ret += dfs(h + 1, w, use_free_mass_cnt + free)) %= MOD;
    }

    first_use_free_mass_cnt[h][w] = use_free_mass_cnt;
    return dp[h][w] = ret;
}

void solve() {
    REP(i, MAX * MAX) {
        pow_mod_memo[i] = i == 0 ? 1 : pow_mod_memo[i - 1] * 3 % MOD;
        inv_pow_mod_memo[i] = -1;
    }
    REP(i, MAX) REP(j, MAX) {
            mass[i][j] = 'Z';
            dp[i][j] = -1;
    }

    cin >> H >> W >> K;
    REP(i, K) {
        int h, w;
        string tmp;
        cin >> h >> w >> tmp;
        h--;w--;
        mass[h][w] = tmp[0];
    }

    cout << dfs(0, 0, 0) << endl;
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
