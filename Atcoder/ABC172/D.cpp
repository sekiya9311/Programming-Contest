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

const int MAX = 1e7 + 10;
int memo[MAX];
VI p;
unordered_set<int> ps;

LL calc(int cur) {
    const auto a = cur;
    if (ps.count(cur)) return memo[cur] = 2;
    VI tmp;
    FORE(e, p) {
        int cnt = 0;
        while (cur % e == 0) {
            cnt++;
            cur /= e;
        }
        if (cnt == 0) continue;
        return memo[a] =  memo[cur] * (cnt + 1);
    }
    return -1;
}

int main(void) {
    LL N;
    cin >> N;
    p = sieve_of_eratosthenes(N);
    ps = unordered_set<int>(ALL(p));
    memo[1] = 1;

    LL ans = 1;
    FOR(i, 2, N + 1) {
        const auto cur = calc(i);
        ans += cur * i;
    }

    cout << ans << endl;
}
