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

const int MAX = 1e5 + 10;
int N, Q;
LL A[MAX];
LL X[MAX];
LL sum[MAX], odd_sum[MAX], even_sum[MAX];

// [...青木,高橋,青木,高橋][青木][高橋]

LL calc(LL x) {
    int low = N / 2, high = N;
    while (high - low > 1) {
        const int mid = (high + low) / 2;
        const int turn = N - mid + 1; // かかったターン
        const int takahashi_left = mid;
        const int takahashi_right = N - 1;// [l, r]
        {
            const int aoki_left = mid - turn;
            const int aoki_right = mid - 1;
            if (x < A[aoki_left]) {
                high = mid;
            } else if (A[aoki_left] <= x && x <= A[aoki_right]) {
                if (abs(A[aoki_left] - x) <= abs(A[aoki_right] - x)) {
                    high = mid;
                } else {
                    low = mid;
                }
            } else {
                low = mid;
            }
        }
    }

    const int turn = N - low + 1;
    const int takahashi_left = low;
    const int takahashi_right = N - 1;
    const int aoki_left = low - turn;
    const int aoki_right = low - 1;

    LL ans = sum[N] - sum[takahashi_left];
    // DEBUG(turn)
    // DEBUG(takahashi_left)
    // DEBUG(aoki_left)
    if (N % 2) {
        ans += even_sum[aoki_left + 1];
    } else {
        ans += odd_sum[aoki_left + 1];
    }
    return ans;
}

int main(void) {
    cin >> N >> Q;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    REP(i, N) {
        sum[i + 1] = A[i] + sum[i];
        if (i % 2 == 0) {
            even_sum[i + 1] = A[i];
        } else {
            odd_sum[i + 1] = A[i];
        }
        even_sum[i + 1] += even_sum[i];
        odd_sum[i + 1] += odd_sum[i];
    }
    REP(i, Q) {
        cin >> X[i];
    }
    REP(i, Q) {
        printf("%lld\n", calc(X[i]));
    }
}
