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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

char rev(const char d) {
    if (d == 'N') return 'S';
    else if (d == 'S') return 'N';
    else if (d == 'E') return 'W';
    else return 'E';
}

void calc(LL &x, LL &y, char c, LL val) {
    if (c == 'N') y += val;
    else if (c == 'S') y -= val;
    else if (c == 'E') x += val;
    else x -= val;
}

bool check(const string &ans, const int X, const int Y) {
    LL cur_x = 0, cur_y = 0;
    REP(i, ans.length()) {
        const auto cur = 1LL << i;
        calc(cur_x, cur_y, ans[i], cur);
    }

    return X == cur_x && cur_y == Y;
}

void solve(stringstream &out) {
    int X, Y;
    cin >> X >> Y;

    const bool neg_x = X < 0;
    const bool neg_y = Y < 0;
    X = abs(X);
    Y = abs(Y);

    if (X % 2 == Y % 2) {
        out << "IMPOSSIBLE" << endl;
        return;
    }

    const LL sum = X + Y;
    int cnt = 0;
    {
        LL tmp = 0;
        while (tmp < sum) {
            tmp += 1LL << cnt++;
        }
    }
// DEBUG(cnt)
    LL cur_x = 0, cur_y = 0;
    string ans = "";
    REP(i, cnt) {
        // cerr << cur_x << " " << cur_y << endl;
        const auto cur = 1LL << i;
        if ((((1LL << cnt) - sum) >> 1) & cur) {
            // neg
            const bool is_x = (((cur_x) ^ X) & cur);
            const bool is_y = (((cur_y) ^ Y) & cur);
            if (is_x == is_y) {
                out << "IMPOSSIBLE" << endl;
                return;
            }
            if (is_x) {
                cur_x -= cur;
                ans += 'W';
            }
            if (is_y) {
                cur_y -= cur;
                ans += 'S';
            }

        } else {
            // pos
            const bool is_x = (((cur_x) ^ X) & cur);
            const bool is_y = (((cur_y) ^ Y) & cur);
            if (is_x == is_y) {
                out << "IMPOSSIBLE" << endl;
                return;
            }
            if (is_x) {
                cur_x += cur;
                ans += 'E';
            }
            if (is_y) {
                cur_y += cur;
                ans += 'N';
            }
        }
    }

// DEBUG(ans)
//
//     DEBUG(cur_x)
//     DEBUG(cur_y)

    assert(check(ans, X, Y));

    REP(i, ans.length()) {
        if ((ans[i] == 'N' || ans[i] == 'S') && neg_y) {
            ans[i] = ans[i] == 'N' ? 'S' : 'N';
        }
        if ((ans[i] == 'E' || ans[i] == 'W') && neg_x) {
            ans[i] = ans[i] == 'E' ? 'W' : 'E';
        }
    }

    out << ans << endl;
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }

    int problem_count;
    scanf("%d", &problem_count);
    //string s;getline(cin, s);
    for (int test_no = 1; test_no <= problem_count; test_no++) {
        stringstream out;
        solve(out);
        printf("Case #%d: %s", test_no, out.str().c_str());
        // cerr << "Case #" << test_no << ": solved" << endl;
    }
}
