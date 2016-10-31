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
const int MOD = INF+7;
const LL LLINF = 1e18;

/* NOT AC */

int n, k;
VI a, b;
//n : 最初のモンスターの数　，　a[] : モンスターの最初の重み
//k : joke後のモンスターの数　，　b[] : joke後のモンスターの重み
vector<pair<int, string>> ans;

int main(void) {
    scanf("%d", &n);
    a.resize(n);
    int dif = 0;
    REP(i, n) {
        scanf("%d", &a[i]);
        if (i != 0) dif = max(dif, abs(a[i] - a[i - 1]));
    }
    scanf("%d", &k);
    b.resize(k);
    REP(i, k) scanf("%d", &b[i]);
    if (a == b) {
        cout << "YES" << endl;
        return 0;
    }
    int asum = accumulate(ALL(a), 0);
    int bsum = accumulate(ALL(b), 0);
    if (asum != bsum || (dif == 0 && a != b)) {
        cout << "NO" << endl;
        return 0;
    }
    VPII seg(k);
    int l, r;
    l = 0, r = 0;
    auto bbuf = b;
    REP(i, k) {
        while (bbuf[i] > 0 && r < n) {
            bbuf[i] -= a[r++];
        }
        if (bbuf[i] != 0) {
            cout << "NO" << endl;
        }
        seg[i] = MP(l, r + 1);
        l = r + 1; r = l;
        if (l >= n && i + 1 != k) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (l < n) {
         cout << "NO" << endl;
         return 0;
    }
    vector<VPII> segvec(k); //(num, id)
    REP(i, k) {
        FPRE(el, seg) {
            FOR(j, el.first, el.second) {
                segvec[i].EB(MP(a[j], j));
            }
        }
        RSORT(segvec[i]);
    }
    FORE(vec, segvec) {

    }
    return 0;
}
