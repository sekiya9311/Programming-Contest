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

long long gcd(long long a, long long b) {
    if(a < b) swap(a, b);
    long long ret = 1;
    while(b) {ret = b; b = a % b; a = ret;}
    return ret;
}
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

inline LL calc(LL x, LL y, LL z) {
    LL n1 = (2 * x * y * z);
    LL n2 = (x * y + y * z + z * x);
    if (n1 % n2 != 0) return -1;
    return n1 / n2;
}

int N;
bool ok = false;

int main(void) {
    cin >> N;
    if (N == 1) {
        cout << -1 << endl;
        return 0;
    }
    FOR(i, N + 1, INF + 1) {
        FOR(j, 0, i) {
            LL ma = lcm(N, lcm(i, j));
            if (ma > INF) break;
            if (i == ma || j == ma) continue;
            LL num = calc(i, j, ma);
            if (num == N) {
                VL ans{i, j, ma};
                SORT(ans);
                REP(i, 3) {
                    cout << (i ? " " : "") << ans[i];
                }
                cout << endl;
                return 0;
            }
            if (num > N) break;
        }
    }
    cout << -1 << endl;
}
