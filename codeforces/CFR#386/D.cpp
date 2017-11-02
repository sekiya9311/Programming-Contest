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
template<typename T> using VT = vector<T>;
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

int n, k, green, black;
const string ng = "NO";

int main(void) {
    cin >> n >> k >> green >> black;
    int G = green, B = black;
    string ans = "";
    int cnt = 0;
    const string ss = "BG";
    int now;
    REP(i, n) {
        now = green >= black;
        if (i && cnt == k && ss[now] == ans[i - 1]) {
            now = (now + 1) % 2;
        }
        if ((now == 1 && green == 0) || (now == 0 && black == 0)) {
            now = (now + 1) % 2;
            if (i && ss[now] != ans[i - 1]) {
            } else if (cnt == k) {
                cout << ng << endl;
                return 0;
            }
        }
        ans += ss[now];
        if (i == 0 || (i && ans[i] == ans[i - 1])) cnt++;
        else cnt = 1;
        if (now) green--;
        else black--;
    }
    //DEBUG(ans)
    if (green == 0 && black == 0) cout << ans << endl;
    else cout << ng << endl;
}
