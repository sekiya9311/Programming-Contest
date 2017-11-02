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
#define RREP(i, a) for (int (i) = (a)-1; (i) >= 0; (i)--)
#define FORR(i, a, b) for (int (i) = (a)-1; (i) >= (b); (i)--)
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
#define FORE(a,b) for (auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;

int main(void) {
    int n;
    cin >> n;
    VL a(n);
    REP (i, n) cin >> a[i];
    REVERSE(a);
    VL b(n, 0);
    b[0] = a[0];
    FOR (i, 1, n) {
        if(!i&1)  b[i] = a[i] - a[i-1];
        else b[i] = a[i] + a[i-1];
    }
    REVERSE(b);
    REP (i, n) cout << b[i] <<" ";
    cout << endl;
}
