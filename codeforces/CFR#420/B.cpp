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

LL m, b;

// y = -(x / m) + b

inline LL sum(LL x) {
    return x * (x + 1) / 2;
}

LL calc(LL x, LL y) {
    LL res = 0;
    LL mi = min(x, y) + 1;
    LL ma = max(x, y);
    for (LL i = 0; i < mi; i++) {
        if (i) res += sum(ma + i) - sum(i - 1);
        else res += sum(ma);
    }
    return res;
}

VL v;

int main(void) {
    cin >> m >> b;
    for (LL x = b; x >= 0; x--) {
            v.EB(x * m);
    }
    int high = v.size(), low = 0;
    while (high - low > 10) {
        const int mid1 = (low + high + low) / 3;
        const int mid2 = (high + high + low) / 3;
        if (calc(v[mid1], -(v[mid1] / m) + b) <= calc(v[mid2], -(v[mid2] / m) + b)) {
            low = mid1;
        } else {
            high = mid2;
        }
    }
    LL ma = 0;
    chmax(ma, calc(v[(int)v.size() - 1], -(v[(int)v.size() - 1] / m) + b));
    if (v.size() >= 2)chmax(ma, calc(v[(int)v.size() - 2], -(v[(int)v.size() - 2] / m) + b));
    chmax(ma, calc(v[0], -(v[0] / m) + b));
    if (v.size() >= 2)chmax(ma, calc(v[1], -(v[1] / m) + b));
    FOR(i, low, high + 1) {
        chmax(ma, calc(v[i], -(v[i] / m) + b));
    }
    cout << ma << endl;
}
