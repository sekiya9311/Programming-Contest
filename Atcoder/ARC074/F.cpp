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

//超点数や流量がめっちゃ大きいときは Dinic!!
//蟻本P190~
class FordFulkerson {
    struct edge {
        int to, rev;    //行き先，逆辺(のid)
        long long cap;  //容量
        edge(int _to, int _rev, long long _cap) {
            this->to = _to;
            this->rev = _rev;
            this->cap = _cap;
        }
    };
private:
    vector<vector<edge>> G;
    vector<bool> used;
    long long dfs(int v, int t, long long f) {
        if (v == t) return f;
        used[v] = true;
        for (auto &&el : G[v]) {
            if (used[el.to] || el.cap <= 0) {
                continue;
            }
            long long d = dfs(el.to, t, min(f, el.cap));
            if (d > 0) {
                el.cap -= d;
                G[el.to][el.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
public:
    FordFulkerson() {}
    FordFulkerson(int n) {
        G.resize(n);
        used.resize(n, false);
    }
    void add_edge(int from, int to, long long cap) {
        G[from].emplace_back(edge(to, G[to].size(), cap));
        G[to].emplace_back(edge(from, G[from].size() - 1, 0));
    }
    long long max_flow(int s, int t) {
        if (s == t) return 0;
        long long flow = 0;
        while (1) {
            fill(begin(used), end(used), false);
            long long f = dfs(s, t, LLINF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};

const int MAX = 110;
FordFulkerson ff(MAX * MAX * 2);
int H, W;
string S[MAX];
char strbuf[MAX];
string next() {
scanf("%s", strbuf);
return strbuf;
}

bool check() {
    int sh = -1, sw = -1;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == 'S') {
                sh = i;
                sw = j;
            }
        }
    }
    REP(i, H) {
        if (S[i][sw] == 'T') return true;
    }
    REP(j, W) {
        if (S[sh][j] == 'T') return true;
    }
    return false;
}

inline int calc(int h, int w) {
    return MAX * h + w;
}
inline int calc2(int h, int w) {
    return MAX * h + w + MAX * MAX;
}

int main(void) {
    scanf("%d%d", &H, &W);
    REP(i, H) {
        S[i] = next();
    }
    if (check()) {
        cout << -1 << endl;
        return 0;
    }
    int sh = -1, sw = -1, gh = -1, gw = -1;
    REP(i, H) REP(j, W) {
        ff.add_edge(calc(i, j), calc2(i, j), 1);
    }
    REP(i, H) {
        REP(j, W) {
            const int now = calc(i, j);
            const int now2 = calc2(i, j);
            if (S[i][j] != '.') {
                FOR(k, i + 1, H) {
                    if (S[k][j] != '.') {
                        ff.add_edge(now2, calc(k, j), LLINF);
                        ff.add_edge(calc2(k, j), now, LLINF);
                    }
                }
                FOR(k, j + 1, W) {
                    if (S[i][k] != '.') {
                        ff.add_edge(now2, calc(i, k), LLINF);
                        ff.add_edge(calc2(i, k), now, LLINF);
                    }
                }
            }
            if (S[i][j] == 'S') {
                sh = i;
                sw = j;
            }
            if (S[i][j] == 'T') {
                gh = i;
                gw = j;
            }
        }
    }
    cout << ff.max_flow(calc2(sh, sw), calc(gh, gw)) << endl;
}
