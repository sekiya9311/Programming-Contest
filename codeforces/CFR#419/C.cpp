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

const int MAX = 111;
const string row = "row", col = "col";
int N, M, x[MAX][MAX];
unordered_set<int> nr, nc;
vector<pair<bool, int>> ans;

int delrow(int id) {
    int mi = INF;
    REP(j, M) {
        chmin(mi, x[id][j]);
    }
    REP(j, M) {
        x[id][j] -= mi;
    }
    nr.insert(id);
    return mi;
} 

int  delcol(int id) {
    int mi = INF;
    REP(i, N) {
        chmin(mi, x[i][id]);
    }
    REP(i, N) {
        x[i][id] -= mi;
    }
    nc.insert(id);
    return mi;
}

bool check() {
    //REP(i, N) {REP(j, M){cout<<x[i][j]<<" ";}cout<<endl;}
    REP(i, N) REP(j, M) {
        if (x[i][j]) return false;
    }
    return true;
}

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, N) {
        REP(j, M) {
            scanf("%d", x[i] + j);
            if (x[i][j] == 0) {
                nr.insert(i);
                nc.insert(j);
            }
        }
    }
    while (!check()) {
        REP(i, N) {
            REP(j, M) {
                if (x[i][j]) {
                    if (N <= M) {
                        if (!nr.count(i)) {
                            int cnt = delrow(i);
                            REP(k, cnt) ans.EB(MP(true, i));
                        } else if (!nc.count(j)) {
                            int cnt = delcol(j);
                            REP(k, cnt) ans.EB(MP(false, j));
                        } else {
                            cout << -1 << endl;
                            return 0;
                        }
                    } else {
                        if (!nc.count(j)) {
                            int cnt = delcol(j);
                            REP(k, cnt) ans.EB(MP(false, j));
                        } else if (!nr.count(i)) {
                            int cnt = delrow(i);
                            REP(k, cnt) ans.EB(MP(true, i));
                        } else {
                            cout << -1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans.size());
    FORE(e, ans) {
        printf("%s %d\n", (e.first ? row.c_str() : col.c_str()), e.second + 1);
    }
}
