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

int main(void) {
    int H; cin >> H;
    string s;
    int h, m;
    cin >> s;
    h = atoi(s.substr(0, 3).c_str());
    m = atoi(s.substr(3, 2).c_str());
    if (H == 12) {
        if (h > 12) {
            h %= 10;
        }
        if (h == 0) h = 10;
    } else {
        if (h >= 24) {
            h %= 10;
        }
    }
    if (m >= 60) {
        m %= 10;
    }
    if (h <10 && m < 10) {
        cout << 0 << h << ":" << 0 << m << endl;
    } else if (h < 10) {
        cout << 0 << h << ":" << m << endl;
    } else if (m < 10) {
        cout << h << ":" << 0 << m << endl;
    } else {
        cout << h << ":" << m << endl;
    }
}