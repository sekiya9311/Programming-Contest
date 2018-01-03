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

const int MAX = 1e5 + 10;
int N;
long long A[MAX], B[MAX];

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld", A + i);
    }
    long long ma = -1;
    REP(i, N) {
        scanf("%lld", B + i);
        chmax(ma, B[i]);
    }
    {
        {
            bool ok = true;
            REP(i, N) {
                if (B[i]) {
                    ok = false;
                }
            }
            if (ok) {
                cout << 1 << endl;
                return 0;
            }
        }
        {
            bool ok = true;
            REP(i, N) {
                if (A[i] != B[i]) {
                    ok = false;
                }
            }
            if (ok) {
                cout << ma + 1 << endl;
                return 0;
            }
        }

        REP(i, N) {
            if (A[i] < B[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    REP(i, N) {
        A[i] -= B[i];
    }
    long long gcd = A[0];
    FOR(i, 1, N) {
        gcd = __gcd(gcd, A[i]);
    }
    long long ans = LLINF;
    for (long long i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            long long a = i;
            long long b = gcd / i;
            if (a > ma) {
                chmin(ans, a);
            }
            if (b > ma) {
                chmin(ans, b);
            }
        }
    }

    if (ans <= 1 || ans == LLINF) ans = -1;
    cout << ans << endl;

}
