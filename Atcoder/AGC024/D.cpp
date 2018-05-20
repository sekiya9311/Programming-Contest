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

int N;
VI G[111];
PII es[111];
int max_order[111];
PLL ans = MP(LLINF, LLINF);

int calc_dist(int now, int prev, int dist) {
    if (G[now].size() == 1 && prev != -1) {
        return dist + 1;
    }
    int ret = 0;
    FORE(e, G[now]) if (e != prev) {
        chmax(ret, calc_dist(e, now, dist + 1));
    }
    return ret;
}

void calc_max_order(int now, int prev, int ord) {
    chmax(max_order[ord], (int)G[now].size() - (prev != -1));
    FORE(e, G[now]) {
        if (e != prev) {
            calc_max_order(e, now, ord + 1);
        }
    }
}

int main(void) {
    cin >> N;
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].EB(b);
        G[b].EB(a);
        es[i] = {a, b};
    }
    REP(i, N) {
        const LL dist = calc_dist(i, -1, 0);
        if (dist <= ans.first) {
            memset(max_order, 0, sizeof(max_order));
            calc_max_order(i, -1, 0);
            LL node = 1;
            REP(j, 111) {
                if (max_order[j]) {
                    node *= max_order[j];
                }
            }
            chmin(ans, MP(dist, node));
        }
    }
    //cerr << ans.first << " " << ans.second << endl;
    REP(i, N - 1) {
        const LL dist = max(calc_dist(es[i].first, es[i].second, 0), calc_dist(es[i].second, es[i].first, 0));
        if (dist <= ans.first) {
            memset(max_order, 0, sizeof(max_order));
            calc_max_order(es[i].first, es[i].second, 0);
            calc_max_order(es[i].second, es[i].first, 0);
            LL node = 2;
            REP(j, 111) {
                if (max_order[j]) {
                    node *= max_order[j];
                }
            }
            chmin(ans, MP(dist, node));
        }
    }
    cout << ans.first << " " << ans.second << endl;
}
