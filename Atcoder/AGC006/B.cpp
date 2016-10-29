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

int main(void) {
    int N, x;
    cin >> N >> x;
    if (x == 1 || x == (2 * N) - 1) {
         cout << "No" << endl;
         return 0;
    }else {
        cout << "Yes" << endl;
    }
    int all = (2 * N - 1);
    int mid = (all / 2) + 1;
    if (mid == x) {
        REP(i, all) {
            cout << i + 1 << endl;
        }
    } else if (mid < x) {
        int buf = 0;
        REP(i, all / 2) {
            cout << i + 1 << endl;
            buf = i + 1;
        }
        cout << x << endl;
        RREP(i, all) {
            if (i + 1 == x) continue;
            if (i + 1 == buf) break;
            cout << i + 1 << endl;
        }
    } else {
        int buf = 0;
        RREP(i, mid) {
            if (i + 1 == x) continue;
            cout << i + 1 << endl;
        }
        cout << x << endl;
        FOR(i, mid, all) {
            cout << i + 1 << endl;
        }
    }
}
