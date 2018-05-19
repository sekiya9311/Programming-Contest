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
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (int)(b); (i)++)
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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

void solve(int testNum) {
    int C;
    cin >> C;
    VI B(C);
    REP(i, C) cin >> B[i];
    string ans = "";
    VT<string> grid(10000, string(C, '.'));
    VI need(C);
    if (B[0] == 0 || B.back() == 0) {
        ans = "IMPOSSIBLE";
    } else {
        int now = 0;
        REP(i, C) {
            if (B[i]) {
                REP(j, B[i]) {
                    need[now + j] = i;
                }
                now += B[i];
            }
        }
        assert(now == C);
        REP(i, C) {
            if (need[i] < i) {
                REP(j, i - need[i]) {
                    grid[j][i - j] = '/';
                }
            } else {
                REP(j, need[i] - i) {
                    grid[j][i + j] = '\\';
                }
            }
        }
        while (grid.size() && grid.back() == string(C, '.')) {
            grid.pop_back();
        }
        grid.EB(string(C, '.'));
        REP(i, grid.size()) if (grid[i][0] != '.') ans = "IMPOSSIBLE";
        REP(i, grid.size()) if (grid[i][C - 1] != '.') ans = "IMPOSSIBLE";
        REP(i, C) if (grid.back()[i] != '.') ans = "IMPOSSIBLE";
        REP(i, grid.size()) {
            REP(j, grid[i].size() - 1) {
                if (grid[i][j] == '\\' && grid[i][j + 1] == '/') {
                    ans = "IMPOSSIBLE";
                }
            }
        }
        if (ans == "") {
            ans = to_string(grid.size());
        }
    }
    cout << "Case #" << testNum << ": " << ans << endl;
    if (ans[0] != 'I') {
        REP(i, grid.size()) {
            cout << grid[i] << endl;
        }
    }
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
