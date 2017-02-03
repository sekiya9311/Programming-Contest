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
int N;
VI graph[MAX];
int C[MAX];

int rootpre;

int dfs(int now, int prev) {
    const int nowColor = C[now];
    int nextColor = -1;
    bool ng = false;
    FORE(e, graph[now]) if (e != prev) {
        const int buf = dfs(e, now);
        if (buf != -1) {
            return buf;
        } else {
            if (nextColor == -1) nextColor = C[e];
            else if (nowColor != C[e]) {
                ng = true;
            }
        }
    }
    if (ng || (nextColor != -1 && nowColor != nextColor)) {
        rootpre = prev;
        return now;
    } else return -1;
}

int main(void) {
    scanf("%d", &N);
    REP(i, N - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        graph[u].EB(v);
        graph[v].EB(u);
    }
    REP(i, N) scanf("%d", C + i);
    int root = 0;
    root = dfs(root, -1);
    //DEBUG(root)
    if (root == -1) {
        root = 0;
    } else {
        const int buf = dfs(root, rootpre);
        const int buf2 = dfs(rootpre, root);
        //DEBUG(buf)DEBUG(buf2)
        if (!((buf == -1 || buf == root) && buf2 == -1)) {
            root = -1;
        }
    }
    if (root == -1) {
        puts("NO");
    } else {
        puts("YES");
        printf("%d\n", root + 1);
    }
}
