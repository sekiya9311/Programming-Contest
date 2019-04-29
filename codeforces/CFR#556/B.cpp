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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N;
string S[55];
bool vis[55][55];

bool check(int ii, int jj) {
    if (ii + 1 >= N || ii + 2 >= N || jj + 1 >= N || jj - 1 < 0) {
        return false;
    }
    vis[ii][jj] = true;

    if (vis[ii + 1][jj] || S[ii + 1][jj] != '.') return false;
    vis[ii + 1][jj] = true;

    if (vis[ii + 2][jj] || S[ii + 2][jj] != '.') return false;
    vis[ii + 2][jj] = true;

    if (vis[ii + 1][jj - 1] || S[ii + 1][jj - 1] != '.') return false;
    vis[ii + 1][jj - 1] = true;

    if (vis[ii + 1][jj + 1] || S[ii + 1][jj + 1] != '.') return false;
    vis[ii + 1][jj + 1] = true;

    return true;
}

int main(void) {
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }
    {
        int cnt = 0;
        REP(i, N) REP(j, N) if (S[i][j] == '.') cnt++;
        if (cnt % 5) {
            cout << "NO" << endl;
            return 0;
        }
    }

    REP(i, N) {
        REP(j, N) {
            if (!vis[i][j] && S[i][j] == '.') {
                if (!check(i, j)) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;
}
