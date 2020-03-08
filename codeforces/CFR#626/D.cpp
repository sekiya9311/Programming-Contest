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

const int MAX = 400010;
int N;
int a[MAX];
int a_mod[MAX];

void naive() {
    int ans = 0;
    REP(i, N) {
        FOR(j, i + 1, N) {
            ans ^= a[i] + a[j];
        }
    }
    DEBUG(ans)
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", a + i);
    }

    int ans = 0;
    REP(bit, 30) {
        const int V = (1 << bit);
        REP(i, N) {
            a_mod[i] = a[i] % (V << 1);
        }
        sort(a_mod, a_mod + N);

        LL cur = 0;
        REP(i, N) {
            {
                // [V, 2V)
                const auto need_min = 1 * V - a_mod[i];
                const auto need_max = 2 * V - a_mod[i];

                const int mi = lower_bound(a_mod + i + 1, a_mod + N, need_min) - a_mod;
                const int ma = lower_bound(a_mod + i + 1, a_mod + N, need_max) - a_mod;
                cur += max(0, ma - mi);
            }
            {
                // [3V, 4V)
                const auto need_min = 3 * V - a_mod[i];
                const auto need_max = 4 * V - a_mod[i];

                const int mi = lower_bound(a_mod + i + 1, a_mod + N, need_min) - a_mod;
                const int ma = lower_bound(a_mod + i + 1, a_mod + N, need_max) - a_mod;
                cur += max(0, ma - mi);
            }
        }
// DEBUG(cur)
        if (cur % 2) {
            ans |= V;
        }
    }

    cout << ans << endl;
}
