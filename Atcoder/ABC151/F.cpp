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

int N;
int X[55], Y[55];

long double dist(long double x, long double y, int i) {
    return sqrtl((X[i] - x) * (X[i] - x) + (Y[i] - y) * (Y[i] - y));
}

long double calc_y(long double x, long double y) {
    long double res = -LLINF;
    REP(i, N) {
        chmax(res, dist(x, y, i));
    }
    return res;
}

long double calc_x(long double x) {
    long double low = 0, high = 1001;
    REP(i, 200) {
        const auto mid1 = (low + low + high) / 3;
        const auto mid2 = (low + high + high) / 3;

        if (calc_y(x, mid1) <= calc_y(x, mid2)) {
            high = mid2;
        } else {
            low = mid1;
        }
    }

    return calc_y(x, low);
}

int main(void) {
    cin >> N;
    REP(i, N) {
        cin >> X[i] >> Y[i];
    }

    long double low = 0, high = 1001;
    REP(i, 200) {
        const auto mid1 = (high + low + low) / 3;
        const auto mid2 = (high + high + low) / 3;
        // cerr << mid1 << " " << mid2 << endl;
        // cerr << calc_x(mid1) << " " << calc_x(mid2) << endl;
        if (calc_x(mid1) <= calc_x(mid2)) {
            high = mid2;
        } else {
            low = mid1;
        }
    }

    cout << fixed << setprecision(20) << calc_x(low) << endl;
}
