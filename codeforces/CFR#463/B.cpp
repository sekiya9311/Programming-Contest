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

const int MAX = 2e5 + 10;
const int MAX_V = 1e6 + 10;
int Q;
int L[MAX], R[MAX], K[MAX];

int memo[MAX_V];
int imos[MAX_V][10];

int dfs(int V) {
    if (memo[V] != -1) return memo[V];
    if (V < 10) {
        return memo[V] = V;
    } else {
        int nxt = 1;
        int v = V;
        while (v) {
            if (v % 10) nxt *= (v % 10);
            v /= 10;
        }
        return memo[V] = dfs(nxt);
    }
}

int main(void) {
    memset(memo, -1, sizeof(memo));
    scanf("%d", &Q);
    REP(i, Q) {
        scanf("%d%d%d", L + i, R + i, K + i);
    }
    REP(i, MAX_V) {
        dfs(i);
    }
    REP(i, MAX_V) {
        imos[i][memo[i]]++;
    }
    REP(i, MAX_V - 1) {
        REP(j, 10) {
            imos[i + 1][j] += imos[i][j];
        }
    }
    REP(i, Q) {
        printf("%d\n", imos[R[i]][K[i]] - imos[L[i] - 1][K[i]]);
    }
}
