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

const int MAX = 40010;
int N, M;
LL K;
int a[MAX], b[MAX];

VL make(int *ar, int size) {
    int cnt = 0;
    VL res(MAX);
    REP(i, size) {
        if (ar[i]) {
            res[++cnt]++;
        } else {
            cnt = 0;
        }
    }

    RREP(i, MAX - 1) {
        res[i] += res[i + 1];
    }

    return res;
}

int main(void) {
    scanf("%d%d%lld", &N, &M, &K);
    REP(i, N) scanf("%d", a + i);
    REP(i, M) scanf("%d", b + i);

    const auto a_cnt = make(a, N);
    const auto b_cnt = make(b, M);

    LL ans = 0;
    for (LL i = 1; i <= min<LL>(max(N, M), K); i++) {
        if (K % i || i >= a_cnt.size() || K / i >= b_cnt.size()) continue;

        ans += 1LL * a_cnt[i] * b_cnt[K / i];
    }

    cout << ans << endl;
}
