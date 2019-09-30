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

// この実装はメモリが死ぬぅ

template<typename T = int>
class cumulative_sum_2d {
private:
    std::vector<std::vector<T>> vec;
    std::vector<std::vector<T>> sum;
    bool invalid;
    int H, W;
public:
    cumulative_sum_2d() {invalid = true;}
    cumulative_sum_2d(const std::vector<std::vector<T>> &v) {
        init(v);
    }
    void init() {
        vec.clear();
        sum.clear();
        H = W = -1;
        invalid = true;
    }
    void init(const std::vector<std::vector<T>> &v) {
        init();
        invalid = false;
        H = v.size();
        W = v.front().size();
        std::copy(v.begin(), v.end(), std::back_inserter(vec));
        sum.resize(H + 1, std::vector<T>(W + 1, 0));
    }
    bool calc_sum() {
        if (invalid) {
            return false;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                sum[i + 1][j + 1] = vec[i][j];
            }
        }
        for (int i = 0; i < H + 1; i++) {
            for (int j = 0; j < W; j++) {
                sum[i][j + 1] += sum[i][j];
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W + 1; j++) {
                sum[i + 1][j] += sum[i][j];
            }
        }
        return true;
    }
    // [p1, p2)
    T get_sum(std::pair<int, int> p1, std::pair<int, int> p2) {
        if (invalid) return 0;
        int h1, w1, h2, w2;
        std::tie(h1, w1) = p1; std::tie(h2, w2) = p2;
        h2--; w2--;
        return sum[h2 + 1][w2 + 1] - sum[h2 + 1][w1] - sum[h1][w2 + 1] + sum[h1][w1];
    }
    T get_sum(int x1, int y1, int x2, int y2) {
        return this->get_sum(std::make_pair(x1, y1), std::make_pair(x2, y2));
    }
    std::vector<std::vector<T>> get_sum_vec() {return sum;}
};

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MARGIN = 3010;
const int MAX = 300010;
int N;
int X[MAX], Y[MAX], D[MAX];

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d%d%d", X + i, Y + i, D + i);
    }

    VVI vec(MARGIN * 2, VI(MARGIN * 2));
    REP(i, N) {
        vec[X[i] - Y[i] + MARGIN][X[i] + Y[i]] = 1;
    }
    cumulative_sum_2d<int> cum(vec);
    cum.calc_sum();

    REP(i, N) {
        const auto x = X[i] - Y[i] + MARGIN;
        const auto y = X[i] + Y[i];
        const auto ans = cum.get_sum(
            max(x - D[i], 0),
            max(y - D[i], 0),
            min(x + D[i] + 1, MARGIN * 2 - 1),
            min(y + D[i] + 1, MARGIN * 2 - 1));

        printf("%d\n", ans);
    }
}
