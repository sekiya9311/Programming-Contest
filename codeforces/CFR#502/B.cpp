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

const int MAX = 1e5 + 10;
int zz[MAX], zo[MAX], oz[MAX], oo[MAX];

int main(void) {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;
    REP(i, N) {
        if (A[i] == '0' && B[i] == '0') zz[i + 1] = 1;
        else if (A[i] == '1' && B[i] == '0') oz[i + 1] = 1;
        else if (A[i] == '0' && B[i] == '1') zo[i + 1] = 1;
        else oo[i + 1] = 1;
    }
    REP(i, N) {
        zz[i + 1] += zz[i];
        oz[i + 1] += oz[i];
        zo[i + 1] += zo[i];
        oo[i + 1] += oo[i];
    }
    LL ans = 0;
    REP(i, N) {
        if (A[i] == '0' && B[i] == '0') ans += (oz[N] - oz[i]) + (oo[N] - oo[i]);
        else if (A[i] == '1' && B[i] == '0') ans += (zo[N] - zo[i]) + (zz[N] - zz[i]);
        else if (A[i] == '0' && B[i] == '1') ans += (oz[N] - oz[i]);
        else ans += (zz[N] - zz[i]);
    }
    cout << ans << endl;
}
