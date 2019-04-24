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

// 約数列挙
//  (O√n)
std::vector<long long> divisor(const long long n) {
    std::vector<long long> ret;
    if (n > 1) for(long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
             ret.emplace_back(i);
             if (i != n / i && i != 1) {
                 ret.emplace_back(n / i);
             }
        }
    }
    return ret;
}

// gcd,lcm,最大公約数,最小公倍数
// O(log max(a,b))

long long my_gcd(long long a, long long b) {
    if(a < b) {
        std::swap(a, b);
    }
    long long ret = 1;
    while (b) {
        ret = b;
        b = a % b;
        a = ret;
    }
    return ret;
}

long long my_lcm(long long a, long long b) {
    return a / my_gcd(a, b) * b;
}

LL A, B;

int main(void) {
    cin >> A >> B;
    const auto mi = min(A, B);
    const auto ma = max(A, B);
    if (ma % mi == 0) {
        cout << 0 << endl;
        return 0;
    }

    const auto ma_gcd = ma - mi;
    auto divs = divisor(ma_gcd);
    divs.EB(ma_gcd);
    LL ans = 0;
    LL mi_lcm = my_lcm(mi, ma);
    FORE(d, divs) {

        const auto tmp_mi = d - mi % d;
        const auto tmp_ma = d - ma % d;
        // DEBUG(d)
        // DEBUG(tmp_mi)
        // DEBUG(tmp_ma)
        const auto tmp_lcm = my_lcm(tmp_mi, tmp_ma);
        if (chmin(mi_lcm, my_lcm(mi + tmp_lcm, ma + tmp_lcm))) {
            ans = tmp_lcm;
        }
    }

    cout << ans << endl;
}
