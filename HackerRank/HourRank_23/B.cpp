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

// !!!!!!!!!!!!  TLE  !!!!!!!!!!!!!

const int MAX = 444;
int q;
int n, m, k;
int h[MAX][MAX];

bool check(pair<int, int> l, pair<int, int> r) {
    LL sum = 0;
    FOR(i, l.first, r.first) {
        FOR(j, l.second, r.second) {
            const int need = min(min(i - l.first + 1, r.first - i), min(j - l.second + 1, r.second - j));
            //cerr << "need = " << need << endl;
            //cerr << i << " " << j << endl;
            //cerr << "h[i][j] = " << h[i][j] << endl;
            if (h[i][j] > need) return false;
            sum += need - h[i][j];
        }
    }
    return sum <= k;
}

void func() {
    int ans = 0;
    REP(i, n) {
        REP(j, m) {
            const pair<int, int> l = MP(i, j);
            FOR(cnt, 1, 176) {
                const int size = 2 * cnt - 1;
                const pair<int, int> r = MP(i + size, j + size);
                if (r.first > n || r.second > m) break;
                if (check(l, r)) {
                    //cerr << i << " " << j << " " << cnt << endl;
                    chmax(ans, cnt);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main(void) {
    scanf("%d", &q);
    REP(i, q) {
        scanf("%d%d%d", &n, &m, &k);
        REP(j, n) REP(kk, m) {
            scanf("%d", h[j] + kk);
        }
        func();
    }
}
