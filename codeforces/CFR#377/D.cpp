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
#include <random>

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for (int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for (int (i) = (a) - 1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cerr << C << endl;
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
#define FORE(a, b) for (auto &&a : b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int n, m;
VI a, d;

bool check(int N) {
    set<int> place[m];
    REP(i, N) {
        if (d[i]) place[d[i] - 1].insert(i);
    }
    VPII last(m, MP(-1, -1));
    REP(i, m) {
        if (place[i].size() == 0) {
            return false;
        }
        last[i] = MP(*(--place[i].end()), i);
    }
    SORT(last);
    int usedDay = 0;
    set<int> already;
    FORE(el, last) {
        if (a[el.second] <= el.first - usedDay) {
            already.insert(el.second);
            usedDay += a[el.second] + 1;
        }
    }
    return already.size() == m;
}

int main(void) {
    cin >> n >> m;
    d.resize(n);
    a.resize(m);
    REP(i, n) scanf("%d", &d[i]);
    REP(i, m) scanf("%d", &a[i]);
    int sum = accumulate(ALL(a), 0);
    if (sum + m > n) {
        cout << -1 << endl;
        return 0;
    }
    if (!check(n)) {
        cout << -1 << endl;
        return 0;
    }
    int high = n, low = 0;
    while (high - low > 1) {
        int mid = low + (high - low) / 2;
        (check(mid) ? high : low) = mid;
    }
    cout << low + 1 << endl;
}
