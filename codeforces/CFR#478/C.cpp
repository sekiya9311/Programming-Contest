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

const int MAX = 200010;
int N, Q;
LL A[MAX], K[MAX];
LL a_sum[MAX];

int main(void) {
    scanf("%d%d", &N, &Q);
    REP(i, N) scanf("%lld", A + i);
    REP(i, Q) scanf("%lld", K + i);
    {
        REP(i, N) a_sum[i + 1] = a_sum[i] + A[i];
    }
    LL pre = 0;
    int now = 0;//最近倒れたやつ
    REP(i, Q) {
        //DEBUG(pre)
        if (pre + K[i] >= a_sum[N] - a_sum[now]) {
            printf("%d\n", N);
            now = 0;
            pre = 0;
        } else if (pre + K[i] < a_sum[now + 1]- a_sum[now]) {
            pre += K[i];
            printf("%d\n", N - now);
        } else {
            int low = now + 1, high = N;
            while (high - low > 1) {
                const int mid = low + (high - low) / 2;
                if (pre + K[i] < a_sum[mid] - a_sum[now]) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            pre = (pre + K[i]) - (a_sum[low] - a_sum[now]);
            now = low;
            printf("%d\n", N - low);
        }
    }
}
