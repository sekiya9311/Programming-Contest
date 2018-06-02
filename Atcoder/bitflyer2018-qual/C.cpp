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
LL D, X[MAX];
LL lim[MAX];// lim[i] = [i, lim[i])が徒歩
LL d_sum[MAX];// D以下の区間の個数の累積和
LL ov_d_sum[MAX];//Dより長い区間の個数の累積和

// a = i, lim[i] <= c

int main(void) {
    cin >> N >> D;
    REP(i, N) cin >> X[i];
    LL ans = 0;
    REP(i, N) {
        int low = i, high = N;
        while (high - low > 1) {
            const int mid = (high + low) / 2;
            if (X[mid] - X[i] <= D) {
                low = mid;
            } else {
                high = mid;
            }
        }
        lim[i] = high;
    }
    REP(i, N) {
        d_sum[i + 1] = d_sum[i] + (lim[i] - i - 1);
        ov_d_sum[i + 1] = ov_d_sum[i] + (N - (lim[i] - i) - i);
    }
    FOR(i, 1, N - 1) {
        // b固定
        int low = -1, high = i;
        while (high - low > 1) {
            const int mid = (high + low) / 2;
            if (X[i] - X[mid] <= D) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cerr << high << " " << i << endl;
        DEBUG(ov_d_sum[i] - ov_d_sum[high] - (N - (lim[i] - i) - i) * (i - high))
        ans += ov_d_sum[i] - ov_d_sum[high] - (N - (lim[i] - i) - i) * (i - high);
        //DEBUG(ans)
    }
    cout << ans << endl;
}
