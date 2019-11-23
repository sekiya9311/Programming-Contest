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
#include <functional>

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
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 200010;
int M;
int d[MAX];
LL C[MAX];

unordered_map<LL, pair<LL, int>> memo[10];

pair<LL, int> calc(int digit, LL count) {
    if (memo[digit].count(count)) {
        return memo[digit][count];
    } else if (count == 1) {
        return memo[digit][count] = {0, digit};
    }

    const auto half = calc(digit, count / 2);
    LL res = half.first * 2;
    int dig = half.second * 2;
    res++;
    if (dig >= 10) {
        dig = dig / 10 + dig % 10;
        res++;
    }
    if (count % 2) {
        dig += digit;
        res++;
        if (dig >= 10) {
            dig = dig / 10 + dig % 10;
            res++;
        }
    }

    return memo[digit][count] = {res, dig};
}

int main(void) {
    cin >> M;
    REP(i, M) {
        cin >> d[i] >> C[i];
    }

    LL ans = 0;
    VI last_d;
    REP(i, M) {
        const auto res = calc(d[i], C[i]);
        ans += res.first;
        last_d.EB(res.second);
    }

    int prev = last_d[0];
    FOR(i, 1, last_d.size()) {
        prev += last_d[i];
        ans++;
        if (prev >= 10) {
            prev = prev / 10 + prev % 10;
            ans++;
        }
    }

    cout << ans << endl;
}
