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

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> is(n + 1, true);
    vector<int> res;
    is[0] = false;
    is[1] = false;
    for (int i = 2; i <= n; i++) if (is[i]) {
        res.emplace_back(i);
        for (int j = i * 2; j <= n; j += i) {
            is[j] = false;
        }
    }
    return res;
}

const int MAX = 1e6;
int n, k;
VI primes;
int ans[MAX];
// k : 互いに素なペア(gcd(a, b) == 1)の個数

int main(void) {
    scanf("%d%d", &n, &k);
    primes = sieve_of_eratosthenes(MAX);
    k = n * (n - 1) / 2 - k; // 互いに素ではないペアをk個作るようにする
    REP(i, n) {
        ans[i] = primes[i + 2];
    }
    int buf = 0;
    for (; buf * (buf + 1) / 2 <= k; buf++);
    
    REP(i, buf) {
        ans[i] <<= 1;
    }
    if (k - buf * (buf - 1) / 2 > 0) {
        ans[buf] *= 3;
        REP(i, k - 1ll * buf * (buf - 1) / 2) {
            ans[i] *= 3;
        }
    }

    REP(i, n) {
        printf("%d%c", ans[i], i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
