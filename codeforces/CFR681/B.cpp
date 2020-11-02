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

const int MAX = 1e5 + 10;
string next() {
    static char strbuf[MAX];
    scanf("%s", strbuf);
    return strbuf;
}

void solve2() {
    int a, b;
    scanf("%d%d", &a, &b);
    const auto S = next();

    VI v;
    {
        int cur = S[0] == '1' ? 1 : -1;
        FOR(i, 1, S.size()) {
            if (cur > 0 && S[i] == '1') {
                cur++;
            } else if (cur < 0 && S[i] == '0') {
                cur--;
            } else {
                v.EB(cur);
                cur = S[i] == '1' ? 1 : -1;
            }
        }
        v.EB(cur);
    }

    {
        bool f = false;
        FORE(e, v) if (e > 0) {
            f = true;
        }
        if (!f) {
            puts("0");
            return;
        }
    }

    if (v.front() < 0) {
        v.erase(begin(v));
    }
    if (v.back() < 0) {
        v.pop_back();
    }

    LL ans = 0;
    FORE(e, v) if (e > 0) {
        ans += a;
    }

    FORE(e, v) if (e < 0) {
        const auto tmp = e * -1 * b;
        if (ans - a + tmp < ans) {
            ans = ans - a + tmp;
        }
    }

    printf("%lld\n", ans);
}

void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {
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
