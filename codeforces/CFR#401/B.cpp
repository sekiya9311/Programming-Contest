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

int n;
string sh, mo;

VI f(string s) {
    VI res;
    FORE(e, s) res.EB(e - '0');
    return res;
}

// moが最低限受けるフリック数
int solve1(VI shv, VI mov) {
    map<int, int> momp, shmp;
    FORE(e, mov) momp[e]++;
    FORE(e, shv) shmp[e]++;
    int res = 0, buf = 0;
    for (int e = 9; e >= 0; e--) {
        if (momp[e] + buf >= shmp[e]) {
            if (momp[e] >= shmp[e]) {
                buf += momp[e] - shmp[e];
            } else {
                buf -= shmp[e] - momp[e];
            }
        } else {
            res += shmp[e] - (momp[e] + buf);
            buf = 0;
        }
    }
    return res;
}
// moが当てることが出来る最大フリック数
int solve2(VI shv, VI mov) {
    map<int, int> momp, shmp;
    FORE(e, mov) momp[e]++;
    FORE(e, shv) shmp[e]++;
    int res = 0;
    REP(i, 10) {
        FOR(j, i + 1, 10) {
            res += min(momp[j], shmp[i]);
            if (momp[j] <= shmp[i]) {
                shmp[i] -= momp[j];
                momp[j] = 0;
            } else {
                momp[j] -= shmp[i];
                shmp[i] = 0;
                break;
            }
        }
    }
    return res;
}
int main(void) {
    cin >> n >> sh >> mo;
    VI shv = f(sh);
    VI mov = f(mo);
    cout << solve1(shv, mov) << '\n' << solve2(shv, mov) << endl;
}
