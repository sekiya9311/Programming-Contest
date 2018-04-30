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
#define DEBUG(C) cerr << #C << " = " << (C) << endl;
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

const int MAX = 3e5 + 10;
int n;
LL x[2];
pair<LL, int> c[MAX];

int main(void) {
    scanf("%d%lld%lld", &n, x, x + 1);
    REP(i, n) {
        scanf("%lld", &c[i].first);
        c[i].second = i;
    }
    sort(c, c + n);
    REP(_, 2) {
        const auto f = x[_];
        const auto s = x[(_ + 1) % 2];
        REP(i, n) {
            // i-1以下使わない
            int low = i - 1, high = n - 1;
            while (high - low > 1) {
                const int mid = low + (high - low) / 2;
                if (1. * f / (mid - i + 1) <= c[i].first) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            if (high < n - 1 && 1. * f / (high - i + 1) <= c[i].first && 1. * s / (n - high - 1) <= c[high + 1].first) {
                puts("Yes");
                if (_ == 0) {
                    printf("%d %d\n", high - i + 1, n - high - 1);
                    FOR(j, i, high + 1) printf("%d%c", c[j].second + 1, (j == high ? '\n' : ' '));
                    FOR(j, high + 1, n) printf("%d%c", c[j].second + 1, (j + 1 == n ? '\n' : ' '));
                } else {
                    printf("%d %d\n", n - high - 1, high - i + 1);
                    FOR(j, high + 1, n) printf("%d%c", c[j].second + 1, (j + 1 == n ? '\n' : ' '));
                    FOR(j, i, high + 1) printf("%d%c", c[j].second + 1, (j == high ? '\n' : ' '));
                }
                return 0;
            }
        }
    }
    puts("No");
}
