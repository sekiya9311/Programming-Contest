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
char strbuf[MAX];
int n;
LL a[MAX];
string s;

int main(void) {
    scanf("%d", &n);
    REP(i, n) scanf("%lld", a + i);
    {
        scanf("%s", strbuf);
        s = strbuf;
    }
    int cnt = 0;
    LL l = -1e9, r = 1e9;
    REP(i, n - 1) {
        if (s[i] == '0' && s[i + 1] == '1') {
            cnt = 1;
            REP(j, 5) {
                chmax(l, a[i + 1 - j] + 1LL);
            }
        } else if (s[i] == '1' && s[i + 1] == '0') {
            cnt = 1;
            REP(j, 5) {
                chmin(r, a[i + 1 - j] - 1LL);
            }
        } else {
            cnt++;
            if (cnt >= 5) {
                if (s[i + 1] == '1') {
                    bool ok = false;
                    REP(j, 5) {
                        ok |= r >= a[i + 1  - j];
                    }
                    if (!ok) {
                        LL mi = INF;
                        REP(j, 5) {
                            chmin(mi, a[i + 1 - j]);
                        }
                        r = mi + 1;
                    }
                } else {
                    bool ok = false;
                    REP(j, 5) {
                        ok |= a[i + 1 - j] >= l;
                    }
                    if (!ok) {
                        LL ma = -INF;
                        REP(j, 5) {
                            chmax(ma, a[i + 1 - j]);
                        }
                        l = ma - 1;
                    }
                }
            }
        }
    }
    cout << l << " " << r << endl;
}
