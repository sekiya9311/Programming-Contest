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

struct interval {
    int begin, end;
    int index;
};

const int MAX = 24 * 60 + 10;
void solve(int testNum) {
    stringstream ss;

    int N;
    scanf("%d", &N);
    VT<interval> se(N);
    REP(i, N) {
        int s, e;
        scanf("%d%d", &s, &e);
        se[i] = {s, e, i};
    }

    sort(begin(se), end(se), [](const auto &l, const auto &r) {
        return (l.end == r.end
            ? l.begin < r.begin
            : l.end < r.end);
    });

    VVI dp(N + 1, VI(MAX, INF));
    dp[0][0] = 0;
    REP(i, N) {
        const auto cur = se[i];
        RREP(j, MAX) if (dp[i][j] < INF) {
            if (dp[i][j] <= cur.begin) {
                chmin(dp[i + 1][j], cur.end);
            }
            if (j <= cur.begin) {
                chmin(dp[i + 1][cur.end], dp[i][j]);
            }
        }
    }

    string ans = "";
    REP(tmp, MAX) {
        if (dp[N][tmp] == INF) continue;

        ans = string(N, ' ');
        int cur = tmp;
        RREP(i, N) {
            if (dp[i][cur] <= se[i].begin) {
                ans[se[i].index] = 'C';
                continue;
            }

            ans[se[i].index] = 'J';
            while (dp[i][cur] == INF || cur > se[i].begin) {
                cur--;
            }
        }

        // DEBUG(cur)
        break;
    }

    if (ans.empty()) {
        ss << "IMPOSSIBLE";
    } else {
        ss << ans;
    }

    cout << "Case #" << testNum << ": " << ss.str() << endl;
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
        // cerr << "Case #" << testNum << ": solved" << endl;
    }
}
