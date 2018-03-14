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

const int MAX = 1e5 + 10;

template<int mod>
class ModCalc {
private:
    const int defnum = -1;
public:
    ModCalc() { }
    int add(int a, int b) {
        a += b;
        while (a < 0) a += mod;
        while (a >= mod) a -= mod;
        return a;
    }
    int mul(int a, int b) {
        return (long long)a * b % mod;
    }
    int pow(int a, int p) {
        int res = 1;
        while (p > 0) {
            if (p & 1) res = this->mul(res, a);
            a = this->mul(a, a);
            p >>= 1;
        }
        return res;
    }
    int inverse(int a) {
        return this->pow(a, mod - 2);
    }
};

ModCalc<MOD> mc;
int memoFact[MAX], memoInvFact[MAX];

int fact(int n) {
    if (memoFact[n] != -1) return memoFact[n];
    return memoFact[n] = (n == 0 ? 1 : mc.mul(n, fact(n - 1)));
}

int invFact(int n) {
    if (memoInvFact[n] != -1) return memoInvFact[n];
    return memoInvFact[n] = mc.inverse(fact(n));
}

LL perm(LL n, LL r) {
    return mc.mul(fact(n), invFact(n - r));
}

LL comb(LL n, LL r) {
    return mc.mul(mc.mul(fact(n), invFact(r)), invFact(n - r));
}

// M個の物をN人で分ける
LL combWithRepetition(LL M, LL N) {
    return comb(M + N - 1, N - 1);
}

//最初に呼んで♪
void init() {
    memset(memoFact, -1, sizeof(memoFact));
    memset(memoInvFact, -1, sizeof(memoInvFact));
    for (int i = 0; i < MAX; i++) {
        fact(i);
        invFact(i);
    }
}

int n;
int a[MAX];

int main(void) {
    init();
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    map<int, int> v;
    REP(i, n) {
        v[a[i]]++;
    }
    LL ans = 1;
    int ma = 0;
    for_each(ALL(v), [&](auto e) {chmax(ma, e.second);});
    bool f = true;
    for_each(ALL(v), [&](auto e) {
        if (e.second == ma && f) {
            f = false;
        } else {
            (ans *= perm(ma, e.second)) %= MOD;
        }
    });
    cout << ans << endl;
}
