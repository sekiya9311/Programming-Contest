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
const int MOD = 998244353;
const LL LLINF = 1e18;

template<int mod>
class ModCalc {
private:
    const int defnum = -1;
public:
    ModCalc() { }
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

const int MAX = 3 * 1e5 + 10;
ModCalc<MOD> mc;
int memoFact[MAX], memoInvFact[MAX];

inline int fact(int n) {
    if (memoFact[n] != -1) return memoFact[n];
    return memoFact[n] = (n == 0 ? 1 : mc.mul(n, fact(n - 1)));
}

inline int invFact(int n) {
    if (memoInvFact[n] != -1) return memoInvFact[n];
    return memoInvFact[n] = mc.inverse(fact(n));
}

inline long long Perm(int n, int r) {
    return mc.mul(fact(n), invFact(n - r));
}

inline long long comb(int n, int r) {
    return mc.mul(mc.mul(fact(n), invFact(r)), invFact(n - r));
}

// M個の物をN人で分ける
inline long long combWithRepetition(int M, int N) {
    return comb(M + N - 1, N - 1);
}

//最初に呼んで♪
inline void init() {
    memset(memoFact, -1, sizeof(memoFact));
    memset(memoInvFact, -1, sizeof(memoInvFact));
    for (int i = 0; i < MAX; i++) {
        fact(i);
        invFact(i);
    }
}

LL N, A, B, K;

int main(void) {
    init();
    cin >> N >> A >> B >> K;
    LL ans = 0;
    REP(i, N + 1) {
        if ((K - i * A) % B) {
            continue;
        }
        if (K - i * A < 0) {
            continue;
        }
        LL red = i;
        LL blue = (K - i * A) / B;
        if (blue > N) {
            continue;
        }
        //cerr << red << " " << blue << endl;
        ans += mc.mul(comb(N, red), comb(N, blue));
        ans %= MOD;
    }
    cout << ans << endl;
}
