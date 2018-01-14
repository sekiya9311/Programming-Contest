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
int K;
LL A[MAX];

int main(void) {
    cin >> K;
    REP(i, K) {
        cin >> A[i];
    }
    if (A[K - 1] > 2) {
        cout << -1 << endl;
        return 0;
    }
    LL mi = 2;
    {
        RREP(i, K) {
            mi = A[i] * (mi / A[i] + (mi % A[i] != 0));
        }
    }
    LL ma = 0;
    {
        LL ok = mi, ng = LLINF;
        while (ng - ok > 1) {
            const LL mid = ok + (ng - ok) / 2;
            LL now = mid;
            REP(i, K) {
                now -= now % A[i];
            }
            if (now == 2) ok = mid;
            else ng = mid;
        }
        {
            LL now = ok;
            REP(i, K) {
                now -= now % A[i];
            }
            if (now == 2) ma = ok;
            else ma = -1;
        }
    }
    if (ma == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << mi << " " << ma << endl;
}
