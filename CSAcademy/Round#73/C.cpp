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

const int MAX_RANK = 40;
const int MAX = 1e5 + 10;
void dfs(int now, int rank, VI graph[MAX], int cnts[MAX]) {
    FORE(e, graph[now]) dfs(e, rank + 1, graph, cnts);
    cnts[rank]++;
}

VI G[MAX], G2[MAX];
int cnt[MAX], cnt2[MAX];

int solve(int pNum) {
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    REP(i, MAX) {
        G[i].clear();
        G2[i].clear();
    }
    int p1 = -1, p2 = -1;
    int n;
    scanf("%d", &n);
    REP(i, n) {
        int a;
        scanf("%d", &a);
        if (a) {
            G[a - 1].EB(i);
        } else {
            p1 = i;
        }
    }
    dfs(p1, 0, G, cnt);
    REP(i, n) {
        int a;
        scanf("%d", &a);
        if (a) {
            G2[a - 1].EB(i);
        } else {
            p2 = i;
        }
    }
    dfs(p2, 0, G2, cnt2);
    REP(i, MAX) if (cnt[i] != cnt2[i]) return 0;
    return 1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    REP(i, t) {
        printf("%d\n", solve(i + 1));
    }
}
