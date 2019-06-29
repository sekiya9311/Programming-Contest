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

const int MAX = 1e5 + 10;
int N, M;
VI G[MAX];
int S, T;
int ans[3][MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, M) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        G[u].EB(v);
    }
    scanf("%d%d", &S, &T);
    S--; T--;
    REP(i, 3) REP(j, MAX) ans[i][j] = INF;

    queue<PII> que;
    que.emplace(S, 0);
    ans[0][S] = 0;
    while (!que.empty()) {
        int cur, cost;
        tie(cur, cost) = que.front();
        que.pop();

        const int mod3 = cost % 3;

        const int nxt_mod3 = (mod3 + 1) % 3;
        const int nxt_cost = cost + 1;
        FORE(nxt, G[cur]) {
            if (ans[nxt_mod3][nxt] <= nxt_cost) continue;
            ans[nxt_mod3][nxt] = nxt_cost;
            que.emplace(nxt, nxt_cost);
        }
    }

    if (ans[0][T] == INF) cout << -1 << endl;
    else cout << ans[0][T] / 3 << endl;
}
