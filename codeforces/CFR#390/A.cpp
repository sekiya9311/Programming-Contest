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

int n;
VI a;
VI asum;

int main(void) {
    scanf("%d", &n);
    a.resize(n);
    asum.resize(n+1);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) {
        if (i) asum[i] = asum[i - 1] + a[i];
        else asum[i] = a[i];
    }
    if (n == 1 && a[0] == 0) {
        puts("NO");
        return 0;
    }
    if (false) {
        puts("YES");
        puts("1");
        printf("%d %d\n", 1, n);
        return 0;
    } else {
        REP(i, n) {
            if (asum[i] != 0 && asum[n - 1] - asum[i] != 0) {
                puts("YES");
                puts("2");
                printf("%d %d\n", 1, i + 1);
                printf("%d %d\n", i + 2, n);
                return 0;
            }
        }
    }
    if (accumulate(ALL(a), 0) != 0) {
        puts("YES");
        puts("1");
        printf("%d %d\n", 1, n);
        return 0;
    }
    puts("NO");
}
