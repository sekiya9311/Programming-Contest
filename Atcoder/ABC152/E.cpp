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
VT<pair<LL, int>> prime_factor_decomposition(long long N) {
    VT<pair<LL, int>> res;
    for (long long i = 2; i * i <= N; i++) {
        int cnt = 0;
        while(N % i == 0) {
            cnt++;
            N /= i;
        }
        if (cnt) {
            res.EB(i, cnt);
        }
    }
    if (N != 1) {
        res.EB(N, 1);
    }
    return res;
}

LL pow_mod(LL a, LL p) {
    if (p == 0) return 1;
    if (p % 2) return a * pow_mod(a, p - 1) % MOD;
    const auto t = pow_mod(a, p / 2);
    return t * t % MOD;
}

int N;
VL A;
VT<VT<pair<LL, int>>> ps;

int main(void) {
    cin >> N;
    A.resize(N);

    REP(i, N) {
        cin >> A[i];
        ps.EB(prime_factor_decomposition(A[i]));
    }

    map<LL, int> cnt;
    FORE(p, ps) {
        FORE(e, p) {
            if (cnt.count(e.first) == 0) {
                cnt[e.first] = e.second;
            } else {
                cnt[e.first] = max(cnt[e.first], e.second);
            }
        }
    }

    LL ans = 1;
    FORE(e, cnt) {
        //cerr << e.first << " " << e.second << " " << pow_mod(e.first, e.second) << endl;
        (ans *= pow_mod(e.first, e.second)) %= MOD;
    }

    const LL tmp = ans;
    ans = 0;
    REP(i, N) {
        (ans += tmp * pow_mod(A[i], MOD - 2)) %= MOD;
    }

    cout << ans << endl;
}
