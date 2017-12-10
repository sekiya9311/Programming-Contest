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
#define EF emplace_front
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 55;
const int MAX_VAL = 1e6;
int N;
LL a[MAX];

int main(void) {
    cin >> N;
    LL ma = -MAX_VAL, mi = MAX_VAL;
    int maId = -1, miId = -1;
    REP(i, N) {
        cin >> a[i];
        if (chmax(ma, a[i])) {
            maId = i;
        }
        if (chmin(mi, a[i])) {
            miId = i;
        }
    }
    deque<PII> ans;
    if (mi <= 0 && ma <= 0) {
        REP(i, N - 1) {
            ans.EF(i + 1, i);
        }
    } else if (mi >= 0 && ma >= 0) {
        REP(i, N - 1) {
            ans.EB(i, i + 1);
        }
    } else {
        // mi < 0 && ma > 0
        if (llabs(mi) <= llabs(ma)) {
            REP(i, N) {
                ans.EB(maId, i);
            }
            REP(i, N - 1) {
                ans.EB(i, i + 1);
            }
        } else {
            REP(i, N - 1) {
                ans.EF(i + 1, i);
            }
            REP(i, N) {
                ans.EF(miId, i);
            }
        }
    }

    cout << ans.size() << endl;
    FORE(e, ans) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }

    FORE(e, ans) {
        a[e.second] += a[e.first];
    }
    cerr << (is_sorted(a, a + N) ? "YES" : "NO") << endl;
    REP(i, N) {
        cerr << a[i] << " ";
    }cerr << endl;
}
