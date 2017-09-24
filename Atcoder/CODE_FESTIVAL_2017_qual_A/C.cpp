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
int h, w;
string a[MAX];
int cnt[26];
bool vis[MAX][MAX];
int need[MAX * MAX];

bool inside(int nh, int nw) {
    return 0 <= nh && nh < h && 0 <= nw && nw < w;
}

bool inside(int nn, bool f) {
    if (f) return 0 <= nn && nn < h;
    else return 0 <= nn && nn < w;
}

int dfs(int nowH, int nowW) {
    //cerr << "now : " << nowH << " " << nowW << endl << endl;;
    if (vis[nowH][nowW]) return 0;
    vis[nowH][nowW] = true;
    int revH = nowH - (h - 1);
    if (!inside(revH, true)) revH = h - 1 - nowH;
    int revW = nowW - (w - 1);
    if (!inside(revW, false)) revW = w - 1 - nowW;
    //cerr <<"rev : " << revH << " " << revW << endl;
    assert(inside(revH, revW));
    return dfs(nowH, revW) + dfs(revH, nowW) + 1;
}

int main(void) {
    cin >> h >> w;
    REP(i, h) {
        cin >> a[i];
        REP(j, w) cnt[a[i][j] - 'a']++;
    }
    REP(i, h) {
        REP(j, w) {
            if (!vis[i][j]) {
                need[dfs(i, j)]++;
            }
        }
    }
    //REP(i, MAX * MAX) if (need[i]) cerr << i << " : " << need[i] << endl;
    RREP(i, MAX * MAX) {
        sort(cnt, cnt + 26);
        RREP(j, 26) {
            while (cnt[j] >= i && need[i]) {
                cnt[j] -= i;
                need[i]--;
            }
        }
        if (need[i] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
