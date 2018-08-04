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

const int MAX = 2e3 + 10;
int N, M;
string S[MAX];

LL left_sum[MAX][MAX], right_sum[MAX][MAX], up_sum[MAX][MAX], down_sum[MAX][MAX];

int main(void) {
    cin >> N >> M;
    REP(i, N) cin >> S[i];

    {
        REP(i, N) {
            REP(j, M) {
                if (S[i][j] == '.') {
                    left_sum[i][j] = 1;
                    if (i) left_sum[i][j] += left_sum[i - 1][j];
                }
            }
        }
        RREP(i, N) {
            REP(j, M) {
                if (S[i][j] == '.') {
                    right_sum[i][j] = 1;
                    if (i != N - 1) right_sum[i][j] += right_sum[i + 1][j];
                }
            }
        }
        REP(i, N) {
            REP(j, M) {
                if (S[i][j] == '.') {
                    up_sum[i][j] = 1;
                    if (j) up_sum[i][j] += up_sum[i][j - 1];
                }
            }
        }
        REP(i, N) {
            RREP(j, M) {
                if (S[i][j] == '.') {
                    down_sum[i][j] = 1;
                    if (j != M - 1) down_sum[i][j] += down_sum[i][j + 1];
                }
            }
        }
    }

    LL ans = 0;
    {
        REP(i, N) {
            REP(j, M) {
                if (S[i][j] == '.') {
                    ans += (right_sum[i][j] - 1) * (down_sum[i][j] - 1);
                    ans += (down_sum[i][j] - 1) * (left_sum[i][j] - 1);
                    ans += (left_sum[i][j] - 1) * (up_sum[i][j] - 1);
                    ans += (up_sum[i][j] - 1) * (right_sum[i][j] - 1);
                }
            }
        }
    }

    cout << ans << endl;
}
