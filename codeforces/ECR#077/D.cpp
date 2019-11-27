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

struct trap_type {
    int l, r, d;
};

const int MAX = 2e5 + 10;
int M, N, K, T;
int a[MAX];
trap_type trap[MAX];
int max_d;
unordered_set<int> rem;

int check2(int mi) {
    VPII vec;
    REP(i, K) if (trap[i].d > mi) {
        vec.EB(trap[i].l, trap[i].r);
    }
    SORT(vec);

    int res = 0;
    int cur_l = 0, cur_r = 0;
    FORE(t, vec) {
        if (t.first > t.second) {
            cur_l = t.first;
            chmax(cur_r, t.second);
            continue;
        }

        cur_l = t.first - 1;
        if (cur_r < t.second) {
            res += t.second - max(cur_l, cur_r);
            cur_r = t.second;
        }
        cur_l = t.first;
        chmax(cur_r, t.second);
    }
    return res * 2;
}

bool check(int count) {
    const int mi = a[count - 1];
    const int nokori_t = T - check2(mi);
    //cerr << count << " " << check2(mi) << endl;
    return nokori_t >= N + 1;
}

int main(void) {
    scanf("%d%d%d%d", &M, &N, &K, &T);
    REP(i, M) {
        scanf("%d", a + i);
    }
    sort(a, a + M);
    reverse(a, a + M);
    REP(i, K) {
        scanf("%d%d%d", &trap[i].l, &trap[i].r, &trap[i].d);
    }

    if (N + 1 > T) {
        cout << 0 << endl;
        return 0;
    }

    int ok = 0, ng = M + 1;
    while (ng - ok > 1) {
        const int mid = (ok + ng) / 2;
        if (check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}
