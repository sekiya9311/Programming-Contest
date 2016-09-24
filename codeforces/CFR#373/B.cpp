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
#define ALL(a) ((a).begin(), (a).end())
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define EP emplace_back
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;

int cnt(string s, char fst) {
    int cnt = 0;
    char c[2];
    if (fst == 'r') {
        c[0] = 'r';
        c[1] = 'b';
    } else {
        c[0] = 'b';
        c[1] = 'r';
    }
    int ccnt[2];REP(i,2)ccnt[i]=0;
    REP(i, s.size()) {
        if (s[i] != c[i%2]) ccnt[i%2]++;
    }
    return max(ccnt[0],ccnt[1]);
}

int main(void) {
    int n; cin >> n;
    string s; cin >> s;
    cout << min(cnt(s, 'r'), cnt(s, 'b')) << endl;
}
