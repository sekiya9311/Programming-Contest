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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

const int H = 100;
const int W = 100;
const char black = '#';
const char white = '.';
char ans[H][W];
int A, B;

bool inside(int h, int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int main(void) {
    cin >> A >> B;
    if (B == 0) {
        REP(i, H) {
            REP(j, W) {
                ans[i][j] = white;
            }
        }
    } else if (A == 0) {
        REP(i, H) {
            REP(j, W) {
                ans[i][j] = black;
            }
        }
    } else {
        {
            int tmpCnt = 0;
            REP(i, H) {
                REP(j, W) {
                    if (tmpCnt < H * W / 2) ans[i][j] = black;
                    else ans[i][j] = white;
                    tmpCnt++;
                }
            }
        }
        {//white
            int tmpCnt = 1;
            for (int i = 0; i < H / 2 && tmpCnt < A; i += 2) {
                for (int j = 0; j < W && tmpCnt < A; j += 2) {
                    ans[i][j] = white;
                    tmpCnt++;
                }
            }
        }
        {//black
            int tmpCnt = 1;
            for (int i = H / 2 + 1; i < H && tmpCnt < B; i += 2) {
                for (int j = 0; j < W && tmpCnt < B; j += 2) {
                    ans[i][j] = black;
                    tmpCnt++;
                }
            }
        }
    }
    cout << H << " " << W << endl;
    REP(i, H) {
        REP(j, W) cout << ans[i][j];
        cout << endl;
    }
}
