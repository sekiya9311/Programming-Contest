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

const int MAX = 2222;
LL N, Z, W, a[MAX];

int main(void) {
    scanf("%lld%lld%lld", &N, &Z, &W);
    REP(i, N) {
        scanf("%lld", a + i);
    }
    // Z or W どちらかはa[N - 1]になる
    // Z = スコア最大化 = 自分大きい値取って相手小さい値取らせる = 自分小さい値取って相手大きい値取らせる !!どちらかはa[N - 1]
    // W = スコア最小化 = a[N - 1]に近い値取る or 相手にa[N - 1]に近い値取らせて自分a[N - 1]とる

    if (N >= 2 && llabs(a[N - 1] - a[N - 2]) < llabs(a[N - 1] - W)) {
        cout << llabs(a[N - 1] - W) << endl;
        return 0;
    }

    int f = -1;
    RREP(i, N - 1) {
        if (llabs(a[N - 1] - W) <= llabs(a[N - 1] - a[i])) {
            f = i;
            break;
        }
    }
    DEBUG(f)
    if (/*次Wがどう動いても  llabs(a[N - 1] - W) より大きいスコアが取れる */f != -1) {
        LL ans = llabs(a[N - 1] - W);
        FOR(i, f, N - 1) {
            chmax(ans, llabs(a[N - 1] - a[i]));
        }
        cout << ans << endl;
    } else {
        cout << llabs(a[N - 1] - W) << endl;
    }
}
