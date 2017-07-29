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

const int MAX = 55;
int n;
LL a[MAX];
LL cnt[MAX];

void TLE() {
    LL cnt = 0;
    LL ma = -1, idx = -1;
    while (true) {
        ma = -1, idx = -1;
        REP(i, n) if (chmax(ma, a[i])) idx = i;
        if (ma < n) break;
        REP(i, n) {
            if (i == idx) a[i] -= n;
            else a[i]++;
        }
        ++cnt;
    }
    cout << cnt << endl;
}

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%lld", a + i);
    }
    sort(a, a + n);
    LL ans = 0;
    while (true) {
        LL nowCnt = 0;
        bool f = false;
        RREP(i, n) {
            cnt[i] = 0;
            if (a[i] >= n) {
                LL buf = (a[i]) / n;   // こいつをN - 1以下まで持ってくのに必要な回数
                a[i] = (a[i]) % n;
                nowCnt += buf;
                cnt[i] = buf;
            }
        }
        REP(i, n) {
            a[i] += nowCnt - cnt[i];
            f |= a[i] >= n;
        }
        ans += nowCnt;
        if (!f) break;
    }
    cout << ans << endl;
}
