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

#define double long double

void solve() {
    int N, D, H;
    cin >> N >> D >> H;
    VT<pair<double, double>> dh(N);
    REP(i, N) {
        cin >> dh[i].first >> dh[i].second;
    }

    double ans = 0;
    REP(i, N) {
        chmax(ans, dh[i].second - ((H - dh[i].second) / (D - dh[i].first) * dh[i].first));
    }

    cout << fixed << setprecision(20) << ans << endl;

//    for (double d = 0; d <= D; d += 1e-4) {
//        bool f = true;
//        REP(j, N) {
//            if ((H - d) / D * dh[j].first + d < dh[j].second) {
//                f = false;
//            }
//        }
//
//        if (f) {
//            cout << fixed << setprecision(20) << d << endl;
//            return;
//        }
//    }

//    double ng = 0, ok = 1000;
//    REP(_, 2000) {
//        const auto mid = ng + (ok - ng) / 2;
//
//        bool f = true;
//        REP(j, N) {
//            if ((H - mid) / D * dh[j].first + mid < dh[j].second) {
//                f = false;
//            }
//        }
//        if (f) {
//            ok = mid;
//        } else {
//            ng = mid;
//        }
//    }
//
//    cout << fixed << setprecision(20) << ok << endl;
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
