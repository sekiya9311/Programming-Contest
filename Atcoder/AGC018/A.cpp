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


long long gcd(long long a, long long b) {
    if(a < b) swap(a, b);
    long long ret = 1;
    while(b) {ret = b; b = a % b; a = ret;}
    return ret;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

const int MAX = 1e5 + 10;
LL N, K;
LL A[MAX];
const string ok = "POSSIBLE";
const string ng = "IMPOSSIBLE";
set<LL> se;

int main(void) {
    scanf("%lld%lld", &N, &K);
    LL ma = 0;
    bool exist = false;
    bool odd = false;
    REP(i, N) {
        scanf("%lld", A + i);
        chmax(ma, A[i]);
        exist |= A[i] == K;
        se.insert(A[i]);
        odd |= (A[i] % 2);
    }    
    if (exist) {
        cout << ok << endl;
        return 0;
    }
    if (se.size() == 1) {
        cout << ng << endl;
        return 0;
    }
    if (ma < K) {
        cout << ng << endl;
        return 0;
    }
    sort(A, A + N);
    bool f = false;
    LL mi = LLINF;
    LL gcdNum = A[0];
    REP(i, N) gcdNum = gcd(gcdNum, A[i]);
    REP(i, N - 1) {
        f |= (se.count(A[i + 1] - A[i]) == 0);
        chmin(mi, A[i + 1] - A[i]);
    }
    if (f) {
        if (K % gcdNum == 0) cout << ok << endl;
        else cout << ng << endl;
    }
    else {
        cout << ng << endl;
    }
}
