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
#include <chrono>

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
template<typename T>inline bool chmax(T &a, T b){return (a < b ? a = b, true : false);}
template<typename T>inline bool chmin(T &a, T b){return (a > b ? a = b, true : false);}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
const long double EPS = 1e-9;

long long gcd(long long a, long long b) {
	a = llabs(a);
	b = llabs(b);
    if(a < b) swap(a, b);
	if (b == 0) return a;
    long long ret = 1;
    while(b) {ret = b; b = a % b; a = ret;}
    return ret;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

const int MAX = 100010;
int N;
LL a[MAX];
int odd = 0, even = 0;

int main() {
	scanf("%d", &N);
	REP(i, N) {
		scanf("%lld", a + i);
	}
    LL buf = a[0];
    FOR(i, 1, N) {
        buf = gcd(buf, a[i]);
    }
    if (buf > 1) {
        cout << "YES" << "\n" << 0 << endl;
        return 0;
    }
    int cnt = 0;
    REP(i, N - 1) {
        while (a[i] % 2) {
            LL b1 = a[i] - a[i + 1];
            LL b2 = a[i] + a[i + 1];
            a[i] = b1;
            a[i + 1] = b2;
            ++cnt;
        }
    }
    int i = N - 2;
    while (a[i + 1] % 2) {
        LL b1 = a[i] - a[i + 1];
        LL b2 = a[i] + a[i + 1];
        a[i] = b1;
        a[i + 1] = b2;
        ++cnt;
    }
    cout << "YES" << "\n" << cnt << endl;
}
