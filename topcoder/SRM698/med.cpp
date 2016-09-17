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
#define RREP(i, a) for(int (i) = (a)-1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a)-1; (i) >= (b); (i)--)
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
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, e) (s.find(e) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e18;

class RepeatStringEasy {
public:
    int LCS(string a, string b) {
        vector <vector <int>> dp(a.size() + 5, vector <int>(b.size() + 5, 0));
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (a[i] == b[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[a.size()][b.size()];
    }
    int maximalLength(string s) {
        int res = 0;
        FOR(i, 1, s.size()) {
            string a, b;
            a = s.substr(0, i);
            b = s.substr(i, s.size() - i);
            //cout << a << " " << b << endl;
            res = max(res, LCS(a, b));
        }
        return res * 2;
    }
};

int main(void) {
    RepeatStringEasy c;
    string s; cin >> s;
    cout << c.maximalLength(s) << endl;
}
