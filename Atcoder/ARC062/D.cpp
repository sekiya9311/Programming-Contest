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

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for (int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for (int (i) = (a) - 1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cout<< C <<endl;
#define VI vector <int>
#define VII vector <VI>
#define VL vector <LL>
#define VLL vector <VL>
#define VD vector <double>
#define VDD vector <VD>
#define PII pair <int, int>
#define PDD pair <double, double>
#define PLL pair <LL, LL>
#define VPII vector <PII>
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define EB emplace_back
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;

PII dp[(int)1e5 + 10][3];
//dp[i][j] : i回目で勝った(0)，あいこ(1), 負け(2)のときの最大ポイント　と　パーできる回数

int main(void) {
    string s;
    cin >> s;
    int N = s.length();
    dp[0][0] = dp[0][1] = dp[0][2] = MP(0, 0);
    FOR(i, 1, N + 1) {
        int id = i - 1;

        if (s[id] == 'g') { //あいてグー
            PII ma = MP(-INF, 0);
            REP(j, 3) {
                if (dp[i - 1][j].second == 0) continue;
                ma = max(ma, dp[i - 1][j]);
            }
            if (ma.second > 0) ma.second--;
            dp[i][0] = ma;
            if (dp[i][0].first != -INF) dp[i][0].first++;
            dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][1].second++;
            dp[i][2] = MP(-INF, 0);

        } else {    //あいてパー

            dp[i][0] = MP(-INF, 0);
            PII ma = MP(-1, 0);
            REP(j, 3) {
                if (dp[i - 1][j].second == 0) continue;
                ma = max(ma, dp[i - 1][j]);
            }
            if (ma.second > 0) ma.second--;
            dp[i][1] = ma;
            ma = MP(-1, -1);
            REP(j, 3) {
                if (dp[i - 1][j].second == 0) continue;
                ma = max(ma, dp[i - 1][j]);
            }
            if (ma.second != -1) ma.second++;
            dp[i][2] = ma;
            dp[i][2].first--;
        }
    }
    int win = max({dp[N][0].first, dp[N][1].first, dp[N][2].first});
    cout << win << endl;
}
