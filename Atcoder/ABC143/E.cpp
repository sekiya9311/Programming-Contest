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

const int MAX_N = 333;
const int MAX_M = MAX_N * MAX_N;

int N, M, L;
VPII G[MAX_N];
int gas_his[MAX_N];

int Q;
int s[MAX_M], t[MAX_M];

LL dist[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];

int main(void) {
    cin >> N >> M >> L;
    REP(i, N) REP(j, N) dist[i][j] = LLINF;
    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;

        if (c > L) continue;

        G[a].EB(b, c);
        G[b].EB(a, c);
        dist[a][b] = dist[b][a] = c;
    }

    REP(k, N) REP(i, N) REP(j, N) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    REP(i, N) REP(j, N) ans[i][j] = i == j ? 0 : INF;
    REP(i, N) REP(j, N) {
        if (dist[i][j] <= L) {
            ans[i][j] = 0;
        }
    }

    REP(k, N) REP(i, N) REP(j, N) {
        chmin(ans[i][j], ans[i][k] + ans[k][j] + 1);
    }

    cin >> Q;
    REP(i, Q) {
        cin >> s[i] >> t[i];
        s[i]--;t[i]--;
    }

    REP(i, Q) {
        if (ans[s[i]][t[i]] < INF) cout << ans[s[i]][t[i]] << endl;
        else cout << -1 << endl;
    }
}
