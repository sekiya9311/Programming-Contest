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

int n, m;
string mz[55];
string s;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
bool inside(int ni, int nj) {
    return 0 <= ni && ni < n && 0 <= nj && nj < m;
}
int main(void) {
    cin >> n >> m;
    REP(i, n) {
        cin >> mz[i];
    }
    cin >> s;
    VI vec(4);
    REP(i, 4) vec[i] = i;
    int si, sj;
    REP(i, n) REP(j, m) {
        if (mz[i][j] == 'S') {
            si = i, sj = j;
        }
    }
    int cnt = 0;
    do {
        int ni = si, nj = sj;
        bool ok = true;
        FORE(e, s) {
            const int idx = vec[e - '0'];
            int nxti = ni + dx[idx];
            int nxtj = nj + dy[idx];
            if (inside(nxti, nxtj)) {
                ni = nxti, nj = nxtj;
                if (mz[ni][nj] == 'E') {
                    break;
                } else if (mz[ni][nj] == '#') {
                    ok = false;
                    break;
                }
            } else {
                ok = false;
                break;
            }
        }
        
        if (ok && mz[ni][nj] == 'E') {
            cnt++;
        }
        
    } while (next_permutation(ALL(vec)));
    cout << cnt << endl;
}
