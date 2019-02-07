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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

LL divisor(const long long n) {
    LL ret = 0;
    if (n > 1) for(long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
             chmax(ret, i);
             if (i != n / i && i != 1) {
                 chmax(ret, n / i);
             }
        }
    }
    return ret;
}

const int MAX = 1e3 + 10;
int q;
LL a[MAX];
map<LL, LL> sp;

LL calc(LL v) {
    int bit = 0;
    while (v) {
        bit++;
        v /= 2;
    }
    return 1LL << bit;
}

int main(void) {
    scanf("%d", &q);
    REP(i, q) {
        scanf("%lld", a + i);
    }
    REP(i, 26) {
        sp[(1LL << i) - 1] = max(divisor((1LL << i) - 1), 1LL);
    }
    REP(i, q) {
        if (__builtin_popcountll(a[i] + 1) == 1) {
            printf("%lld\n", sp[a[i]]);
        } else {
            printf("%lld\n", calc(a[i]) - 1);
        }
    }
}
