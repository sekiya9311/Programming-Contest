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

void TLE(const string &s) {
    static int imosArray[26][MAX];
    static int* imos[26];
    auto isKaibun = [&] (int l, int r) {
        int odd = 0;
        REP(i, 26) odd += (imos[i][r - 1] - imos[i][l - 1]) % 2;
        return odd < 2;
    };
    static VI dp;
    const int L = s.size();
    REP(i, 26) {
        imos[i] = &imosArray[i][1];
    }
    REP(i, s.size()) {
        imos[s[i] - 'a'][i]++;
    }
    REP(i, 26) REP(j, MAX - 2) {
        imos[i][j + 1] += imos[i][j];
    }
    dp = VI(L + 1, L); // dp[i] := i) の最小
    dp[0] = 0;
    REP(i, L) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        FOR(j, i + 1, L + 1) {
            if (isKaibun(i, j)) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
    }
    cout << dp[L] << endl;
}

void Fast(const string &S) {
    static int dp[1 << 26];
    const int L = S.length();
    fill(dp, dp + (1 << 26), L);
    int bit = 0;
    dp[bit] = 0;
    for (int i = 0; i < L; i++) {
        bit ^= (1 << (S[i] - 'a'));
        for (int j = 0; j < 26; j++) {
            dp[bit] = min(dp[bit], dp[bit ^ (1 << j)] + 1);
        }
    }
    int ans = __builtin_popcount(bit) <= 1 ? 1 : dp[bit];
    cout << ans << endl;
}

int main(void) {
    string s;
    cin >> s;
    //TLE(s);
    Fast(s);
}
