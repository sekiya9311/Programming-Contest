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
vector<int> G[MAX];
int cnt[2];

bool is_bipartite_graph(std::vector<int> checkGraph[], int size, int now = 0, int prev = -1, int c = 0) {
    static int color[MAX];      // must declare {const int MAX;}
    static bool isFirst = true;
    if (isFirst) {
        memset(color, -1, sizeof(color));
        isFirst = false;
    }
    if (color[now] == -1) {

        cnt[c]++;

        color[now] = c;

        bool ret = true;
        for (int e : checkGraph[now]) {
            if (e != prev) {
                ret &= is_bipartite_graph(checkGraph, size, e, now, c ^ 1);
            }
        }
        return ret;
    } else {
        return color[now] == c;
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
    if (is_bipartite_graph(G, n)) {
        cout << 1ll * cnt[0] * cnt[1] - m << endl;
    } else {
        cout << 1ll * n * (n - 1) / 2 - m << endl;
    }
}
