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

const int MAX = 2222;
int N;
LL a[MAX];

bool check() {
    REP(i, N - 1) {
        if (a[i] >= a[i + 1]) return false;
    }
    return true;
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld", a + i);
    }
    if (check()) {
        puts("0");
        return 0;
    }
    printf("%d\n", N + 1);
    LL ma = 0;
    REP(i, N) chmax(ma, a[i]);
    LL foo = ma + N + 1;
    RREP(i, N) {
        LL bar = (i - (a[i] + foo) % (ma + N + 1) + (ma + N + 1)) % (ma + N + 1);
        printf("1 %d %lld\n", i + 1, bar);
        foo += bar;
        a[i] += foo;
    }
    // puts("");
    // REP(i, N) printf("%lld\n", a[i] % (ma + N + 1));
    // puts("");
    // 0, 1, 2, 3, ...
    printf("2 %d %lld\n", N, ma + N + 1);
}
