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

const int N = 24;
int a[N];

const VI master{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

bool check(VI v) {
    REP(i, 6) {
        int now = -1;
        REP(j, 4) {
            if (now == -1) now = a[v[i * 4 + j] - 1];
            if (a[v[i * 4 + j] - 1] != now) {
                //cout << i << " " << j << endl;
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    REP(i, N) {
        cin >> a[i];
    }
    bool ok = false;
    VI v{24, 2, 22, 4, 1, 6, 3, 8, 5, 10, 7, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 11, 23, 9};
    ok |= check(v);
    v = {5, 2, 7, 4, 9, 6, 11, 8, 24, 10, 22, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 3, 23, 1};
    ok |= check(v);
    v = {1, 2, 3, 4, 13, 14, 7, 8, 9, 10, 11, 12, 21, 22, 15, 16, 5, 6, 19, 20, 17, 18, 23, 24};
    ok |= check(v);
    v = {1, 2, 3, 4, 17, 18, 7, 8, 9, 10, 11, 12, 5, 6, 15, 16, 21, 22, 19, 20, 13, 14, 23, 24};
    ok |= check(v);
    v = {15, 13, 3, 4, 5, 6, 7, 8, 9, 10, 20, 18, 11, 14, 12, 16, 17, 1, 19, 2, 21, 22, 23, 24};
    ok |= check(v);
    v = {18, 20, 3, 4, 5, 6, 7, 8, 9, 10, 13, 15, 2, 14, 1, 16, 17, 12, 19, 11, 21, 22, 23, 24};
    ok |= check(v);
    cout << (ok ? "Yes" : "No") << endl;
}
