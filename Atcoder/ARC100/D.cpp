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

const int MAX = 2e5 + 10;
int N;
LL A[MAX];

LL get(int l, int r) {
    // [l, r)
    //cerr << l << " " << r << endl;
    //cerr << A[r] - A[l] << endl;
    return A[r] - A[l];
}

int main(void) {
    cin >> N;
    REP(i, N) cin >> A[i + 1];
    REP(i, N) A[i + 1] += A[i];
    LL ans = LLINF;
    FOR(i, 2, N - 1) {
        VT<PLL> l, r;
        {
            int low = 1, high = i;
            while (high - low > 1) {
                const int mid = (low + high) >> 1;
                if (get(mid, i) - get(0, mid) >= 0) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            FOR(j, low - 2, low + 3) {
                if (0 < j && j < i) l.EB(get(0, j), get(j, i));
            }
        }
        {
            int low = i + 1, high = N;
            while (high - low > 1) {
                const int mid = (low + high) >> 1;
                if (get(mid, N) - get(i, mid) >= 0) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            FOR(j, low - 2, low + 3) {
                if (i < j && j < N) r.EB(get(i, j), get(j, N));
            }
        }
        FORE(le, l) FORE(re, r) {
            VL vec;
            vec.EB(le.first);
            vec.EB(le.second);
            vec.EB(re.first);
            vec.EB(re.second);
            SORT(vec);
            chmin(ans, vec.back() - vec.front());
        }
    }
    cout << ans << endl;
}
