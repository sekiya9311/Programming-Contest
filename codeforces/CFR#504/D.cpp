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

const int MAX = 2e5 + 10;
int N, Q;
int a[MAX];
VI mp[MAX];
VI unknown;

bool vis[MAX];
void dfs(int now, int val) {
    vis[now] = true;
    if (a[now] == -1) {
        a[now] = val;
    }
    if (0 < now && !vis[now - 1] && a[now - 1] == -1) {
        dfs(now - 1, val);
    } else if (now + 1 < N && !vis[now + 1] && a[now + 1] == -1) {
        dfs(now + 1, val);
    }
}

int main(void) {
    scanf("%d%d", &N, &Q);
    REP(i, N) scanf("%d", a + i), a[i]--;
    VI a_non_zero;
    REP(i, N) {
        if (a[i] > -1) a_non_zero.EB(a[i]);
        else unknown.EB(i);
    }
    REP(i, a_non_zero.size()) {
        mp[a_non_zero[i]].EB(i);
    }
    RREP(i, Q) {
        if (mp[i].size() > 1) {
            REP(j, mp[i].size()) {
                if (j + 1 < mp[i].size() && mp[i][j] + 1 < a_non_zero.size() && a_non_zero[mp[i][j] + 1] < i) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    if (unknown.size() == 0 && mp[Q - 1].size() == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (unknown.size() == N) {
        REP(i, N) a[i] = Q - 1;
    } else {
        REP(i, N) if (!vis[i] && a[i] > -1) {
            dfs(i, a[i]);
        }
    }
    if (mp[Q - 1].size() == 0) {
        a[unknown[0]] = Q - 1;
    }
    REP(i, N) printf("%d%c", a[i] + 1, (i + 1 == N ? '\n' : ' '));
}
