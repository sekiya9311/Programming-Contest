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

const int MAX = 2e5 + 10;
int N, M;
VT<pair<int, LL>> G[MAX];
LL a[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, M) {
        int u, v;
        LL w;
        scanf("%d%d%lld", &v, &u, &w);
        u--;v--;
        G[u].EB(v, w << 1);
        G[v].EB(u, w << 1);
    }
    REP(i, N) {
        scanf("%lld", a + i);
    }
    priority_queue<pair<LL, int>, VT<pair<LL, int>>, greater<pair<LL, int>>> pq;
    REP(i, N) {
        pq.emplace(a[i], i);
    }
    while (!pq.empty()) {
        auto el = pq.top(); pq.pop();
        const LL cost = el.first;
        const int now = el.second;
        if (a[now] < cost) continue;
        FORE(e, G[now]) {
            if (e.second + cost <= a[e.first]) {
                a[e.first] = e.second + cost;
                pq.emplace(e.second + cost, e.first);
            }
        }
    }
    REP(i, N) {
        printf("%lld%c", a[i], " \n"[i + 1 == N]);
    }
}
