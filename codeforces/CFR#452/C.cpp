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

int n;

void TLE() {
    VL buf(1 << n);
    REP(i, 1 << n) {
        VL sum(2);
        REP(j, n) sum[!!(i & (1 << j))] += n - j;
        buf[i] = llabs(sum[0] - sum[1]);
    }
    LL mi = LLINF;
    REP(i, 1 << n) {
        cout << i << " = " << buf[i] << endl;
        chmin(mi, buf[i]);
    }
    VI miIdx;
    REP(i, 1 << n) {
        if (mi == buf[i]) miIdx.EB(i);
    }
    cout << "min = " << mi << endl;
    cout << "idx : ";
    FORE(e, miIdx) cout << e << " ";cout << endl;
}

void fast() {
    LL sum = 1ll * n * (n + 1) / 2;
    printf("%lld\n", sum % 2);
    VI ans;
    sum /= 2;
    RREP(i, n) {
        if (sum >= i + 1) {
            ans.EB(i + 1);
            sum -= i + 1;
        }
    }
    assert(sum == 0);
    SORT(ans);
    printf("%d ", (int)ans.size());
    REP(i, ans.size()) printf("%d%c", ans[i], (i + 1 == (int)ans.size() ? '\n' : ' '));
}

int main(void) {
    cin >> n;
    //TLE();
    fast();
}
