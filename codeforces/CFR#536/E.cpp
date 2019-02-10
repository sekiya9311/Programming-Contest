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
#include <functional>

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

struct state {
    int s, t, d;
    LL w;
    int idx;
    bool operator>(const state& other) const {
        if (w == other.w) {
            if (d == other.d) return idx > other.idx;
            else return d > other.d;
        }
        else return  w > other.w;
    }
    state() {}
    state(int _s, int _t, int _d, LL _w, int i)
        : s(_s), t(_t), d(_d), w(_w), idx(i) {}
};

const int MAX = 1e5 + 10;
int N, M, K;
state st[MAX];

int work[MAX];
LL dp[MAX][222];

int main(void) {
    scanf("%d%d%d", &N, &M, &K);
    REP(i, K) {
        int s, t, d;
        LL w;
        scanf("%d%d%d%lld", &s, &t, &d, &w);
        s--;
        t--;
        d--;
        st[i] = state(s, t, d, w, i);
    }
    {
        // calc need to do work
        memset(work, -1, sizeof(work));
        VVI left(MAX), right(MAX);
        REP(i, K) {
            left[st[i].s].EB(i);
            right[st[i].t].EB(i);
        }
        set<state, greater<state>> se;
        REP(i, N) {
            FORE(e, left[i]) {
                se.emplace(st[e]);
            }
            if (!se.empty()) {
                work[i] = se.begin()->idx;
            }
            FORE(e, right[i]) {
                se.erase(st[e]);
            }
        }
    }
    REP(i, MAX) REP(j, 222) dp[i][j] = LLINF;
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, M + 1) {
            // dp
            if (dp[i][j] == LLINF) {
                continue;
            }

            if (work[i] == -1) {
                chmin(dp[i + 1][j], dp[i][j]);
            } else {
                chmin(dp[st[work[i]].d + 1][j], dp[i][j] + st[work[i]].w);
                if (j < M) {
                    chmin(dp[i + 1][j + 1], dp[i][j]);
                }
            }
        }
    }
    cout << *min_element(ALL(dp[N])) << endl;
}
