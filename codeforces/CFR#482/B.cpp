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

const string KURO = "Kuro";
const string SHIRO = "Shiro";
const string KATIE = "Katie";
const string DRAW = "Draw";
LL N, L;
string kuro, shiro, katie;

LL calc(string S) {
    LL ma = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        LL change = 0, cnt = 0;
        FORE(e, S) {
            if (e == c) cnt++;
            else change++;
        }
        LL minus = max(0ll, N - change);
        if (minus % 2 == 0) {
            minus = 0;
        } else {
            minus %= (L + 1);
            if (minus == L) minus = 0;
        }
        chmax(ma, max(minus, cnt + min(change, N) - minus % 2));
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        LL change = 0, cnt = 0;
        FORE(e, S) {
            if (e == c) cnt++;
            else change++;
        }
        LL minus = max(0ll, N - change);
        if (minus % 2 == 0) {
            minus = 0;
        } else {
            minus %= (L + 1);
            if (minus == L) minus = 0;
        }
        chmax(ma, max(minus, cnt + min(change, N) - minus % 2));
    }
    return ma;
}

int main(void) {
    cin >> N;
    cin >> kuro >> shiro >> katie;
    L = kuro.length();
    LL kuroMa = calc(kuro);
    LL shiroMa = calc(shiro);
    LL katieMa = calc(katie);
    if (kuroMa > shiroMa && kuroMa > katieMa) {
        cout << KURO << endl;
    } else if (shiroMa > kuroMa && shiroMa > katieMa) {
        cout << SHIRO << endl;
    } else if (katieMa > kuroMa && katieMa > shiroMa) {
        cout << KATIE << endl;
    } else {
        cout << DRAW << endl;
    }
}
