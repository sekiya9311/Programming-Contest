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
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX_N = 55;
const int MAX_M = 1111;
int N, M;
int x[MAX_M], y[MAX_M], z[MAX_M];
LL G[MAX_N][MAX_N];

void solve(int testNum) {
    stringstream ss;
    REP(i, MAX_N) REP(j, MAX_N) {
        if (i == j) G[i][j] = 0;
        else G[i][j] = LLINF;
    }

    scanf("%d%d", &N, &M);
    REP(i, M) {
        scanf("%d%d%d", x + i, y + i, z + i);
        x[i]--; y[i]--;
        G[x[i]][y[i]] = G[y[i]][x[i]] = z[i];
    }

    REP(k, N) REP(i, N) REP(j, N) chmin(G[i][j], G[i][k] + G[k][j]);

    bool exists = true;
    REP(i, M) {
        if (G[x[i]][y[i]] != G[y[i]][x[i]] || G[x[i]][y[i]] != z[i]) {
            exists = false;
            break;
        }
    }
    if (exists) {

        ss << M << endl;
        REP(i, M) {
            ss << x[i] + 1 << " " << y[i] + 1 << " " << z[i] << endl;
        }

    } else {
        ss << "Impossible" << endl;
    }

    cout << "Case #" << testNum << ": " << ss.str();
}

int main(void) {
    if (freopen("out.txt", "w", stdout) == NULL) {
        cerr << "file open failed" << endl;
        exit(1);
    }
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
