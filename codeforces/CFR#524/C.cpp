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

const int MAX = 1e3 + 10;
int T;

bool is_black(LL x, LL y) {
    return (x % 2) ^ (y % 2);
}

int main(void) {
    scanf("%d", &T);
    while (T--) {
        LL N, M;
        scanf("%lld%lld", &N, &M);
        LL x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        LL xx1, yy1, xx2, yy2;
        scanf("%lld%lld%lld%lld", &xx1, &yy1, &xx2, &yy2);


        LL dub_w = 0, dub_b = 0;
        {
            LL sx = max(x1, xx1);
            LL sy = max(y1, yy1);
            LL gx = min(x2, xx2);
            LL gy = min(y2, yy2);
            LL dx = gx - sx + 1;
            LL dy = gy - sy + 1;
            if (dx > 0 && dy > 0) {
                if ((dx % 2) && (dy % 2)) {
                    dub_w = (dx * dy) - ((dx * dy) / 2 + is_black(sx, sy));
                    dub_b = (dx * dy) - dub_w;
                } else {
                    dub_w = (dx * dy) / 2;
                    dub_b = (dx * dy) / 2;
                }
            }
        }
        LL black, white;
        black = (N * M) / 2 - dub_b;
        white = (N * M) / 2 + ((N % 2) && (M % 2)) - dub_w;

        //cerr << white << " " << black << endl;
        if (((x2 - x1 + 1) % 2) && ((y2 - y1 + 1) % 2)) {
            LL dd = (x2 - x1 + 1) * (y2 - y1 + 1) / 2 + is_black(x1, y1) - dub_b;
            white += dd;
            black -= dd;
        } else {
            LL dd = (x2 - x1 + 1) * (y2 - y1 + 1) / 2 - dub_b;
            white += dd;
            black -= dd;
        }
        //cerr << white << " " << black << endl;

        if (((xx2 - xx1 + 1) % 2) && ((yy2 - yy1 + 1) % 2)) {
            LL dd = (xx2 - xx1 + 1) * (yy2 - yy1 + 1) / 2 + !is_black(xx1, yy1) - dub_w;
            white -= dd;
            black += dd;
        } else {
            LL dd = (xx2 - xx1 + 1) * (yy2 - yy1 + 1) / 2 - dub_w;
            white -= dd;
            black += dd;
        }
    //    cerr << white << " " << black << endl;
    //    DEBUG(dub_w)
    //    DEBUG(dub_b)
        cout << white << " " << black + dub_w + dub_b << endl;
    }
}
