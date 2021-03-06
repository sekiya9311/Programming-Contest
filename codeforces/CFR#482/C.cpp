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

const int MAX = 3e5 + 10;
int N, X, Y;
VI G[MAX];
int a[MAX], b[MAX];
//XのあとY行ったらダメ!!

int dfs(int now, int prev, int target, int master) {
    if (now == target) {
        return -1;
    }
    int sum = 1;
    FORE(e, G[now]) {
        if (e != prev) {
            int tmp = dfs(e, now, target, master);
            if (tmp == -1) {
                if (now != master) {
                    return -1;
                }
            } else {
                sum += tmp;
            }
        }
    }
    return sum;
}

int main(void) {
    scanf("%d%d%d", &N, &X, &Y);
    X--;Y--;
    REP(i, N - 1) {
        scanf("%d%d", a + i, b + i);
        a[i]--;b[i]--;
        G[a[i]].EB(b[i]);
        G[b[i]].EB(a[i]);
    }
    LL xSum = dfs(X, -1, Y, X);
    LL ySum = dfs(Y, -1, X, Y);
    DEBUG(xSum)
    DEBUG(ySum)
    cout << 1ll * N * (N - 1) - (xSum * ySum) << endl;
}
