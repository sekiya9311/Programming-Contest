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

bool check(int a, int b, int c) {
    VI v({a, b, c});
    SORT(v);
    if (v[0] + v[1] <= v[2]) return false;
    return true;
}

int main(void) {
    int x, y;
    cin >> x >> y;
    int a, b, c;
    a= b = c = y;
    int cnt = 0;
    int f = 1;
    vector <bool> ff(3, false);
    //0 a, 1 b, 2 c
    while(true) {
        //cout << a << " " << b << " " << c << endl;
        if (a == b && b == c && c == x) {
            cnt++; break;
        }
        if (f == 0) {
            if ((!check(a, b, c))) {
                a--;cnt++; f++; continue;
            }
            if (a == x) {
                if(!ff[0]) cnt++;
                ff[0] = true;
                f++;
                continue;
            }
            a++;
        } else if (f == 1) {
            if ((!check(a, b, c))) {
                b--;cnt++; f++; continue;
            }
            if (b == x) {
                if(!ff[1]) cnt++;
                ff[1] = true;
                f++;
                continue;
            }
            b++;
        } else if (f == 2) {
            if ((!check(a, b, c))) {
                c--;cnt++; f++; continue;
            }
            if (c == x) {
                if(!ff[2]) cnt++;
                ff[2] = true;
                f++;
                continue;
            }
            c++;
        }
        f %= 3;
    }
    cout << cnt << endl;
}
