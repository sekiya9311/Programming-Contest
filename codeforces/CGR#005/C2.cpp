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

const int MAX = 50010;
int N;
LL x[MAX], y[MAX], z[MAX];

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld%lld%lld", x + i, y + i, z + i);
    }

    map<LL, VT<tuple<LL, LL, int>>> z_to_xy;
    REP(i, N) {
        z_to_xy[z[i]].EB(x[i], y[i], i);
    }

    VT<pair<LL, int>> nokori;
    FORE(e, z_to_xy) {

        map<LL, VT<pair<LL, int>>> y_to_x;
        FORE(ee, e.second) {
            const auto X = get<0>(ee);
            const auto Y = get<1>(ee);
            const auto index = get<2>(ee);

            y_to_x[Y].EB(X, index);
        }

        VT<pair<LL, int>> pre_nokori;
        const auto Z = e.first;
        FORE(ee, y_to_x) {
            SORT(ee.second);
            REP(i, ee.second.size() / 2) {
                printf("%d %d\n", ee.second[i * 2].second + 1, ee.second[i * 2 + 1].second + 1);
            }
            if (ee.second.size() % 2) {
                pre_nokori.EB(ee.first, ee.second.back().second);
            }
        }

        SORT(pre_nokori);
        REP(i, pre_nokori.size() / 2) {
            printf("%d %d\n", pre_nokori[i * 2].second + 1, pre_nokori[i * 2 + 1].second + 1);
        }
        if (pre_nokori.size() % 2) {
            nokori.EB(e.first, pre_nokori.back().second);
        }
    }

    SORT(nokori);
    REP(i, nokori.size() / 2) {
        printf("%d %d\n", nokori[i * 2].second + 1, nokori[i * 2 + 1].second + 1);
    }
}
