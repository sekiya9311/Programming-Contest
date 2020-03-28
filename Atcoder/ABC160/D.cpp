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

const int MAX = 2e3 + 10;
int dist[MAX][MAX];
LL N, X, Y;
VI G[MAX];

void calc(int root) {
    dist[root][root] = 0;
    queue<PII> que;

    que.emplace(root, 0);
    while (!que.empty()) {
        const auto cur = que.front();
        que.pop();
        FORE(e, G[cur.first]) if (dist[root][e] == INF) {
            dist[root][e] = cur.second + 1;
            que.emplace(e, cur.second + 1);
        }
    }
}

int main(void) {
    cin >> N >> X >> Y;
    X--; Y--;

    REP(i, N - 1) {
        G[i].EB(i + 1);
        G[i + 1].EB(i);
    }
    G[X].EB(Y);
    G[Y].EB(X);

    REP(i, MAX) REP(j, MAX) {
        dist[i][j] = INF;
    }

    REP(i, N) {
        calc(i);
    }

    VI ans(N - 1);
    REP(i, N) {
        FOR(j, i + 1, N) {
            ans[dist[i][j] - 1]++;
        }
    }

    REP(i, N - 1) {
        cout << ans[i] << endl;
    }
}
