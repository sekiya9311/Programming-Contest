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
LL b1, q, l, m;
LL a[MAX];
unordered_set<LL> dame;

int main(void) {
    scanf("%lld%lld%lld%lld", &b1, &q, &l, &m);
    REP(i, m) {
        scanf("%lld", a + i);
        dame.insert(a[i]);
    }
    if (q == 0) {
        if (b1 == 0) {
            if (dame.count(0)) {
                puts("0");
            } else {
                puts("inf");
            }
        } else {
            if (dame.count(0)) {
                if (dame.count(b1) == 0 && llabs(b1) <= l) {
                    puts("1");
                } else {
                    puts("0");
                }
            } else {
                if (llabs(b1) <= l) puts("inf");
                else puts("0");
            }
        }
    } else if (b1 == 0) {
        if (dame.count(0)) {
            puts("0");
        } else {
            puts("inf");
        }
    } else if (q == 1) {
        if (dame.count(b1) || llabs(b1) > l) {
            puts("0");
        } else {
            puts("inf");
        }
    } else if (q == -1) {
        if ((dame.count(b1) && dame.count(-b1)) || llabs(b1) > l) {
            puts("0");
        } else {
            puts("inf");
        }
    } else {
        LL now = b1;
        int ans = 0;
        while (true) {
            if (dame.count(now) == 0 && llabs(now) <= l) {
                ++ans;
            } else if (llabs(now) > l) {
                break;
            }
            now *= q;
        }
        printf("%d\n", ans);
    }
}
