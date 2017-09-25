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

LL a;//距離
LL b;//タンク量
LL f;//ガソスタ
LL k;//片道k回

void dame(int ii) {
    DEBUG(ii)
    cout << -1 << endl;
    exit(0);
}

int main(void) {
    cin >> a >> b >> f >> k;
    int cnt = 0;
    LL now = b;
    REP(i, k) {
        DEBUG(i)DEBUG(now)
        DEBUG(cnt)
        if (i % 2 == 0) {
            // 0 -> a
            const LL need = (a - f) * 2;
            if (now < f) {//ガソスタまで行けない
                dame(0);
            }
            bool ff = false;
            if (i + 1 < k && now - f < need) {
                cnt++;
                now = b;
                ff = true;
            }
            else if (i + 1 == k && now - f < need / 2) {cnt++;now = b;ff = true;}
            else now -= f;
            now -= need / 2;
        } else {
            //a -> 0
            const LL need = (a - f);
            if (now < need) {
                dame(1);
            }
            now -= need;
            bool ff = false;
            if ((i + 1 < k && now < f * 2) || (i + 1 == k && now < f)) {
                now = b;
                cnt++;
                ff = true;
            }
            now -= f;
            if (now < 0) {
                dame(2);
            }
            if (i + 1 < k && now < f && !ff) {
                now = b;
                now -= f;
                cnt++;
            }
        }
        if (now < 0) dame(3);
    }
    cout << cnt << endl;
}
