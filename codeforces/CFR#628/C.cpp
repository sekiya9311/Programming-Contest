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
VI G[MAX];
int a[MAX], b[MAX];
map<PII, int> ans;

int val = 3;
void dfs(int cur, int par) {
    FORE(e, G[cur]) if (e != par) {
        ans[MP(min(cur, e), max(cur, e))] = val++;
        dfs(e, cur);
    }
}

int main(void) {
    scanf("%d", &N);
    REP(i, N - 1) {
        scanf("%d%d", a + i, b + i);
        a[i]--; b[i]--;
        G[a[i]].EB(b[i]);
        G[b[i]].EB(a[i]);
    }

    REP(i, N) if (G[i].size() >= 3) {
        int cnt = 0;
        FORE(nxt, G[i]) {
            if (cnt < 3) {
                ans[MP(min(i, nxt), max(i, nxt))] = cnt++;
            } else {
                ans[MP(min(i, nxt), max(i, nxt))] = val++;
            }
            dfs(nxt, i);
        }
        break;
    }

    if (ans.empty()) {
        REP(i, N - 1) {
            ans[MP(min(a[i], b[i]), max(a[i], b[i]))] = i;
        }
    }

    REP(i, N - 1) {
        printf("%d\n", ans[MP(min(a[i], b[i]), max(a[i], b[i]))]);
    }
}
