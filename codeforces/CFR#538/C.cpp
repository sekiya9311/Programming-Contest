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

// 素因数分解
// O(√N * std::map)
//res[i] = n : iがn個
VT<pair<LL, int>> prime_factor_decomposition(long long N) {
    VT<pair<LL, int>> res;
    for (long long i = 2; i * i <= N; i++) {
        int cnt = 0;
        while(N % i == 0) {
            cnt++;
            N /= i;
        }
        if (cnt) {
            //res[i] = cnt;
            res.EB(1ll * i, cnt);
        }
    }
    if (N != 1) {
        res.EB(N, 1);
    }
    return res;
}

LL calc(LL n, LL b) {
    LL tmp = b;
    LL ret = 0;
    while (tmp <= n) {
        ret += n / tmp;
        if (n / tmp < b) break;
        tmp *= b;
    }
    return ret;
}

LL N, B;

int main(void) {
    cin >> N >> B;
    LL ans = LLINF;
    auto foo = prime_factor_decomposition(B);
    FORE(e, foo) {
        auto tmp = calc(N, e.first);
        chmin(ans, tmp / e.second);
    }
    cout << ans << endl;
}
