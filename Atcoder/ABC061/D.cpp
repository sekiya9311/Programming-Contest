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

// O(|V||E|)
struct edge {int from, to, cost;};
bool Bellman_Ford(int V, int E, int s, edge es[], LL dist[]) {
    fill(dist, dist + V, LLINF);
    dist[s] = 0;
    int cnt = 0;
    while (true) {
        bool update = false;
        set<int> se;
        for (int i = 0; i < E; ++i) {
            bool f = (dist[es[i].from] != LLINF && chmin(dist[es[i].to], dist[es[i].from] + es[i].cost));
            if (f) se.insert(es[i].to);
            update |= f;
        }
        if (!update) break;
        if (cnt == V - 1) {
            if (se.count(V - 1)) return true;
            break;
        }
        ++cnt;
    }
    return false;
}

const int MAX_N = 1010;
const int MAX_M = 2020;
int N, M;
edge e[MAX_M];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, M) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i] = {a - 1, b - 1, -c};
    }
    vector<LL> dist(N);
    if (Bellman_Ford(N, M, 0, e, dist.data())) {
        cout << "inf" << endl;
        DEBUG(-dist[N - 1])
    } else cout << -dist[N - 1] << endl;
}
