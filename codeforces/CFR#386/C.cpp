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


//トラム0からｓへ行く
//t1秒で1m進む
//iｇor x1からx2にt2秒で1m進む
//pトラムのスタート位置
//dトラムの最初の移動方向(-1 : s-> 0    1 : 0 -> s)
#define int double
int s, x1, x2;
int t1, t2;
int p, d;

int tim(int nowpoint, int nowtime) {
    int p_ = p, d_ = d;
    int trammove = nowtime / t1;
    while (true) {
        if (d_ == -1) {
            if (p_ - trammove < 0) {
                trammove -= p_;
                p_ = 0; d_ = 1;
            } else {
                break;
            }
        } else {
            if (p_ + trammove > s) {
                trammove -= s - p_;
                p_ = s; d_ = -1;
            } else {
                break;
            }
        }
    }
    int res = 0;
    if (nowpoint < x2) {
        if (d_ == -1) {
            if (nowpoint <= p_) {
                res += (p_ + nowpoint) * t1;
            } else {
                res += (p_ + nowpoint) * t1;
            }
            if (x2 <= s) {
                res += abs(x2 - nowpoint) * t1;
            } else {
                res += abs(s - nowpoint) * t1;
                res += abs(x2 - s) * t2;
            }
        } else {
            if (p_ <= nowpoint) {
                res += abs(nowpoint - p_) * t1;
            } else {
                res += (abs(s - p_) + s + nowpoint) * t1;
            }
            if (x2 <= s) {
                res += abs(x2 - nowpoint) * t1;
            } else {
                res += abs(s - nowpoint) * t1;
                res += abs(x2 - s) * t2;
            }
        }
    } else {
        if (d_ == -1) {
            if (nowpoint <= p_) {
                res += abs(nowpoint - p_) * t1;
            } else {
                res += (p_ + s + abs(s - nowpoint)) * t1;
            }
            res += abs(nowpoint - x2) * t1;
        } else {
            if (nowpoint <= p_) {
                res += (abs(s - p_) + abs(s - nowpoint)) * t1;
            } else {
                res += (abs(s - p_) + abs(s - nowpoint)) * t1;
            }
            res += abs(nowpoint - x2) * t1;
        }
    }
    //cout <<nowpoint<<" "<<p_<<" "<<d_<<" "<<res<<" "<<nowtime<<endl;
    return res + nowtime;
}

signed main(void) {
    cin >> s >> x1 >> x2;
    cin >> t1 >> t2;
    cin >> p >> d;
    int ma = abs(x1 - x2) * t2;
    if (x1 < x2) FOR(i, x1, x2+1) {
        ma = min(ma, tim(i, (i - x1) * t2));
    } else {
        for (int i = x1; i >= x2; i--) {
            ma = min(ma, tim(i, (x1 - i) * t2));
        }
    }
    cout << ma << endl;
}
