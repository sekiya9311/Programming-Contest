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

const int dx4[] = {0, 0, -1, 1};
const int dy4[] = {1, -1, 0, 0};
const int MAX = 333;
int H, W, K;
string S[MAX];
int ans[MAX][MAX];

bool valid(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

int main(void) {
    cin >> H >> W >> K;
    REP(i, H) {
        cin >> S[i];
    }

    memset(ans, -1, sizeof(ans));
    {
        int cnt = 0;
        REP(i, H) {
            REP(j, W) {
                if (S[i][j] == '#') {
                    ans[i][j] = ++cnt;
                    RREP(jj, j) {
                        if (ans[i][jj] == -1 && S[i][jj] == '.') {
                            ans[i][jj]= cnt;
                        } else break;
                    }
                    FOR(jj, j + 1, W) {
                        if (ans[i][jj] == -1 && S[i][jj] == '.') {
                            ans[i][jj]= cnt;
                        } else break;
                    }
                }
            }
        }
    }

    // REP(i, H) {
    //     REP(j, W) {
    //         cout << ans[i][j] << (j + 1 == W ? '\n' : ' ');
    //     }
    // }

    queue<int> que;
    REP(i, H) if (ans[i][0] != -1) {
        que.emplace(i);
    }
    while (!que.empty()) {
        const auto cur_i = que.front();
        que.pop();

        if (cur_i - 1 >= 0 && ans[cur_i - 1][0] == -1) {
            REP(j, W) {
                ans[cur_i - 1][j] = ans[cur_i][j];
            }
            que.emplace(cur_i - 1);
        }
        if (cur_i + 1 < H && ans[cur_i + 1][0] == -1) {
            REP(j, W) {
                ans[cur_i + 1][j] = ans[cur_i][j];
            }
            que.emplace(cur_i + 1);
        }
    }

    REP(i, H) {
        REP(j, W) {
            cout << ans[i][j] << (j + 1 == W ? '\n' : ' ');
        }
    }
}
