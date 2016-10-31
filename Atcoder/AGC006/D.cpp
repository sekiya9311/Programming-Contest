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
 
using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
 
const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
 
VI a;
int N, all;
 
bool check(int n) {
    vector<bool> b(all);
    REP(i, all) b[i] = (a[i] >= n);
    if (b[N - 2] == b[N - 1] || b[N - 1] == b[N]) return b[N - 1];
    int right = N - 1, left = N - 1;
    while (right + 1 < all && b[right] != b[right + 1]) right++;
    while (left - 1 >= 0 && b[left] != b[left - 1]) left--;
    return ((abs(N - 1 - left) >= abs(N - 1 - right)) ? b[right] : b[left]);
}
 
int main(void) {
    cin >> N;
    all = 2 * N - 1;
    a.resize(all);
    REP(i, all) scanf("%d", &a[i]);
    int high = all, low = 0;
    while (high - low > 1) {
	int mid = (high + low) / 2;
	(check(mid) ? low : high) = mid;
    }
    cout << low << endl;
}
