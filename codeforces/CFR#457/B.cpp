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

// Counterexample exists !!

const int MAX = 1e5 + 10;
LL N, K;
set<LL> beki2;
LL ans[MAX];

int main(void) {
    cin >> N >> K;
    REP(i, 62) beki2.emplace(1ll << i);

    int ptr = 0;
    REP(i, 60) {
        if (N & (1ll << i)) {
            ans[ptr++] = i;
        }
    }
    bool ok = true;
    if (ptr > K) {
        ok = false;
    } else if (ptr < K) {
        priority_queue<LL> pq;
        REP(i, ptr) {
            pq.emplace(ans[i]);
        }
        while (pq.size() < K) {
            LL ma = pq.top();
            pq.pop();
            ma--;
            REP(i, 2) pq.emplace(ma);
        }
        if (pq.size() > K) {
            ok = false;
        } else {
            ptr = 0;
            while (!pq.empty()) {
                ans[ptr++] = pq.top();
                pq.pop();
            }
        }
    }

    if (ok) {
        puts("Yes");
        sort(ans, ans + K);
        reverse(ans, ans + K);
        REP(i, K) {
            printf("%lld%c", ans[i], (i + 1 == K ? '\n' : ' '));
        }
    } else {
        puts("No");
    }
}
