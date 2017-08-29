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
int n, m;
VI G[MAX];
int C[MAX];
int ans[3];

void out(int a, int b, int c) {
    cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    exit(0);
}

void dfs(int now, int cost) {
    C[now] = cost;
    if (cost % (n / 3) == 0) {
        ans[cost / (n / 3)] = now;
    }
    FORE(e, G[now]) {
        if (C[e] == -1) {
            dfs(e, cost + 1);
        }
    }
}

int main(void) {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        G[a].EB(b);
        G[b].EB(a);
    }
    bool one = false;
    REP(i, n) {
        if (G[i].size() >= 3) {
            const int a = G[i][0];
            const int b = G[i][1];
            const int c = G[i][2];
            for (int e : G[a]) if (e == b) {
                out(a, b, i);
            }
            for (int e : G[b]) if (e == c) {
                out(b, c, i);
            }
            for (int e : G[c]) if (e == a) {
                out(i, c, a);
            }
            out(a, b, c);
        } else if (G[i].size() <= 1) {
            one = true;
        }
    }
    if (one) {
        cout << -1 << endl;
        return 0;
    }
    memset(C, -1, sizeof(C));
    if (n == m && n % 3 == 0) {
        dfs(0, 0);
        out(ans[0], ans[1], ans[2]);
    }
    cout << -1 << endl;
}
