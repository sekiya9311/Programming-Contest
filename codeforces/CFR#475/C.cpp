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
const int MOD = INF + 9;
const LL LLINF = 1e18;

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

int N, A, B, K;
string S;

inline get_sign(int idx) {
    idx %= S.size();
    return S[idx] == '+' ? 1 : -1;
}

signed main(void) {
    cin >> N >> A >> B >> K;
    cin >> S;
    LL ans = 0;
    LL nowVal = 0;
    while (S.size() < 1e5) {
        S = S + S;
    }
    const int base = S.size();
    const int invA = mc.inverse(A);
    nowVal = mc.pow(A, N);
    LL CNT = 0;
    REP(i, min(base, N + 1)) {
        CNT++;
        ans = mc.add(ans, get_sign(i) * nowVal);
        nowVal = mc.mul(mc.mul(nowVal, invA), B);
    }
    if (N + 1 <= base) {
        cout << ans << endl;
    } else {
        LL pre = ans;
        const int loop = (N + 1) / base - 1;
        const int amari = (N + 1) % base;
        const int invPowA = mc.inverse(mc.pow(A, base));
        const int powB = mc.pow(B, base);
        REP(i, loop) {
            CNT += base;
            pre = mc.mul(mc.mul(pre, invPowA), powB);
            ans = mc.add(ans, pre);
        }
        pre = mc.mul(mc.pow(A, amari - 1), mc.pow(B, N - amari + 1));
        REP(i, amari) {
            CNT++;
            ans = mc.add(ans, pre * get_sign(i));
            pre = mc.mul(mc.mul(pre, invA), B);
        }
        DEBUG(CNT)
        cout << ans << endl;
    }
}
