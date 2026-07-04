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
#define GREATER(T) T, VT<T>, greater<T>

const LL MOD = 998244353;
const int MAX = 555;
LL dp[MAX][3][2][1 << 10][2]; // [idx][mod 3][contains 3][used digit][less than N]

void solve() {
    string N;
    cin >> N;
    dp[0][0][0][0][0] = 1;
    for (int i = 0; i < N.size(); i++) {
        const auto D = N[i] - '0';
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < (1 << 10); l++) {
                    for (int m = 0; m < 2; m++) {
                        if (dp[i][j][k][l][m] == 0) continue;
                        for (int d = 0; d < (m ? 10 : D + 1); d++) {

                            int used;
                            if (l == 0 && d == 0) {
                                // used zero only
                                used = 0;
                            } else {
                                used = l | (1 << d);
                            }

                            (dp[i + 1][(j + d) % 3][k || (d == 3)][used][m || (d < D)] += dp[i][j][k][l][m]) %= MOD;
                        }
                    }
                }
            }
        }
    }

    LL ans = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 2; k++) {
            for (int l = 0; l < (1 << 10); l++) {
                if (l == 0) continue;
                for (int m = 0; m < 2; m++) {
                    if (dp[N.size()][j][k][l][m] == 0) continue;
                    int ok_cnt = 0;
                    if (j % 3 == 0) ok_cnt++;
                    if (k) ok_cnt++;
                    if (__builtin_popcount(l) == 3) ok_cnt++;
                    if (ok_cnt == 1) {
                        (ans += (dp[N.size()][j][k][l][m])) %= MOD;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
