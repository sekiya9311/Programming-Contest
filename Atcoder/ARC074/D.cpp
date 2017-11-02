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

const int MAX = 3 * 1e5 + 10;
int N;
long long a[MAX], l[MAX], r[MAX];
 
int main() {
    scanf("%d", &N);
    for (int i = 0; i < 3 * N; ++i) {
        scanf("%lld", a + i);
    }
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    priority_queue<long long> pq2;
    for (int i = 0; i < N; ++i) {
        l[0] += a[i];
        r[0] += a[N * 2 + i];
        pq.push(a[i]);
        pq2.push(a[N * 2 + i]);
    }
    for (int i = 0; i < N; ++i) {
        pq.push(a[N + i]);
        l[i + 1] = l[i] + a[N + i] - pq.top();
        pq.pop();
        pq2.push(a[2 * N - i - 1]);
        r[i + 1] = r[i] + a[2 * N - i - 1] - pq2.top();
        pq2.pop();
    }
    long long ans = -LLINF;
    for (int i = 0; i <= N; ++i) {
        ans = max(ans, l[i] - r[N - i]);
    }
    printf("%lld\n", ans);
}
