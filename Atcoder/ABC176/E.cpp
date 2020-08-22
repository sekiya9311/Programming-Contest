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

// StarrySkyTree, (区間加算，区間最小値or最大値)
// O(log N)
class starry_sky_tree {
private:
    const static long long inf = 1e18;
    const int N;
    std::vector<long long> add_vec, min_vec;
    std::function<bool(long long, long long)> comp;
    void add(int l, int r, long long val, int k, int L, int R) {
        if (R <= l || r <= L) {
            return;
        }
        if (l <= L && R <= r) {
            this->add_vec[k] += val;
            return;
        }
        this->add(l, r, val, k * 2 + 1, L, (L + R) / 2);
        this->add(l, r, val, k * 2 + 2, (L + R) / 2, R);
        this->min_vec[k] = std::min(add_vec[k * 2 + 1] + min_vec[k * 2 + 1],
                                    add_vec[k * 2 + 2] + min_vec[k * 2 + 2], comp);
    }
    long long get(int l, int r, int k, int L, int R) {
        if (R <= l || r <= L) {
            return inf;
        }
        if (l <= L && R <= r) {
            return add_vec[k] + min_vec[k];
        }
        auto left = this->get(l, r, k * 2 + 1, L, (L + R) / 2);
        auto right = this->get(l, r, k * 2 + 2, (L + R) / 2, R);
        return std::min(left, right, comp) + add_vec[k];
    }
public:
    starry_sky_tree(const int n, const long long def = inf,
                    const std::function<bool(long long, long long)> _comp = std::less<long long>())
            : N(n), add_vec(n << 2, 0),
              min_vec(n << 2, def), comp(_comp) {}
    void add(int l, int r, long long v) {
        this->add(l, r, v, 0, 0, N);
    }
    long long get(int l, int r) {
        return this->get(l, r, 0, 0, N);
    }
};

struct bomb {
    int h, w;
};
const int MAX = 3e5 + 10;
int H, W, M;
bomb b[MAX];
VI h[MAX], w[MAX];
starry_sky_tree t(MAX, 0, greater<>());

void solve() {
    cin >> H >> W >> M;
    REP(i, M) {
        cin >> b[i].h >> b[i].w;
        b[i].h--; b[i].w--;

        h[b[i].h].EB(i);
        w[b[i].w].EB(i);
    }

    REP(i, M) {
        t.add(b[i].w, b[i].w + 1, 1);
    }
    FORE(i, h[0]) {
        t.add(b[i].w, b[i].w + 1, -1);
    }

    int ans = 0;
    REP(i, H) {
        chmax<int>(ans, h[i].size() + t.get(0, MAX));

        FORE(j, h[i]) {
            t.add(b[j].w, b[j].w + 1, 1);
        }
        FORE(j, h[i + 1]) {
            t.add(b[j].w, b[j].w + 1, -1);
        }
    }

    cout << ans << endl;
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
