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
int N;
int takahashi, aoki;
VI G[MAX];

VI calc_dist(int cur) {
    VI dist(N, -1);
    queue<PII> que;
    que.emplace(cur, 0);
    while (!que.empty()) {
        const auto cur = que.front();
        que.pop();
        dist[cur.first] = cur.second;
        FORE(e, G[cur.first]) if (dist[e] == -1) {
            que.emplace(e, cur.second + 1);
        }
    }
    return dist;
}


int main(void) {
    cin >> N;
    cin >> takahashi >> aoki;
    takahashi--; aoki--;
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].EB(b);
        G[b].EB(a);
    }

    int ans = 0;
    const auto t_t = calc_dist(takahashi);
    const auto t_a = calc_dist(aoki);
    REP(i, N) {
        if (G[i].size() > 1) {
            continue;
        }
        if (t_t[i] <= t_a[i]) {
            chmax(ans, t_a[i] - 1);
        }
    }
    cout << ans << endl;
}
