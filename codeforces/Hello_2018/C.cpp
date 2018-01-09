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

const int MAX = 33;
int n;
LL L, c[MAX];

signed main(void) {
    cin >> n >> L;
    int msb;
    {
        REP(i, 30) if (L & (1ll << i)) msb = i;
        msb++;
    }
    LL sum2 = LLINF;
    REP(i, n) {
        cin >> c[i];
        if (chmin(sum2, c[i] << max(0, msb - i))) {
            DEBUG(i)
        }
    }
    LL sum = 0;
    VL anses;
    RREP(i, 30) {
        {
            LL miCost = LLINF;
            LL getL = 0;
            int jj;
            REP(j, n) {
                if (chmin(miCost, c[j] * (1ll << max(0, i - j + 1)))) {
                    getL = 1ll << max(i + 1, j);
                    jj = j;
                }
            }
            anses.EB(miCost + sum);
        }
        if (L & (1ll << i)) {
            LL miCost = LLINF;
            LL getL = 0;
            int jj;
            REP(j, n) {
                if (chmin(miCost, c[j] * (1ll << max(0, i - j)))) {
                    getL = 1ll << max(i, j);
                    jj = j;
                }
            }
            DEBUG(i)
            DEBUG(jj)
            sum += miCost;
            L -= getL;
        }
        if (L <= 0) {
            break;
        }
    }
    anses.EB(sum);
    anses.EB(sum2);
    cout << (*min_element(ALL(anses))) << endl;
}
