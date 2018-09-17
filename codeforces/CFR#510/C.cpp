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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 2e5 + 10;
int N;
LL a[MAX];

using state = pair<LL, int>;//(val, idx)
int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld", a + i);
    }
    VI del_idx;
    priority_queue<pair<LL, int>> plus, minus;
    {
        VI zero;
        REP(i, N) {
            if (a[i] > 0) {
                plus.emplace(a[i], i);
            } else if (a[i] < 0) {
                minus.emplace(-a[i], i);
            } else {
                zero.EB(i);
            }
        }
        if (plus.empty() && minus.size() <= 1) {
            int master = -1;
            if (minus.size() == 1) {
                master = minus.top().second;
            }
            REP(i, (int)zero.size() - 1) {
                if (master == -1) master = zero[i];
                 else printf("1 %d %d\n", zero[i] + 1, master + 1);
            }
            if (master != -1) printf("2 %d\n", master + 1);
            return 0;
        } else {
            //FORE(e, zero) printf("2 %d\n", e + 1);
            FORE(e, zero) del_idx.EB(e);
        }
    }
    int minus_idx = -1;
    if (minus.size() > 1) {
        auto ma = minus.top();
        minus_idx = ma.second;
        minus.pop();
        bool now_minus = true;
        while (true) {
            if (minus.size() == 1 && !now_minus) {
                break;
            } else if (minus.empty()) {
                break;
            }
            auto now = minus.top();
            minus.pop();
            printf("1 %d %d\n", now.second + 1, ma.second + 1);
            now_minus = !now_minus;
        }
        if (minus.size()) {
            auto now = minus.top();
            del_idx.EB(now.second);
            //printf("2 %d\n", now.second + 1);
        }
    } else if (minus.size() == 1) {
        del_idx.EB(minus.top().second);
        //printf("2 %d\n", minus.top().second + 1);
    }
    if (plus.size()) {
        auto ma = plus.top();
        plus.pop();
        while (!plus.empty()) {
            auto now = plus.top();
            plus.pop();
            printf("1 %d %d\n", now.second + 1, ma.second + 1);
        }
        if (minus_idx != -1) {
            printf("1 %d %d\n", ma.second + 1, minus_idx + 1);
        }
    }
    {
        int master = -1;
        REP(i, (int)del_idx.size()) {
            if (i == 0) master = del_idx[i];
            else printf("1 %d %d\n", del_idx[i] + 1, master + 1);
        }
        if (master != -1) printf("2 %d\n", master + 1);
    }
}
