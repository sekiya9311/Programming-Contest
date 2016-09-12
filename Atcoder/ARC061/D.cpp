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
const int MOD = INF + 7;

const int MAX = 1e5 + 10;
#define int LL
int H, W, N;
int a[MAX], b[MAX];
int ans[10];

bool inside(int h, int w) {
    bool res = true;
    if (h < 0 || h >= H - 2) res = false;
    if (w < 0 || w >= W - 2) res = false;
    return res;
}

signed main(void) {
    scanf("%d %d %d", &H, &W, &N);
    ans[0] = (H - 2) * (W - 2);
    map <PII, int> mp;
    REP (i, N) {
	scanf("%d %d", &a[i], &b[i]);
	a[i]--; b[i]--;
	REP (j, 3) REP (k, 3) {
	    PII p = MP(a[i] - j, b[i] - k);
	    mp[p]++;
	}
    }
    FORE(el, mp) {
	int h = el.first.first;
	int w = el.first.second;
	if(!inside(h, w)) continue;
	//cout << h << " " << w << endl;
	ans[el.second]++;
    }
    FOR (i, 1, 10) {
	ans[0] -= ans[i];
    }
    REP (i, 10) {
	cout << ans[i] << endl;
    }
}
