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

// 1. 売る→高橋くんは番号の小さいものから一個ずつしか売れない．売るたびに青木くんは一つ販売を停止
// 2. 買う→買えるものを好きなだけ買える

const int MAX = 20;
int N;
LL getTakahashi[MAX][1 << MAX]; // [i][j] := i個まで売って，集合jのときに得られる最大価値
LL ans[1 << MAX];
LL x[MAX], c[MAX], v[MAX];

int main(void) {

    {
        REP(i, MAX) REP(j, (1 << MAX)) getTakahashi[i][j] = -LLINF;
        REP(i, (1 << MAX)) ans[i] = LLINF;
        ans[0] = 0;
    }

    scanf("%d", &N);
    REP(i, N) scanf("%lld", x + i + 1);
    REP(i, N) scanf("%lld", c + i);
    REP(i, N) scanf("%lld", v + i);

    REP(i, N + 1) x[i + 1] += x[i];

    REP(i, N) {
        REP(j, (1 << N)) {
            LL cost = 0, sumv = 0;
            REP(k, N) {
                if (j & (1 << k)) {
                    cost += c[k];
                    sumv += v[k];
                }
            }
            if (cost <= x[i]) {
                getTakahashi[i][j] = sumv;
            }
        }
    }

    REP(i, N) {
         REP(j, (1 << N)) {
             REP(k, N) {
                 chmax(getTakahashi[i][j | (1 << k)], getTakahashi[i][j]);
             }
         }
    }

    REP(i, (1 << N)) {
        const int bit = N - __builtin_popcount(i);
        chmax(ans[i], getTakahashi[bit][i]);
        REP(j, N) {
            if ((i & (1 << j)) == 0) {
                chmin(ans[i | (1 << j)], ans[i]);
            }
        }
    }
    cout << ans[(1 << N) - 1] << endl;
}
