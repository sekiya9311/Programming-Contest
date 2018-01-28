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

const int MAX = 2e5 + 10;
int N, M;
int L[MAX], R[MAX], D[MAX];
LL x[MAX];
bool exist_r[MAX];
VI x_idx[MAX];
bool used[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, M) {
        scanf("%d%d%d", L + i, R + i, D + i);
        L[i]--;
        R[i]--;
        exist_r[R[i]] = true;
        x_idx[L[i]].EB(i);
    }
    memset(x, -1, sizeof(x));
    queue<int> q;
    REP(i, N) {
        if (!exist_r[i]) {
            x[i] = 0;
            q.emplace(i);
        }
    }
    bool ok = true;
    while (!q.empty()) {
        const int e = q.front();
        q.pop();
        FORE(i, x_idx[e]) {
            used[i] = true;
            if (x[R[i]] == -1) {
                x[R[i]] = x[L[i]] + D[i];
                q.emplace(R[i]);
            }
            if (x[R[i]] != x[L[i]] + D[i]) {
                ok = false;
            }
        }
    }
    REP(i, M) {
        if (!used[i]) {
            if (x[L[i]] == -1 && x[R[i]] == -1) {
                x[L[i]] = 0;
                x[R[i]] = x[L[i]] + D[i];
            } else if (x[L[i]] == -1) {
                x[L[i]] = x[R[i]] - D[i];
            } else if (x[R[i]] == -1) {
                x[R[i]] = x[L[i]] + D[i];
            }
            if (x[R[i]] != x[L[i]] + D[i]) {
                ok = false;
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
