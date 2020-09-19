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

LL N;
int X, M;

void naive() {
    LL A = X;
    LL ans = A;
    FOR(i, 2, N + 1) {
        A = (A * A) % M;
        ans += A;
    }
    cout << ans << endl;
}

void solve() {
    cin >> N >> X >> M;

    LL loop_cur = -1;
    LL loop_sum = -1;
    int loop_l = -1, loop_r = -1;
    map<LL, pair<int, LL>> vis;
    LL A = X;
    LL ans = A;
    vis[X] = {1, X};
    FOR(i, 2, N + 1) {
        const auto cur = (A * A) % M;
        if (vis.count(cur)) {
            loop_l = vis[cur].first;
            loop_r = i;
            loop_sum = ans + cur - vis[cur].second;
            loop_cur = cur;
            break;
        }
        vis[cur] = {i, ans + cur};
        A = cur;
        ans += A;
    }

    if (loop_l > -1) {
        const auto nokori = N - loop_r;
        const auto matomeru = nokori / (loop_r - loop_l);
        const auto saigo = loop_r + matomeru * (loop_r - loop_l);

        ans += loop_sum * matomeru;

        A = loop_cur;
        ans += A;
        for (LL i = saigo; i < N; i++) {
            const auto cur = (A * A) % M;
            A = cur;
            ans += A;
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
