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

struct residential {
    int X, Y;
    int person;
};

int N;
residential residentials[16];
VI ew, ns;
LL ans[16];

LL calc() {
    LL res = 0;
    REP(i, N) {
        LL tmp = LLINF;
        chmin<LL>(tmp, abs(residentials[i].Y));
        chmin<LL>(tmp, abs(residentials[i].X));
        FORE(e, ew) {
            chmin<LL>(tmp, abs(residentials[i].Y - e));
        }
        FORE(e, ns) {
            chmin<LL>(tmp, abs(residentials[i].X - e));
        }
        res += tmp * residentials[i].person;
    }
    return res;
}

void dfs(int idx, int cnt) {
    if (cnt == N) {
        chmin(ans[ew.size() + ns.size()], calc());
        return;
    }

    dfs(idx + 1, cnt + 1);
    ew.EB(residentials[idx].Y);
    dfs(idx + 1, cnt + 1);
    ew.pop_back();
    ns.EB(residentials[idx].X);
    dfs(idx + 1, cnt + 1);
    ns.pop_back();
}

int main(void) {
    cin >> N;
    REP(i, N) {
        cin >> residentials[i].X >> residentials[i].Y >> residentials[i].person;
    }
    fill(ans, ans + 16, LLINF);

    dfs(0, 0);

    REP(i, N + 1) {
        cout << ans[i] << endl;
    }
}
