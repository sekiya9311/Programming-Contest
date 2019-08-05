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

LL calc_gcd(LL *ar, int L) {
    LL tmp = ar[0];
    REP(i, L - 1) {
        tmp = __gcd(tmp, abs(ar[i + 1]));
    }
    return tmp;
}

// 約数列挙
//  (O√n)
std::vector<long long> divisor(const long long n, const bool to_sort) {
    std::vector<long long> ret;
    if (n > 1) for(long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
             ret.emplace_back(i);
             if (i != n / i && i != 1) {
                 ret.emplace_back(n / i);
             }
        }
    }

    if (to_sort) {
        std::sort(std::begin(ret), std::end(ret));
    }

    return ret;
}

const int MAX = 555;
int N;
LL K, A[MAX];

bool check(LL target) {
    VI v;
    REP(i, N) v.EB(A[i] % target);
    SORT(v);

    LL left_sum = 0, right_sum = accumulate(ALL(v), 0LL, [target](LL acc, LL cur) {
        return acc + target - cur;
    });
    if (right_sum == 0) return true;
    LL cnt = 0;
    REP(i, N) {
        left_sum += v[i];
        cnt += v[i];
        right_sum -= target - v[i];
        if (left_sum == right_sum && cnt <= K) {
            return true;
        }
    }
    return false;
}

int main(void) {
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    const auto a_sum = accumulate(A, A + N, 0LL);
    auto div = divisor(a_sum, true);
    div.EB(a_sum);
    REVERSE(div);

    FORE(e, div) {
        if (check(e)) {
            cout << e << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
