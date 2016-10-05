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
#define EB emplace_back

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e18;

int N;
VI a, dis;

int main(void) {
    cin >> N;
    a.resize(N);
    dis.resize(N + 1, 0);
    int maxlen = 0;
    REP(i, N) {
        cin >> a[i];
        dis[a[i]]++;
        maxlen = max(maxlen, a[i]);
    }
    int minlen = (maxlen + 1) / 2;
    REP(i, minlen) {
        if (dis[i]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    FOR(i, minlen, maxlen + 1) {
        if (i == minlen) dis[i] -= 1 + (maxlen % 2);
        else dis[i] -= 2;
        if (dis[i] < 0) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    REP(i ,minlen) if (dis[i + 1]) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    return 0;
}
