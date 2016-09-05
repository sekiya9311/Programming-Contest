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

int H, W;
void out(vector <string> red, vector <string> blue) {
    REP(i, H) cout << red[i] << endl;
    cout << endl;
    REP(i, H) cout << blue[i] << endl;
}

vector <string> merge(vector <string> red, vector <string> blue) {
    vector <string> out(H);
    REP (i, H) REP (j, W) {
        if (red[i][j] == '#' && blue[i][j] == '#') {
            out[i] += '#';
        } else {
            out[i] += '.';
        }
    }
    // REP (i, H) {
    //     cout << out[i] << endl;
    // }
    return out;
}

int main(void) {
    cin >> H >> W;
    vector <string> a(H), red(H, string(W, '.')), blue(H, string(W, '.'));
    REP (i, H) {
        red[i][0] = '#';
        blue[i][W-1] = '#';
    }
    REP (i, H) cin >> a[i];
    REP (i, H) if (i%2 == 1) REP (j, W-1) {
        red[i][j] = '#';
    }
    REP (i, H) if (i%2 == 0) FOR (j, 1, W) {
        blue[i][j] = '#';
    }
    REP (i, H) REP (j, W) {
        if (a[i][j] == '#') {
            red[i][j] = '#';
            blue[i][j] = '#';
        }
    }
    out(red, blue);
    // if (merge(red, blue) == a) {
    //     cerr << "AC" << endl;
    // } else {
    //     cerr << "WA" << endl;
    // }
}
