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

const int MAX = 1e5 + 10;
int N;
LL s[MAX];
LL a[MAX];

VI G[MAX];

bool valid = true;

void dfs(int now, int prev) {
    const auto par_sum = s[prev];
    if (s[now] == -1) {
        s[now] = par_sum;
        a[now] = 0;
    } else {
        a[now] = s[now] - par_sum;
        if (a[now] < 0) {
            valid = false;
        }
    }
    FORE(e, G[now]) {
        dfs(e, now);
    }
}

LL dfs2(int now, int prev, int rank) {
    LL mi = LLINF, ma = -LLINF;
    FORE(e, G[now]) {
        const auto tmp = dfs2(e, now, rank + 1);
        chmin(mi, tmp);
        chmax(ma, tmp);
    }
    if (rank % 2 == 0 && G[now].size()) {
        const auto sub = mi - s[now];
        s[now] = mi;
        a[now] += sub;
        FORE(e, G[now]) {
            a[e] -= sub;
        }
    }
    return s[now];
}

int main(void) {
    scanf("%d", &N);
    REP(i, N - 1) {
        int p;
        scanf("%d", &p);
        G[p - 1].EB(i + 1);
    }
    REP(i, N) {
        scanf("%lld", s + i);
    }
    a[0] = s[0];
    FORE(e, G[0]) {
        dfs(e, 0);
    }
    if (!valid) {
        puts("-1");
        return 0;
    }
    FORE(e, G[0]) {
        dfs2(e, 0, 2);
    }
    LL ans = 0;
    REP(i, N) {
        //DEBUG(a[i])
        ans += a[i];
    }
    printf("%lld\n", ans);
}
