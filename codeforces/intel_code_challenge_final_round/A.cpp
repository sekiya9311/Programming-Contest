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

VI mday{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector <string> day{"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main(void) {
    string m1, m2;
    bool f = false;
    cin >> m1 >> m2;
    REP(i, day.size() - 1) {
        if (m1 == day[i]) {
            REP(j, mday.size() - 1) {
                if (day[(i + mday[j]) % 7] == m2) f = true;
            }
        }
    }
    string ans = "";
    if (f) ans = "YES";
    else ans = "NO";
    cout << ans << endl;
}
