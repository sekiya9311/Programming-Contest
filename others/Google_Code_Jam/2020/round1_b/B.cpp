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
#include <random>

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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

char ask(LL w, LL h) {
    cout << w << " " << h << endl;
    string res;
    cin >> res;
    if (res[0] == 'W') exit(1);
    if (res[0] == 'C') throw 123;
    return res[0];
}

const int MAX = 1e9;
random_device rnd;
void solve(const LL A, const LL B) {

    int sh, sw;
    while (true) {
        const int cur_h = rnd() % (MAX * 2 + 1) - MAX;
        const int cur_w = rnd() % (MAX * 2 + 1) - MAX;
        if (ask(cur_h, cur_w) == 'H') {
            sh = cur_h;
            sw = cur_w;
            break;
        }
    }

    int top, down, left, right;
    {
        // 右端
        int ok = sw, ng = MAX + 1;
        while (ng - ok > 1) {
            const int mid = ok + (ng - ok) / 2;
            if (ask(mid, 0) == 'H') {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        right = ok;
    }
    {
        // 上端
        int ok = sh, ng = MAX + 1;
        while (ng - ok > 1) {
            const int mid = ok + (ng - ok) / 2;
            if (ask(0, mid) == 'H') {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        top = ok;
    }
    {
        // 左端
        int ok = sw, ng = -MAX - 1;
        while (ok - ng > 1) {
            const int mid = ng + (ok - ng) / 2;
            if (ask(mid, 0) == 'H') {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        left = ok;
    }
    {
        // 下端
        int ok = sh, ng = -MAX - 1;
        while (ok - ng > 1) {
            const int mid = ng + (ok - ng) / 2;
            if (ask(0, mid) == 'H') {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        down = ok;
    }

    ask((left + right) / 2, (top + down) / 2);
}

int main() {
    int T, A, B;
    cin >> T >> A >> B;
    while (T--) {
        try {
            solve(A, B);
        }
        catch (int ex) {

        }
    }
}
