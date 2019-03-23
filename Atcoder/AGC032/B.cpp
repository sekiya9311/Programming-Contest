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

int N;
VI m_sum(111);
int con[111];
bool cut[111][111];

int main(void) {
    cin >> N;
    {
        int all_sum = N * (N + 1) / 2;
        REP(i, N) m_sum[i] = all_sum - (i + 1);
    }
    for(int i = -1; i < N; i++) {
        memset(cut, false, sizeof(cut));
        if (i > -1) {
            FOR(j, N - i, N) cut[j][N - 1] = cut[N - 1][j] = true;
            m_sum[N - 1] -= (i + 1);
            m_sum[i] -= N;
            cut[i][N - 1] = cut[N - 1][i] = true;
        }
        auto sum = m_sum;
        const int cur_sum = sum[N - 1];

        bool ok = true;
        RREP(j, N - 1) {

            while (sum[j] > cur_sum) {
                int mul;
                if (sum[j] - cur_sum < j + 1) {
                    mul = sum[j] - cur_sum;
                } else {
                    mul = j;
                }

                sum[j] -= mul;
                sum[mul - 1] -= j + 1;
                cut[j][mul - 1] = cut[mul - 1][j] = true;
            }

            if (sum[j] != cur_sum) {
                ok = false;
            }

        }
        if (ok) {
            VPII ans;
            REP(j, N) {
                FOR(k, j + 1, N) if (!cut[j][k]) {
                    ans.EB(j, k);
                }
            }
            cout << ans.size() << endl;
            FORE(e, ans) {
                cout << e.first + 1 << " " << e.second + 1 << endl;
            }
            return 0;
        }
    }
}
