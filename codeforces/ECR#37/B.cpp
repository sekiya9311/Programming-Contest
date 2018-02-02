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

int main(void) {
    int t;
    scanf("%d", &t);
    REP(_, t) {
        int n;
        scanf("%d", &n);
        VI l(n), r(n);
        REP(i, n) {
            int a, b;
            scanf("%d%d", &a, &b);
            l[i] = a - 1;
            r[i] = b - 1;
        }
        VI ans(n, -1);
        int now = 0;
        while (true) {
            queue<int> qq;
            bool owari = true;
            REP(i, n) {
                if (ans[i] == -1) {
                    owari = false;
                }
                if (l[i] <= now && ans[i] == -1) {
                    qq.emplace(i);
                }
            }
            if (owari) break;
            if (!qq.empty()) {
                ans[qq.front()] = now + 1;
                qq.pop();
                while (!qq.empty()) {
                    if (r[qq.front()] <= now) {
                        ans[qq.front()] = 0;
                    }
                    qq.pop();
                }
            }
            now++;
        }
        REP(i, n) printf("%d%c", ans[i], i + 1 == n ? '\n' : ' ');
    }
}
