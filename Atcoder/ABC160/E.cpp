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

const int MAX = 1e5 + 10;
int X, Y, A, B, C;
LL p[MAX], q[MAX], r[MAX];

int main(void) {
    cin >> X >> Y >> A >> B >> C;
    REP(i, A) {
        cin >> p[i];
    }
    REP(i, B) {
        cin >> q[i];
    }
    REP(i, C) {
        cin >> r[i];
    }

    priority_queue<pair<LL, int>> pq;
    REP(i, A) pq.emplace(p[i], 1);
    REP(i, B) pq.emplace(q[i], 2);
    REP(i, C) pq.emplace(r[i], 3);

    VL red, green, free;
    while (!pq.empty()) {
        const auto cur = pq.top();
        pq.pop();
        switch (cur.second) {
        case 1:
            {
                // red
                if (red.size() == X) continue;
                const auto tmp = Y - green.size();
                const auto tmp2 = free.size() - tmp;
                if (red.size() + max<int>(0, tmp2) >= X) continue;

                red.EB(cur.first);
                break;
            }
        case 2:
            {
                // green
                if (green.size() == Y) continue;
                const auto tmp = X - red.size();
                const auto tmp2 = free.size() - tmp;
                if (green.size() + max<int>(0, tmp2) >= Y) continue;
                green.EB(cur.first);
                break;
            }
        case 3:
            {
                // free
                const auto tmp = X - red.size();
                const auto tmp2 = Y - green.size();
                if (free.size() >= tmp + tmp2) continue;
                free.EB(cur.first);
                break;
            }
        }
    }

    LL ans = 0;
    FORE(e, red) ans += e;
    FORE(e, green) ans += e;
    FORE(e, free) ans += e;

    cout << ans << endl;
}
