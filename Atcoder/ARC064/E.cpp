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

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

using State = pair<PII, int>;
int xs, ys, xg, yg;
int N;
VT<State> circle;

int main(void) {
    scanf("%d%d%d%d", &xs, &ys, &xg, &yg);
    scanf("%d", &N);
    circle.resize(N + 2);
    circle[0] = MP(MP(xs, ys), 0);
    circle[N + 1] = MP(MP(xg, yg), 0);
    REP(i, N) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        circle[i + 1] = MP(MP(x, y), r);
    }
    priority_queue<pair<double, int>, VT<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push(MP(0, 0));
    double ans = 1e18;
    VT<bool> visited(N + 2, false);
    while (!pq.empty()) {
        double nowCost;
        int nowId;
        tie(nowCost, nowId) = pq.top(); pq.pop();
        if (visited[nowId]) continue;
        visited[nowId] = true;
        if (nowId == N + 1) {
            ans = nowCost;
            break;
        }
        double x1, y1, r1;
        x1 = circle[nowId].first.first;
        y1 = circle[nowId].first.second;
        r1 = circle[nowId].second;
        REP(i, N + 2) {
            if (visited[i]) continue;
            double x2, y2, r2;
            x2 = circle[i].first.first;
            y2 = circle[i].first.second;
            r2 = circle[i].second;
            double nextCost = nowCost + max<long double>(0.0, sqrtl(powl(x1 - x2, 2) + powl(y1 - y2, 2)) - r1 - r2);
            pq.push(MP(nextCost, i));
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}
