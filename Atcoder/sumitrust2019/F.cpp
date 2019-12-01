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

const string INF_RES = "infinity";
LL T[2], A[2], B[2];

bool go(LL &takahashi, LL move_t, LL &aoki, LL move_a, const LL t) {
    const LL cur_t = takahashi;
    const LL cur_a = aoki;

    takahashi += move_t * t;
    aoki += move_a * t;

    if (cur_t == cur_a) return false;
    if (takahashi == aoki) return true;
    if ((cur_t < cur_a) ^ (takahashi < aoki)) return true;
    return false;
}

void naive() {
    int cnt = 0;
    LL takahashi = 0, aoki = 0;
    while (true) {
        int meet_cnt = 0;

        if(go(takahashi, A[0], aoki, B[0], T[0])) {
            meet_cnt++;
        }

        if (go(takahashi, A[1], aoki, B[1], T[1])) {
            meet_cnt++;
        }

        const LL mi = min(takahashi, aoki);
        takahashi -= mi;
        aoki -= mi;

        if (meet_cnt == 0) break;
        cnt += meet_cnt;
    }
    cout << cnt << endl;
}

int main(void) {
    REP(i, 2) {
        cin >> T[i];
    }
    REP(i, 2) {
        cin >> A[i];
    }
    REP(i, 2) {
        cin >> B[i];
    }

    if (T[0] * A[0] + T[1] * A[1] == T[0] * B[0] + T[1] * B[1]) {
        cout << INF_RES << endl;
        return 0;
    }
    if (!((A[0] > B[0]) ^ (A[1] > B[1]))) {
        cout << 0 << endl;
        return 0;
    }

    //naive();

    {
        LL t = 0, a = 0;
        bool f = go(t, A[0], a, B[0], T[0]);
        f |= go(t, A[1], a, B[1], T[1]);
        if (!f) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (T[0] * A[0] + T[1] * A[1] > T[0] * B[0] + T[1] * B[1]) {
        swap(A[0], B[0]);
        swap(A[1], B[1]);
    }

    // A <= B
    const LL all_diff = (T[0] * B[0] + T[1] * B[1]) - (T[0] * A[0] + T[1] * A[1]);
    const LL zero_diff = T[0] * A[0] - T[0] * B[0];

    // all_diff * x > zero_diff
    // x > zero_diff / all_diff

    const LL ans = (zero_diff / all_diff * 2) + (zero_diff % all_diff != 0);
    DEBUG(zero_diff)
    DEBUG(all_diff)
    DEBUG(zero_diff % all_diff)
    cout << ans << endl;
}
