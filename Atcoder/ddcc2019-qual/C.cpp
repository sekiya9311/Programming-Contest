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

// powmod 累乗
// O(log b)
long long pow_mod(long long a, long long b, long long mod) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret = (a * ret) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}

const int MAX = 1e5 + 10;
int N;

int main(void) {
    cin >> N;
    LL ans = 0;
    FOR(i, 1, N + 1) {
        int high = N + 1, low = 1;
        while (high - low > 1) {
            const int mid = (high + low) / 2;
            if (1ll * mid * i <= N) {
                low = mid;
            } else {
                high = mid;
            }
        }
        //cerr << i << " " << low << endl;
        (ans += (pow_mod(i, 10, MOD) - pow_mod(i - 1, 10, MOD) + MOD) * pow_mod(low, 10, MOD) % MOD) %= MOD;
    }
    cout << ans % MOD << endl;
}
