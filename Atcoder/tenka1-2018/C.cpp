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

int main(void) {
    int N;
    cin >> N;
    VL a(N);
    REP(i, N) cin >> a[i];
    SORT(a);
    deque<LL> dq;
    FOR(i, 1, N) dq.emplace_back(a[i]);
    LL left = a[0], right = a[0];
    bool f = false;
    LL ans = 0;
    REP(i, N - 1) {
        LL left_val = dq.front();
        LL right_val = dq.back();
        LL left_lval = llabs(left - left_val);
        LL left_rval = llabs(right - left_val);
        LL right_lval = llabs(left - right_val);
        LL right_rval = llabs(right - right_val);
        if (max(left_lval, left_rval) < max(right_lval, right_rval)) {
            dq.pop_back();
            if (right_lval < right_rval) {
                ans += right_rval;
                right = right_val;
            } else {
                ans += right_lval;
                left = right_val;
            }
        } else {
            dq.pop_front();
            if (left_lval < left_rval) {
                ans += left_rval;
                right = left_val;
            } else {
                ans += left_lval;
                left = left_val;
            }
        }
    }
    cout << ans << endl;
}
