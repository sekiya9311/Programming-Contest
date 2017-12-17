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

int n;
string strN;
const int nines[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

int naive(int ma) {
    int ans = 0;
    FOR(i, 1, n + 1) {
        FOR(j, i + 1, n + 1) {
            const int val = i + j;
            if (val % (int)pow(10, ma + 1) == nines[ma]) {
                //cout << i << " " << j << endl;
                ans++;
            }
        }
    }
    //cout << ans << endl;
    return ans;
}
LL fast(int ma) {
    LL ans = 0;
    REP(i, 9) {
        const LL getVal = stoll(to_string(i) + to_string(nines[ma]));
        if (getVal > n * 2 || getVal / 2 > n) {
            break;
        }
        LL low = 0, high = getVal / 2;
        while (high - low > 1) {
            const LL mid = (high + low) / 2;
            if (mid <= n && getVal - mid <= n) {
                high = mid;
            } else {
                low = mid;
            }
        }
        ans += getVal / 2 - high + 1;
    }
    cout << ans << endl;
    return ans;
}

int main(void) {
    cin >> n;
    strN = to_string(n);
    int ma = -1;
    REP(i, 9) {
        if (n * 2 >= nines[i]) {
            ma = i;
        }
    }
    if (ma == -1) {
        cout << n * (n - 1) / 2 << endl;
        return 0;
    }
    //LL buf1 = naive(ma);
    LL buf2 = fast(ma);
    //assert(buf1 == buf2);
}
