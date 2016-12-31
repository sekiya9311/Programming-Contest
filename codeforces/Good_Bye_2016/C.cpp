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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N;
VPII cd;

int main(void) {
    scanf("%d", &N);
    cd.resize(N);
    bool containstwo = false;
    bool restriction = false;
    REP(i, N) {
        int c, d;
        scanf("%d%d", &c, &d);
        containstwo |= (d == 2);
        if (restriction && (cd[i - 1].second != d)) {
            cout << "Impossible" << endl;
            return 0;
        }
        restriction = ((c >= 0 && d == 1) || (c <= 0 && d == 2));
        cd[i] = MP(c, d);
    }
    if ((!containstwo)) {
        cout << "Infinity" << endl;
        return 0;
    }
    LL high, low;
    high = LLINF, low = -LLINF;
    REP(i, N) {
        int c, d;
        tie(c, d) = cd[i];
        if (d == 1) {
            low = max(low, 1900ll);
        } else {
            high = min(high, 1899ll);
        }
        low += c;
        high += c;
    }
    if (low > high) {
        cout << "Impossible" << endl;
    } else {
        cout << high << endl;
    }
}
