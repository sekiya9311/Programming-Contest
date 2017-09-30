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
LL n, k;
LL a[MAX], b[MAX];
PLL ab[MAX];

int calc_msb(LL num) {
    int msb = 0;
    REP(i, 60) {
        if (num & 1) msb = i;
        num >>= 1;
    }
    return msb;
}

void func1() {
    int kmsb = calc_msb(k);
    LL ans = 0;
    LL buf0 = 0;    // equal to msb && (k & a[i]) != a[i]
    LL buf1 = 0;    // equal to msb && (k & a[i]) == a[i]
    LL buf2 = 0;    // less than msb && (k & a[i]) == a[i]
    LL buf3 = 0;    // less than msb && (k & a[i]) != a[i]
    REP(i, n) {
        int msb = calc_msb(a[i]);
        if (msb > kmsb) continue;
        else if (msb == kmsb && k >= a[i]) {
            if ((k & a[i]) != a[i]) {
                buf0 += b[i];
            } else {
                buf1 += b[i];
            }
        } else if (msb < kmsb) {
            if ((k & a[i]) != a[i]) {
                buf3 += b[i];
            } else {
                buf2 += b[i];
            }
        }
    }
    cout << max({buf0, buf1 + buf2, buf2 + buf3}) << endl;
    cerr << buf0 << " " << buf1 << " " << buf2 << " " << buf3 << endl;
}

map<LL, LL> dp;

LL calc(LL maxNum) {
    //DEBUG(maxNum)
    if (dp.count(maxNum)) return dp[maxNum];
    const int mnMsb = calc_msb(maxNum);
    LL buf = 0; // not up msb(k) bit
    LL buf1 = 0;
    bool f = false;
    REP(i, n) {
        bool ff = true;
        const int amsb = calc_msb(a[i]);
        if (amsb < mnMsb) {
            buf += b[i];
            ff = false;
        }
        if (((a[i] | maxNum) == maxNum)) {
            buf1 += b[i];
            ff = false;
        }
        f |= ff;
    }
    //DEBUG(buf)
    if (!f) return dp[maxNum] = max(buf, buf1);
    if (maxNum == 0) return dp[maxNum] = max(buf, buf1);
    // up msb(k) bit
    REP(i, n) {
        if (a[i] & (1 << mnMsb)) {
            a[i] ^= (1 << mnMsb);
        }
    }
    LL buf2 = calc(maxNum ^ (1 << mnMsb));
    //DEBUG(buf2)
    return dp[maxNum] = max({buf, buf1, buf2});
}

int main(void) {
    scanf("%lld%lld", &n, &k);
    REP(i, n) {
        scanf("%lld%lld", a + i, b + i);
        ab[i] = MP(a[i], b[i]);
    }
    sort(ab, ab + n);
    REP(i, n) {
        a[i] = ab[i].first;
        b[i] = ab[i].second;
    }
    cout << calc(k) << endl;
}
