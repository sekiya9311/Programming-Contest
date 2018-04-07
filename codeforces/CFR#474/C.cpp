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

const int MAX = 1e4;
LL X, d;
LL ans[MAX];

void hoge() {
    if (X <= 1e4) {
        LL now = 1;
        REP(i, X) {
            ans[i] = now;
            now += d;
        }
        REP(i, X) {
            printf("%lld%c", ans[i], (i + 1 == X ? '\n' : ' '));
        }
    } else {
        assert(false);
    }
}

int main(void) {
    cin >> X >> d;
    LL now = 1;
    int idx = 1;
    LL val = 0;
    int pre = 1;
    while (now < X) {
        if (now + (1LL << (idx - pre + 1)) <= X) {
            ans[idx] = val;
            now += (1LL << (idx - pre + 1));
        } else {
            ans[idx] = val + d;
            val += d;
            pre = idx + 1;
            now++;
        }
        //DEBUG(now)
        idx++;
        if (idx == MAX) break;
    }
    if (now < X) {
        puts("-1");
        return 0;
    }
    printf("%d\n", idx);
    REP(i, idx) printf("%lld%c", ans[i] + 1, (i + 1 == idx ? '\n' : ' '));
}
