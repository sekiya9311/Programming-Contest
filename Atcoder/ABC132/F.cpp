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

const int MAX_N = 111;
const int MAX_DIV_CNT = 1e5 + 10;
LL N;
int K;
int dp[MAX_N][MAX_DIV_CNT];
int n_div_cnt;
int interval[MAX_DIV_CNT];

int main(void) {
    cin >> N >> K;
    {
        set<int> se;
        for (int i = 1; i * i <= N; i++) {
            se.emplace(i);
            se.emplace(N / i);
        }
        VL divs_n(ALL(se));
        divs_n.insert(begin(divs_n), 0);

        n_div_cnt = divs_n.size();
        REP(i, n_div_cnt - 1) {
            interval[i] = divs_n[i + 1] - divs_n[i];
        }
    }

    REP(i, n_div_cnt - 1) {
        dp[0][i] = interval[i];
    }
    REP(i, K - 1) {
        VI prev_dp_sum(n_div_cnt - 1);
        partial_sum(dp[i], dp[i] + n_div_cnt - 1, begin(prev_dp_sum), [&](const int l, const int r) {
            return mc.add(l, r);
        });

        REP(j, n_div_cnt - 1) {
            dp[i + 1][j] = mc.mul(prev_dp_sum[n_div_cnt - 1 - j - 1], interval[j]);
        }
    }

    const int ans = accumulate(dp[K - 1], dp[K - 1] + n_div_cnt - 1, 0, [](const int l, const int r) {
        return mc.add(l, r);
    });
    cout << ans << endl;
}
