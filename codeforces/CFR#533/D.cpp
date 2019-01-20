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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int dx4[] = {0, 0, -1, 1};
const int dy4[] = {1, -1, 0, 0};
const int MAX = 1111;
inline string next() {
    static char strbuf[MAX];
    scanf("%s", strbuf);
    return strbuf;
}
int N, M, P;
LL S[10];
VPII edge[10];
string G[MAX];
int pos[MAX][MAX];

inline bool inside(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M && pos[i][j] == -1;
}

int main(void) {
    scanf("%d%d%d", &N, &M, &P);
    REP(i, P) {
        scanf("%lld", S + i);
    }
    memset(pos, -1, sizeof(pos));
    int nokori = N * M;
    REP(i, N) {
        string str = next();
        REP(j, M) {
            if (isdigit(str[j])) {
                pos[i][j] = str[j] - '1';
                edge[str[j] - '1'].EB(i, j);
                nokori--;
            } else if (str[j] == '#') {
                pos[i][j] = INF;
                nokori--;
            }
        }
    }
    while (nokori > 0) {
        const int pre = nokori;
        REP(i, P) {
            set<pair<int, PII>> que;
            FORE(e, edge[i]) {
                que.emplace(MP(1, e));
            }
            set<PII> n_e;
            while (!que.empty()) {
                auto el = *que.begin();
                que.erase(que.begin());
                REP(d, 4) {
                    int ni = el.second.first + dx4[d];
                    int nj = el.second.second + dy4[d];
                    if (!inside(ni, nj)) {
                        continue;
                    }
                    pos[ni][nj] = i;
                    nokori--;
                    REP(dd, 4) if (inside(ni + dx4[dd], nj + dy4[dd])) {
                        if (el.first == S[i]) {
                            n_e.emplace(ni, nj);
                        } else {
                            que.emplace(MP(el.first + 1, MP(ni, nj)));
                        }
                        break;
                    }
                }
            }
            edge[i].clear();
            FORE(e, n_e) {
                edge[i].EB(e);
            }
        }
        if (pre == nokori) break;
    }
    VI ans(P);
    REP(i, N) {
        REP(j, M) {
            if (0 <= pos[i][j] && pos[i][j] < P) {
                ans[pos[i][j]]++;
            }
        }
    }
    // REP(i, N) {
    //     REP(j, M) {
    //         if (0 <= pos[i][j] && pos[i][j] < P) cout << pos[i][j] << " ";
    //         else cout << 'x' << " ";
    //     }cout << endl;
    // }cout << endl;
    REP(i, P) printf("%d%c", ans[i], " \n"[i + 1 == P]);
}
