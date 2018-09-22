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

// gcd,lcm,最大公約数,最小公倍数
// O(log max(a,b))
long long gcd(long long a, long long b) {
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

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

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

const int MAX = 3e5 + 10;
const int MAX_V = 1.5 * 1e7 + 10;
int N;
int a[MAX];
int cnt[MAX_V];
VI primes;

int main(void) {
    {
        primes = sieve_of_eratosthenes(MAX_V);
    }
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", a + i);
    }
    LL all_gcd = a[0];
    FOR(i, 1, N) {
        all_gcd = __gcd(all_gcd, 1ll * a[i]);
    }
    REP(i, N) {
        a[i] /= all_gcd;
        FORE(e, primes) {
            if (1ll * e * e <= a[i]) {
                if (a[i] % e == 0) {
                    cnt[e]++;
                    while (a[i] % e == 0) {
                        a[i] /= e;
                    }
                }
            } else {
                break;
            }
        }
        cnt[a[i]]++;
    }
    int ans = 0;
    FOR(i, 2, MAX_V) {
        chmax(ans, cnt[i]);
    }
    if (ans == 0) cout << -1 << endl;
    else cout << N - ans << endl;
}
