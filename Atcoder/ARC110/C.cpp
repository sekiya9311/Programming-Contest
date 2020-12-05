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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 2e5 + 10;
int N;
int P[MAX];
VI ans;

void solve() {
    cin >> N;
    REP(i, N) {
        cin >> P[i];
    }

    stack<tuple<int, int, bool>> stk;
    stk.emplace(0, N, true);
    while (!stk.empty()) {
        const auto [l, r, f] = stk.top();
        stk.pop();
        if (r - l == 1) continue;


        if (f) {
            int mi = INF;
            int ma = -INF;
            FOR(i, l, r - 1) {
                const auto cur_mi = min(mi, P[i + 1]);
                const auto cur_ma = max(ma, P[i + 1]);
                if (cur_mi == l + 1 && cur_ma == i + 1) {
                    ans.EB(i);
                    swap(P[i], P[i + 1]);
                    stk.emplace(l, i + 1, false);
                    stk.emplace(i + 1, r, true);
                    break;
                }
                mi = min(mi, P[i]);
                ma = max(ma, P[i]);
            }
        } else {
            int mi = INF;
            int ma = -INF;
            for (int i = r - 1; i > l; i--) {
                const auto cur_mi = min(mi, P[i - 1]);
                const auto cur_ma = max(ma, P[i - 1]);
                if (cur_mi == i + 1 && cur_ma == r) {
                    ans.EB(i - 1);
                    swap(P[i - 1], P[i]);
                    stk.emplace(l, i, false);
                    stk.emplace(i, r, true);
                    break;
                }
                mi = min(mi, P[i]);
                ma = max(ma, P[i]);
            }

        }
    }

    if (!is_sorted(P, P + N) || ans.size() != N - 1) {
        puts("-1");
        return;
    }

    FORE(e, ans) {
        printf("%d\n", e + 1);
    }
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
