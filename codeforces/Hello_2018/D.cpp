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

const int MAX = 2e5 + 10;
int n;
LL T;
int a[MAX], t[MAX];
pair<PII, int> pa[MAX];// t[i], a[i], idx

unordered_set<int> func(int size) {
    unordered_set<int> ret;
    LL tbuf = T;
    FORE(e, pa) {
        int aa = a[e.second];
        int tt = t[e.second];
        if (size <= aa && tbuf >= tt && ret.size() < size) {
            ret.emplace(e.second);
            tbuf -= tt;
        }
    }
    return ret;
}

int main(void) {
    scanf("%d%lld", &n, &T);
    REP(i, n) {
        scanf("%d%d", a + i, t + i);
        pa[i] =  MP(MP(t[i], a[i]), i);
    }
    sort(pa, pa + n);
    int ok = 0, ng = n + 1;
    while (ng - ok > 1) {
        const int mid = (ok + ng) / 2;
        if (func(mid).size() == mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    auto ans = func(ok);
    printf("%d\n", (int) ans.size());
    printf("%d\n", (int) ans.size());
    FORE(e, ans) {
        printf("%d ", e + 1);
    }
    puts("");
}
