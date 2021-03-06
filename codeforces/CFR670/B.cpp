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

void solve2() {
    int N;
    scanf("%d", &N);
    VL pos, neg, zero;
    REP(i, N) {
        LL a;
        scanf("%lld", &a);
        if (a> 0) pos.EB(a);
        else if (a < 0) neg.EB(-a);
        else zero.EB(a);
    }
    RSORT(pos);
    RSORT(neg);

    if (N - zero.size() < 5) {
        cout << 0 << endl;
        return;
    }

    LL ans = zero.size() ? 0 : -LLINF;
    REP(minus_cnt, 6) {
        const int plus_cnt = 5 - minus_cnt;
        if (pos.size() >= plus_cnt && neg.size() >= minus_cnt) {
            if (minus_cnt % 2 == 0) {
                // max !!
                LL tmp = 1;
                REP(i, plus_cnt) tmp *= pos[i];
                REP(i, minus_cnt) tmp *= neg[i];
                chmax(ans, tmp);
            } else {
                // min !!
                LL tmp = -1;
                REP(i, plus_cnt) tmp *= pos[(int)pos.size() - i - 1];
                REP(i, minus_cnt) {
                    tmp *= neg[(int)neg.size() - i - 1];
                }
                chmax(ans, tmp);
            }
        }
    }

    cout << ans << endl;
}

void solve() {
    int T;
    scanf("%d", &T);
    REP(_, T) {
        solve2();
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
