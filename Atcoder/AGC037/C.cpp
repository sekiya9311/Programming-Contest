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

const int MAX = 2e5 + 10;
int N;
LL A[MAX], B[MAX];

int main(void) {
    scanf("%d", &N);
    REP(i, N) scanf("%lld", A + i);
    REP(i, N) scanf("%lld", B + i);

    auto comp = [&](const int l_idx, const int r_idx) {
        return B[l_idx] - A[l_idx] < B[r_idx] - A[r_idx];
    };
    priority_queue<int, VI, decltype(comp)> pq(comp);
    REP(i, N) {
        if (A[i] < B[i]) pq.emplace(i);
        else if (A[i] > B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    LL cnt = 0;
    while (!pq.empty()) {
        const auto cur_idx = pq.top();
        pq.pop();

        const int pre_idx = (cur_idx - 1 + N) % N;
        const int nxt_idx = (cur_idx + 1) % N;

        const LL cur_minus = B[pre_idx] + B[nxt_idx];

        const LL times = (B[cur_idx] - A[cur_idx]) / cur_minus;

        const LL minus = cur_minus * times;

        const LL val = B[cur_idx] - minus;
        if (times == 0 || val < A[cur_idx]) {
            cout << -1 << endl;
            return 0;
        }
        B[cur_idx] = val;
        if (A[cur_idx] != B[cur_idx]) {
            pq.emplace(cur_idx);
        }

        cnt += times;
    }

    cout << cnt << endl;
}
