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

int N;
VPII G[55];
int A[55], B[55];
int M;
int u[22], v[22];
LL route_idxes_mask[55][55];
LL rest_mask[22];

void make_route_internal(const int cur, const int par, LL cur_route_idxes_mask, const int root) {

    route_idxes_mask[root][cur] = cur_route_idxes_mask;

    FORE(el, G[cur]) if (el.first != par) {
        cur_route_idxes_mask |= (1LL << el.second);
        make_route_internal(el.first, cur, cur_route_idxes_mask, root);
        cur_route_idxes_mask ^= (1LL << el.second);
    }
}

void make_route() {
    REP(i, N) {
        make_route_internal(i, -1, 0, i);
    }
}

int main(void) {
    cin >> N;
    REP(i, N - 1) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].EB(B[i], i);
        G[B[i]].EB(A[i], i);
    }
    cin >> M;
    REP(i, M) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    make_route();
    REP(i, M) {
        rest_mask[i] = route_idxes_mask[u[i]][v[i]];
    }

    LL ans = 0;
    REP(bit, (1 << M)) {
        LL cur_mask = 0;
        REP(i, M) if (bit & (1 << i)) {
            cur_mask |= rest_mask[i];
        }

        const int bit_count = __builtin_popcountll(cur_mask);

        if (__builtin_parity(bit)) {
            ans -= 1LL << (N - 1 - bit_count);
        } else {
            ans += 1LL << (N - 1 - bit_count);
        }
        //DEBUG(ans)
    }

    cout << ans << endl;
}
