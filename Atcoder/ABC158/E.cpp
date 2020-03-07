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

const int MAX = 2e5 + 10;
int N, P;
char S[MAX];

void naive() {
    LL ans = 0;
    unordered_map<LL, LL> dp;
    REP(i, N) {
        unordered_map<LL, LL> nxt;
        FORE(e, dp) {
            nxt[(e.first * 10 + (S[i] - '0')) % P] += e.second;
        }
        nxt[(S[i] - '0') % P]++;
        dp = nxt;

        if (dp.count(0)) {
            ans += dp[0];
        }
    }

    printf("%lld\n", ans);
}

void solve2() {
    LL ans = 0;
    REP(i, N) {
        if ((S[i] - '0') % 2 == 0) {
            ans += i + 1;
        }
    }
    cout << ans << endl;
}

void solve5() {
    LL ans = 0;
    REP(i, N) {
        const int d = (S[i] - '0');
        if (d == 0 || d == 5) {
            ans += i + 1;
        }
    }
    cout << ans << endl;
}

int main(void) {
    scanf("%d%d", &N, &P);
    scanf("%s", S);

    if (P == 2) {
        solve2();
        return 0;
    } else if (P == 5) {
        solve5();
        return 0;
    }

    reverse(S, S + N);

    VL v(N);
    VL v_acc(N + 1);
    {
        LL tmp = 1;
        REP(i, N) {
            v[i] = (S[i] - '0') * tmp % P;
            (tmp *= 10) %= P;
        }

        REP(i, N) {
            v_acc[i + 1] = (v_acc[i] + v[i]) % P;
        }
    }

    map<LL, LL> cnt;
    LL ans = 0;
    RREP(i, N + 1) {
        ans += cnt[v_acc[i]];
        cnt[v_acc[i]]++;
    }

    cout << ans << endl;
}
