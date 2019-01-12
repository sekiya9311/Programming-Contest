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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

// 素因数分解
// O(√N * std::map)
//res[i] = n : iがn個
std::map<long long, int> prime_factor_decomposition(long long N) {
    std::map<long long, int> res;
    for (long long i = 2; i * i <= N; i++) {
        int cnt = 0;
        while(N % i == 0) {
            cnt++;
            N /= i;
        }
        if (cnt) {
            res[i] = cnt;
        }
    }
    if (N != 1) {
        res[N] = 1;
    }
    return res;
}

const int MAX = 2e5 + 10;
int N;
int a[MAX];
VI a_p[MAX];
VI G[MAX];
map<int, int> dp[MAX];
int ans;

void dfs(int now, int prev) {
    FORE(e, G[now]) if (e != prev) {
        dfs(e, now);
    }
    FORE(p, a_p[now]) {
        int top = 0, second = 0;
        FORE(e, G[now]) if (e != prev && dp[e].count(p)) {
            const int val = dp[e][p];
            if (val > top) {
                second = top;
                top = val;
            } else if (val > second) {
                second = val;
            }
        }
        dp[now][p] = top + 1;
        chmax(ans, top + second + 1);
    }
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", a + i);
        auto tmp = prime_factor_decomposition(a[i]);
        FORE(e, tmp) if (e.first > 1) {
            a_p[i].EB((int)e.first);
        }
    }
    REP(i, N - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;y--;
        G[x].EB(y);
        G[y].EB(x);
    }
    if (count_if(a, a + N, [](int i){return i != 1;}) == 0) {
        cout << 0 << endl;
        return 0;
    }
    ans = 1;
    dfs(0, -1);
    cout << ans <<endl;
}
