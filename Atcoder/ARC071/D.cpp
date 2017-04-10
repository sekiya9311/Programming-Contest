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

const int MAX = 1e5 + 10;
int N, M;
LL x[MAX], y[MAX];
LL xdif[MAX], ydif[MAX];
LL xsum[MAX], ysum[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, N) {
        scanf("%lld", x + i);
        if (i) {
            xdif[i - 1] = (x[i] - x[i - 1]) % MOD;
        }
    }
    REP(i, M) {
        scanf("%lld", y + i);
        if (i) {
            ydif[i - 1] = (y[i] - y[i - 1]) % MOD;
        }
    }
    LL Y = 0, X = 0;
    REP(i, N - 1) {
        if (i == 0) xsum[i] = xdif[i];
        else xsum[i] = (xdif[i] + xsum[i - 1]) % MOD;
    }
    REP(i, M - 1) {
        if (i == 0) ysum[i] = ydif[i];
        else ysum[i] = (ydif[i] + ysum[i - 1]) % MOD;
    }
    REP(i, N - 2) (xsum[i + 1] += xsum[i]) %= MOD;
    //REP(i, N - 2) (xsum[i + 1] += xsum[i]) %= MOD;
    REP(i, M - 2) (ysum[i + 1] += ysum[i]) %= MOD;
    //REP(i, M - 2) (ysum[i + 1] += ysum[i]) %= MOD;
    LL buf = xsum[N - 2];
    REP(i, N - 1) {
        if (i) buf = (buf - (xdif[i - 1] * (N - i) % MOD) + MOD) % MOD;
        (X += buf) %= MOD;
        //DEBUG(X)
    }
    buf = ysum[M - 2];
    REP(i, M - 1) {
        if (i) buf = (buf - (ydif[i - 1] * (M - i) % MOD) + MOD) % MOD;
        (Y += buf) %= MOD;
        //DEBUG(Y)
    }
    //REP(i, N - 1) cerr << xsum[i]<<" ";cerr<<endl;
    //REP(i, M - 1) cerr << ysum[i]<<" ";cerr <<endl;
    //cerr << X << " " << Y << endl;
    cout << (X * Y) % MOD << endl;
}
