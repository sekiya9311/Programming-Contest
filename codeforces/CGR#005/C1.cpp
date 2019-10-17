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

const int MAX = 50010;
const int EASY_MAX = 2222;
int N;
LL x[MAX], y[MAX], z[MAX];

LL dist[EASY_MAX][EASY_MAX];
bool already[EASY_MAX];
pair<LL, int> ar[EASY_MAX];


int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld%lld%lld", x + i, y + i, z + i);
    }

    REP(i, N) REP(j, N) {
        dist[i][j] = llabs(x[i] - x[j]) + llabs(y[i] - y[j]) + llabs(z[i] - z[j]);
    }

    REP(i, N) {
        if (already[i]) continue;
        int ptr = 0;
        REP(j, N) if (i != j && !already[j]) {
            ar[ptr++] = {dist[i][j], j};
        }
        sort(ar, ar + ptr);
        printf("%d %d\n", i + 1, ar[0].second + 1);
        already[i] = true;
        already[ar[0].second] = true;
    }
}
