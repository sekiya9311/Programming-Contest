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

const int MAX = 200010;
char strbuf[MAX];
string next() {
    scanf("%s", strbuf);
    return strbuf;
}

int n;
int a[MAX];
string S;
VVI vv;
VI v;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", a + i);
    }
    S = next();
    REP(i, n - 1) {
        v.EB(a[i]);
        if (S[i] == '0') {
            SORT(v);
            vv.EB(v);
            int ma = v.back();
            v.clear();
            v.EB(ma);
        }
    }
    v.EB(a[n - 1]);
    SORT(v);
    vv.EB(v);
    int now = 1;
    VI vec;
    // FORE(e, vv) {
    //     FORE(ee, e) cerr << ee << " ";cerr << endl;
    // }
    REP(i, vv.size()) {
        if (0 < i && vv[i - 1].back() != vv[i][0]) {
            cout << "NO" << endl;
            return 0;
        }
        FOR(j, i != 0, vv[i].size()) {
            vec.EB(vv[i][j]);
        }
    }

    FORE(e, vec) if (e != now++) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}
