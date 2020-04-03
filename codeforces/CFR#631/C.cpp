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
int N, M;
int l[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, M) {
        scanf("%d", l + i);
    }

    LL sum = 0;
    REP(i, M) {
        sum += l[i];
    }
    if (sum < N) {
        puts("-1");
        return 0;
    }

    {
        int cur = 0;
        REP(i, M) {
            if (cur + l[i] > N) {
                puts("-1");
                return 0;
            }
            cur++;
        }
    }

    LL need_m = sum - N;
    VI ans(M);
    REP(i, M) {
        if (i == 0) {
            ans[i] = 1;
        } else {
            int tmp = ans[i - 1] + l[i - 1];
            // 最大 l[i - 1]-1 引ける
            if (need_m >= l[i - 1] - 1) {
                need_m -= l[i - 1] - 1;
                ans[i] = ans[i - 1] + 1;
            } else {
                ans[i] = tmp - need_m;
                need_m = 0;
            }
        }
    }
    if (need_m > 0) {
        puts("-1");
        return 0;
    }
    assert(need_m == 0);

    REP(i, M) {
        printf("%d%c", ans[i], (i + 1 == M ? '\n' : ' '));
    }
}
