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

class bipartite_matching {
private:
    std::vector<std::vector<int>> G;
    std::vector<int> match;
    std::vector<bool> visited;
    bool dfs(const int now) {
        this->visited[now] = true;
        for (const int &nxt : this->G[now]) {
            const int nxt_match = this->match[nxt];
            if (nxt_match < 0 || (!this->visited[nxt_match]
                                && this->dfs(nxt_match))) {
                this->match[now] = nxt;
                this->match[nxt] = now;
                return true;
            }
        }
        return false;
    }
public:
    bipartite_matching() {}
    bipartite_matching(const int N)
        : G(N),
          match(N, -1),
          visited(N, false) {}
    void add_edge(const int from, const int to) {
        this->G[from].emplace_back(to);
        this->G[to].emplace_back(from);
    }
    int calc_maximum_match() {
        int ret = 0;
        for (int i = 0; i < (int) this->G.size(); i++) {
            if (this->match[i] < 0) {
                std::fill(
                    std::begin(this->visited),
                    std::end(this->visited),
                    false
                );
                ret += this->dfs(i);
            }
        }
        return ret;
    }
    int operator[](const int idx) const {
        return this->match[idx];
    }
} ;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
const int MAX = 44;
int r, c;
char C[MAX][MAX];
map<PII, int> mp;
map<int, PII> revmp;

inline bool inside(int nr, int nc) {
    return 0 <= nr && nr < r && 0 <= nc && nc < c;
}

int main(void) {
    scanf("%d%d", &r, &c);
    REP(i, r) {
        scanf("%s", C[i]);
    }
    int cnt = 0;
    REP(i, r) {
        REP(j, c) {
            if (C[i][j] == '.') {
                mp[{i, j}] = cnt++;
                revmp[mp[{i, j}]] = {i, j};
            }
        }
    }
    bipartite_matching bm(cnt);
    REP(i, r) {
        REP(j, c) {
            if (C[i][j] == '.') {
                REP(k, 4) {
                    const int ni = i + dx[k];
                    const int nj = j + dy[k];
                    if (inside(ni, nj) && mp.count({ni, nj})) {
                        bm.add_edge(mp[{i, j}], mp[{ni, nj}]);
                    }
                }
            }
        }
    }
    cout << cnt - bm.calc_maximum_match() << endl;
}
