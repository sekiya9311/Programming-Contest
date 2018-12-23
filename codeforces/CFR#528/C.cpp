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

int x[3], y[3];

void go(set<PII> &ret, int x, int y, int p_x, int p_y) {
    while (p_x != x || p_y != y) {
        if (p_x < x) ret.emplace(p_x++, p_y);
        else if (p_x > x) ret.emplace(p_x--, p_y);
        else if (p_y < y) ret.emplace(p_x, p_y++);
        else ret.emplace(p_x, p_y--);
    }
}

set<PII> calc(int a, int b) {
    set<PII> ret;
    const int sub = (b + 1) % 3;
    int mi = INF;
    int p_x, p_y;
    REP(i, 1111) {
        REP(j, 1111) {
            if (min(x[a], x[b]) <= i && i <= max(x[a], x[b]) && min(y[a], y[b]) <= j && j <= max(y[a], y[b])) {
                if (chmin(mi, abs(i - x[sub]) + abs(j - y[sub]))) {
                    p_x = i;
                    p_y = j;
                }
            }
        }
    }
    REP(i, 3) ret.emplace(x[i], y[i]);
    if (!(p_x == x[a] && p_y == y[a]) || (p_x == x[b] && p_y == y[b])) {
        ret.emplace(p_x, p_y);
    }
    go(ret, x[sub], y[sub], p_x, p_y);
    if (!(p_x == x[a] && p_y == y[a]) || (p_x == x[b] && p_y == y[b])) {
        ret.emplace(p_x, p_y);
    }
    go(ret, x[a], y[a], x[b], y[b]);
    return ret;
}

int main(void) {
    REP(i, 3) {
        cin >> x[i] >> y[i];
    }
    set<PII> ans;
    REP(i, 3) {
        auto foo = calc(i, (i + 1) % 3);
        if (ans.size() == 0 || foo.size() < ans.size()) {
            ans = foo;
        }
    }
    printf("%d\n", (int)ans.size());
    FORE(e, ans) {
        printf("%d %d\n", e.first, e.second);
    }
}
