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

const int MAX = 1e5 + 10;
int N;
int A[MAX];

inline void decrease_map(map<int, int> &mp, int key) {
    if (mp[key] == 1) {
        mp.erase(key);
    } else {
        mp[key]--;
    }
}

VT<PLL> pre_ans;
LL calc(int cnt) {
    map<int, int> mp;
    REP(i, N) {
        mp[A[i]]++;
    }

    REP(i, N - 1) {
        const auto l = *begin(mp);
        const auto r = *rbegin(mp);
        if (i < cnt) {
            auto nxt = l.first - r.first;
            if (chmin(nxt, r.first - l.first)) {
                pre_ans[i] = {r.first, l.first};
            } else {
                pre_ans[i] = {l.first, r.first};
            }
            decrease_map(mp, l.first);
            decrease_map(mp, r.first);
            mp[nxt]++;
        } else {
            auto nxt = l.first - r.first;
            if (chmax(nxt, r.first - l.first)) {
                pre_ans[i] = {r.first, l.first};
            } else {
                pre_ans[i] = {l.first, r.first};
            }
            decrease_map(mp, l.first);
            decrease_map(mp, r.first);
            mp[nxt]++;
        }
    }

    return begin(mp)->first;
}

int main(void) {
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    pre_ans.resize(N - 1);

    int low = 0, high = N - 1;
    while (high - low > 10) {
        const auto mid1 = (low + low + high) / 3;
        const auto mid2 = (low + high + high) / 3;

        const auto c1 = calc(mid1);
        const auto c2 = calc(mid2);
        if (c1 >= c2) {
            high = mid2;
        } else {
            low = mid1;
        }
    }

    LL ans = -LLINF;
    VT<PLL> ans_route;
    FOR(i, low, high) {
        if (chmax(ans, calc(i))) {
            ans_route = pre_ans;
        }
    }

    printf("%lld\n", ans);
    FORE(e, ans_route) {
        printf("%lld %lld\n", e.first, e.second);
    }

}
