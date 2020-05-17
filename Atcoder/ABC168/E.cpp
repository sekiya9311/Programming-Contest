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

const int MAX = 2e5 + 10;

template<int mod>
class mod_calc {
private:
    const int defnum = -1;
public:
    mod_calc() { }
    const inline int add(int a, const int b) const {
        a += b;
        while (a < 0) a += mod;
        while (a >= mod) a -= mod;
        return a;
    }
    const inline int mul(const int a, const int b) const {
        return (long long)a * b % mod;
    }
    const inline void add_ref(int &a, const int b) const {
        a = this->add(a, b);
    }
    const inline void mul_ref(int &a, const int b) const {
        a = this->mul(a, b);
    }
    const inline void add_ref(long long &a, const int b) const {
        a = this->add(a, b);
    }
    const inline void mul_ref(long long &a, const int b) const {
        a = this->mul(a, b);
    }
    const inline int pow(int a, int p) const {
        int res = 1;
        while (p > 0) {
            if (p & 1) res = this->mul(res, a);
            a = this->mul(a, a);
            p >>= 1;
        }
        return res;
    }
    const inline int inverse(int a) const {
        return this->pow(a, mod - 2);
    }
};

mod_calc<MOD> mc;
int memo_fact[MAX], memo_inv_fact[MAX];

inline int fact(int n) {
    if (memo_fact[n] != -1) return memo_fact[n];
    return memo_fact[n] = (n == 0 ? 1 : mc.mul(n, fact(n - 1)));
}

inline int inv_fact(int n) {
    if (memo_inv_fact[n] != -1) return memo_inv_fact[n];
    return memo_inv_fact[n] = mc.inverse(fact(n));
}

inline long long perm(int n, int r) {
    return mc.mul(fact(n), inv_fact(n - r));
}

inline long long comb(int n, int r) {
    return mc.mul(mc.mul(fact(n), inv_fact(r)), inv_fact(n - r));
}

// M個の物をN人で分ける
inline long long comb_with_repetition(int M, int N) {
    return comb(M + N - 1, N - 1);
}

//最初に呼んで♪ O(MAX)
inline void init() {
    memset(memo_fact, -1, sizeof(memo_fact));
    memset(memo_inv_fact, -1, sizeof(memo_inv_fact));
    for (int i = 0; i < MAX; i++) {
        fact(i);
        inv_fact(i);
    }
}

int N;
PLL AB[MAX];

int main(void) {
    init();
    cin >> N;
    REP(i, N) {
        cin >> AB[i].first >> AB[i].second;
    }

    int all_zero = 0, a_zero = 0, b_zero = 0;
    map<PLL, int> mp;
    REP(i, N) {
        if (AB[i] == MP(0LL, 0LL)) {
            all_zero++;
        } else if (AB[i].first == 0) {
            a_zero++;
        } else if (AB[i].second == 0) {
            b_zero++;
        } else {
            const auto tmp = gcd(abs(AB[i].first), abs(AB[i].second));
            AB[i].first /= tmp;
            AB[i].second /= tmp;
            if ((AB[i].first < 0 && AB[i].second < 0) || (AB[i].first > 0 && AB[i].second < 0)) {
                // only {+, +} or {-, +}
                AB[i].first *= -1;
                AB[i].second *= -1;
            }
            mp[AB[i]]++;
        }
    }
    const int normal = N - all_zero - a_zero - b_zero;

    LL ans = mc.add(
        mc.add(
            mc.add(mc.pow(2, a_zero), -1),
            mc.add(mc.pow(2, b_zero), -1)
        ),
        1
    );

    FORE(e, mp) {
        if (e.second == 0) continue;
        const auto rev = e.first.first > 0
            ? MP(e.first.second * -1, e.first.first)
            : MP(e.first.second, e.first.first * -1);
        if (mp.count(rev) == 0) {
            const auto tmp = mc.add(
                mc.add(mc.pow(2, e.second), -1),
                1
            );
            ans = mc.mul(ans, tmp);
        } else {
            const auto tmp = mc.add(
                mc.add(
                    mc.add(mc.pow(2, e.second), -1),
                    mc.add(mc.pow(2, mp[rev]), -1)
                ),
                1
            );
            ans = mc.mul(ans, tmp);
            mp[rev] = 0;
        }
        e.second = 0;
    }

    cout << (ans + all_zero - 1 + MOD) % MOD << endl;
}
