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
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

struct item_type {
    LL V, W;
    item_type() {
        V = 0;
        W = 0;
    }
};
struct query_type {
    int v;
    LL L;
};

int get_parent(const int i) {
    if (i == 0) return -1;
    return (i - 1) / 2;
}

const int MAX_BIT = 18;
const int MAX_N = (1 << MAX_BIT) + 10;
const int MAX_W = 1e5 + 10;
int N;
item_type items[MAX_N];
int Q;
query_type queries[MAX_N];
LL dp[1 << (MAX_BIT / 2)][MAX_W];
int get_lim() { return min(N, MAX_BIT / 2); }

LL calc(query_type query) {
    const auto L = get_lim();
    VI cand;
    int point = query.v;
    {
        while (point >= (1 << L)) {
            cand.EB(point);
            point = get_parent(point);
        }
    }

    LL res = dp[point][query.L];
    REP(i, (1 << cand.size())) {
        LL cur_w = 0, cur_v = 0;
        REP(j, cand.size()) {
            if (i & (1 << j)) {
                cur_w += items[cand[j]].W;
                cur_v += items[cand[j]].V;
            }
        }
        const auto nokori = query.L - cur_w;
        if (nokori < 0) continue;
        chmax(res, cur_v);
        chmax(res, cur_v + dp[point][nokori]);
    }
    return res;
}

void pre_calc() {
    memset(dp, -1, sizeof(-1));
    const int L = get_lim();
    REP(i, (1 << L)) {
        const int par = get_parent(i);
        if (par == -1) {
            // i == 0
            dp[i][items[i].W] = items[i].V;
            dp[0][0] = 0;
            continue;
        }
        REP(j, MAX_W) if (dp[par][j] != -1) {
            chmax(dp[i][j], dp[par][j]);
            if (j + items[i].W < MAX_W) {
                chmax(dp[i][j + items[i].W], dp[par][j] + items[i].V);
            }
        }
    }
    REP(i, (1 << L)) {
        REP(j, MAX_W - 1) {
            chmax(dp[i][j + 1], dp[i][j]);
        }
    }
}

void func() {
    REP(_, Q) {
        const auto query = queries[_];
        const auto ans = calc(query);
        printf("%lld\n", ans);
    }
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld%lld", &items[i].V, &items[i].W);
    }
    scanf("%d", &Q);
    REP(i, Q) {
        scanf("%d%lld", &queries[i].v, &queries[i].L);
        queries[i].v--;
    }

    pre_calc();
    func();
}
