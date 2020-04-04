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

int K;

bool is_runrun(LL v) {
    int cur = -1;
    while (v) {
        if (cur == -1) cur = v % 10;
        else {
            const auto tmp = v % 10;
            if (abs(cur - tmp) > 1) return false;
            cur = tmp;
        }
        v /= 10;
    }
    return true;
}

void naive() {
    int cur = 0;
    int cnt = 0;
    while (cnt < K) {
        cur++;
        if (is_runrun(cur)) {
            DEBUG(cur)
            cnt++;
        }
    }
    cout << cur << endl;
}

LL dp[11][10];

int main(void) {
    cin >> K;

    REP(i, 10) {
        dp[0][i] = 1;
    }
    FOR(i, 1, 11) {
        REP(d, 10) {
            // calc dp[i][d]
            FOR(e, -1, 2) {
                const int pre = d + e;
                if (0 <= pre && pre < 10) {
                    dp[i][d] += dp[i - 1][pre];
                }
            }
        }
    }

    LL sum = 0;
    REP(i, 11) FOR(j, 1, 10) {
        sum += dp[i][j];
    }
    const auto tmp = sum;

    int pre = 0;
    LL ans = 0;
    bool f = false;
    RREP(i, 11) {
        if (f) {
            FORR(j, pre + 2, pre - 1) {
                if (j < 0 || j >= 10) continue;
                if (sum - dp[i][j] >= K) {
                    sum -= dp[i][j];
                } else {
                    ans = ans * 10 + j;
                    pre = j;
                    break;
                }
            }
        } else {
            FORR(j, 10, 1) {
                if (sum - dp[i][j] >= K) {
                    sum -= dp[i][j];
                } else {
                    ans = ans * 10 + j;
                    pre = j;
                    f = true;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}
