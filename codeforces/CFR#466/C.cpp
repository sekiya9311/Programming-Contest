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

int N, K;
string S;
bool ok[26];

int main(void) {
    cin >> N >> K >> S;
    FORE(c, S) ok[c - 'a'] = true;
    string ans = "";
    char fc = -1, lc = -1;
    REP(i, 26) {
        if (ok[i] && fc == -1) fc = i + 'a';
        if (ok[26 - i - 1] && lc == -1) lc = 26 - i - 1 + 'a';
    }
    DEBUG(fc)DEBUG(lc)
    if (N < K) {
        REP(i, K) {
            if (i < N) ans += S[i];
            else ans += fc;
        }
    } else {
        REP(i, K) ans += S[i];
        RREP(i, K) {
            if (ans[i] != lc) {
                FOR(j, ans[i] - 'a' + 1, 26) if (ok[j]) {
                    ans[i] = j + 'a';
                    break;
                }
                FOR(j, i + 1, K) ans[j] = fc;
                break;
            }
        }
    }
    cout << ans << endl;
}
