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

int a[3][6];
int n;

int main(void) {
    cin >> n;
    REP(i, n) REP(j, 6) cin >> a[i][j];
    int now = 1;
    while (true) {
        bool ok = false;
        if (now < 10) {
            REP(i, n) REP(j, 6) if (a[i][j] == now) ok = true;
        } else if (now < 100) {
            int ten = now / 10, one = now % 10;
            REP(i, n) {
                REP(j, 6) {
                    if (a[i][j] == ten) {
                        REP(k , n) if (k != i) REP(l, 6) if (a[k][l] == one) ok = true;
                    }
                }
            }
        } else if (now < 1000) {
            int han = now / 100, ten = (now % 100) / 10, one = now % 10;
            REP(i, n) {
                REP(j, 6) if (a[i][j] == han) {
                    REP(k, n) if (k != i) REP(l, 6) if (a[k][l] == ten) {
                        REP(m, n) if (m != i && m != k) REP(o, 6) if (a[m][o] == one) ok = true;
                    }
                }
            }
        }
        if (!ok) {
            cout << now - 1 << endl;
            return 0;
        }
        now++;
    }
    return 0;
}
