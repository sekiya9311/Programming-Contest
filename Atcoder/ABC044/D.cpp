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
#define FORE(a,b) for(auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e18;
#define int LL
LL n, s;
LL f(LL b, LL n) {
    if (n < b) return n;
    else return f(b, floor((double)n/(double)b))+(n%b);
}

signed main(void) {
    cin >> n >> s;
    if (n < s) {
        cout << -1 << endl;
        return 0;
    }
    if (n == s) {
        cout << n+1 << endl;
        return 0;
    }
    LL ans = LLINF;
    for (int i = 2; i*i <= n; i++) {
        if (f(i, n) == s) {
            ans = min<LL>(ans, i);
        }
    }
    for (int i = 1; i*i <= n; i++) {
        if ((n-s)%i) continue;
        LL b = ((n-s)/i)+1;
        if (f(b, n) == s) {
            ans = min(ans, b);
        }
    }
    cout << (ans!=LLINF?ans:(-1)) << endl;
}
