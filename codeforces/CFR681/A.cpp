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
const int MOD = INF + 7;
const LL LLINF = 1e18;

// エラトステネスの篩,素数列挙
// O(N log log N)
std::vector<int> sieve_of_eratosthenes(const int n) {
    std::vector<bool> is(n + 1, true);
    std::vector<int> res;
    is[0] = false;
    is[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is[i]) {
            res.emplace_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is[j] = false;
            }
        }
    }
    return res;
}

bool check(const VL &se) {
    FORE(e1, se) FORE(e2, se) {
            if (e1 == e2) continue;
        if (__gcd(e1, e2) == 1 || e1 % e2 == 0 || e2 % e1 == 0) return false;
    }
    return true;
}

bool check2(const VL &v, LL t) {
    FORE(e, v) {
        if (__gcd(e, t) == 1 || e % t == 0 || t % e == 0) return false;
    }
    return true;
}

void solve2() {
    int N;
    cin >> N;

    // const auto p = sieve_of_eratosthenes(N * 4);
    VL ans;
    for (int i = N * 4; i > 0; i--) {
        if (check2(ans, i)) ans.EB(i);
    }

//    assert(ans.size() == N);
//    assert(check(ans));
    REP(i, N) {
        printf("%lld%c", ans[i], (i + 1 == N ? '\n' : ' '));
    }
    puts("\n");
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        solve2();
    }
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
