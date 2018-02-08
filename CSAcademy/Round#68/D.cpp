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

const int MAX = 2222;
LL ans[MAX][MAX];

void TLE() {
    int N, q;
    scanf("%d%d",&N, &q);
    while (q--) {
        int r, c, l;
        LL s;
        scanf("%d%d%d%lld", &r, &c, &l, &s);
        r--;c--;

        REP(x, N) {
            if (r <= x && x < r + l) {
                int miY = c;
                int maY = x - r + c;
                if (miY <= maY) {
                    ans[x][miY] += s;
                    ans[x][maY + 1] -= s;
                }
            }
        }
    }
    REP(x, N) {
        REP(y, MAX - 1) ans[x][y + 1] += ans[x][y];
    }
    REP(i, N) {
        REP(j, N) {
            printf("%lld%c", ans[i][j], (j + 1 == N ? '\n' : ' '));
        }
    }
}

int main(void) {
    int N, q;
    scanf("%d%d",&N, &q);
    while (q--) {
        int r, c, l;
        LL s;
        scanf("%d%d%d%lld", &r, &c, &l, &s);
        r--;c--;

        int miR = r;
        int miC = c;
        int maR = r + l;
        int maC = maR - r + c;

        ans[miR][miC] += s;
        ans[miR][miC + 1] -= s;
        ans[maR][miC] -= s;
        ans[maR + 1][miC + 1] += s;
        ans[maR][maC + 1] += s;
        ans[maR + 1][maC + 1] -= s;

    }


    REP(i, N) {
        REP(j, N) {
            ans[i + 1][j] += ans[i][j];
        }
    }
    REP(i, N) {
        REP(j, N) {
            ans[i][j + 1] += ans[i][j];
        }
    }
    REP(i, N) {
        REP(j, N) {
            ans[i + 1][j + 1] += ans[i][j];
        }
    }

    REP(i, N) {
        REP(j, N) {
            printf("%lld%c", ans[i][j], (j + 1 == N ? '\n' : ' '));
        }
    }
}
