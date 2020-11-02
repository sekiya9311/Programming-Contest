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
LL a[MAX], b[MAX];

LL calc(LL mid) {
    LL delivery = 0;
    LL work_me = 0;
    REP(i, N) {
        if (a[i] <= mid) {
            chmax(delivery, a[i]);
        } else {
            work_me += b[i];
        }
    }
    return max(work_me, delivery);
}

void solve2() {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld", a + i);
    }
    REP(i, N) {
        scanf("%lld", b + i);
    }

    VI idx(N);
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](const auto &l, const auto &r) {
        if (a[l] == a[r]) return b[l] < b[r];
        return a[l] > a[r];
    });


    LL work_me = 0;
    LL ans = a[idx[0]];
    REP(ii, idx.size()) {
        const auto i = idx[ii];
        work_me += b[i];
        const auto tmp = max(ii + 1 == N ? 0 : a[idx[ii + 1]], work_me);
        chmin(ans, tmp);

        // cerr << "(" << a[i] << ", " << b[i] << ")" << endl;
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
