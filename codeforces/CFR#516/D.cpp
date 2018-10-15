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

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

const int MAX = 2222;
int N, M;
int R, C;
int X, Y;
char s[MAX][MAX];
int ok[MAX][MAX];

bool possible(int arg_x, int arg_y) {
    return 0 <= arg_x && arg_x < N
        && 0 <= arg_y&& arg_y < M
        && s[arg_x][arg_y] == '.';
}

int main(void) {
    scanf("%d%d", &N, &M);
    scanf("%d%d", &R, &C);
    R--; C--;
    scanf("%d%d", &X, &Y);
    REP(i, N) {
        scanf("%s", s[i]);
    }

    REP(i, MAX) {
        REP(j, MAX) {
            ok[i][j] = MOD;
        }
    }

    deque<PII> que;
    if (s[R][C] == '.') {
        que.emplace_front(R, C);
        ok[R][C] = 0;
    }

    while (!que.empty()) {
        int rr, cc;
        tie(rr, cc) = que.front();
        que.pop_front();
        REP(d, 4) {
            int nr = rr + dx[d];
            int nc = cc + dy[d];
            if (!possible(nr, nc)) {
                continue;
            }
            if (d == 2) {
                if (chmin(ok[nr][nc], ok[rr][cc] + 1)) {
                    que.emplace_back(nr, nc);
                }
            } else {
                if (chmin(ok[nr][nc], ok[rr][cc])) {
                    que.emplace_front(nr, nc);
                }
            }
        }
    }

    int ans = 0;
    REP(i, N) {
        REP(j, M) {
            if (s[i][j] == '.') {
                int left = ok[i][j];
                int right = j - C + left;
                if (left <= X && right <= Y) {
                    ans++;
                    s[i][j] = 'A';
                }
            }
        }
    }
    //REP(i,N) cerr << s[i] << endl;
    cout << ans << endl;
}
