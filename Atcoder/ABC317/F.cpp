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

// 剰余計算,MOD計算,順列・組み合わせ,Permutation・Combination
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
int tmp_dp[65][11][11][11][2][2][2][2][2][2];
// dp[bit][x1 mod a1][x2 mod a2][x3 mod a3][[[x1, x2, x3 is more than 0]]][[[x1, x2, x3 less than N]]]

void solve() {
    LL N;
    VL A(3);
    cin >> N >> A[0] >> A[1] >> A[2];
    SORT(A);

    memset(tmp_dp, 0, sizeof(tmp_dp));
    auto dp = tmp_dp + 1;
    dp[63][0][0][0][0][0][0][0][0][0] = 1;
    RREP(bit, 64) {
        const auto n_on_bit = (N & (1LL << bit)) != 0;
        REP(x1_mod, A[0]) {
            REP(x2_mod, A[1]) {
                REP(x3_mod, A[2]) {
                    REP(x1_m0, 2) {
                        REP(x2_m0, 2) {
                            REP(x3_m0, 2) {
                                REP(x1_ln, 2) {
                                    REP(x2_ln, 2) {
                                        REP(x3_ln, 2) {
                                            const auto cur = dp[bit][x1_mod][x2_mod][x3_mod][x1_m0][x2_m0][x3_m0][x1_ln][x2_ln][x3_ln];
                                            REP(nxt_1, 2) {
                                                if (!x1_ln && n_on_bit < nxt_1) {
                                                    continue;
                                                }
                                                REP(nxt_2, 2) {
                                                    if (!x2_ln && n_on_bit < nxt_2) {
                                                        continue;
                                                    }
                                                    const auto nxt_3 = nxt_1 ^ nxt_2;
                                                    if (!x3_ln && n_on_bit < nxt_3) {
                                                        continue;
                                                    }

                                                    const auto nxt_x1_mod = (x1_mod + ((LL)nxt_1 << bit)) % A[0];
                                                    const auto nxt_x2_mod = (x2_mod + ((LL)nxt_2 << bit)) % A[1];
                                                    const auto nxt_x3_mod = (x3_mod + ((LL)nxt_3 << bit)) % A[2];
                                                    const auto nxt_x1_m0 = x1_m0 | nxt_1;
                                                    const auto nxt_x2_m0 = x2_m0 | nxt_2;
                                                    const auto nxt_x3_m0 = x3_m0 | nxt_3;
                                                    const auto nxt_x1_ln = x1_ln | (nxt_1 < n_on_bit);
                                                    const auto nxt_x2_ln = x2_ln | (nxt_2 < n_on_bit);
                                                    const auto nxt_x3_ln = x3_ln | (nxt_3 < n_on_bit);
                                                    auto &target = dp[bit - 1][nxt_x1_mod][nxt_x2_mod][nxt_x3_mod][nxt_x1_m0][nxt_x2_m0][nxt_x3_m0][nxt_x1_ln][nxt_x2_ln][nxt_x3_ln];
                                                    mc.add_ref(target, cur);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    REP(i, 2) {
        REP(j, 2) {
            REP(k, 2) {
                mc.add_ref(ans, dp[-1][0][0][0][1][1][1][i][j][k]);
            }
        }
    }

    cout << ans << "\n";
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
