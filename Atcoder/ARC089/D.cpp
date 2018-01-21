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

template<typename T = int>
class CumulativeSum2D {
private:
    std::vector<std::vector<T>> vec;
    std::vector<std::vector<T>> sum;
    bool invalid;
    int H, W;
public:
    CumulativeSum2D() {invalid = true;}
    CumulativeSum2D(const std::vector<std::vector<T>> &v) {
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
    bool calcSum() {
        if (invalid) return false;
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
    T getSum(std::pair<int, int> p1, std::pair<int, int> p2) {
        if (invalid) return 0;
        int h1, w1, h2, w2;
        std::tie(h1, w1) = p1; std::tie(h2, w2) = p2;
        h2--; w2--;
        return sum[h2 + 1][w2 + 1] - sum[h2 + 1][w1] - sum[h1][w2 + 1] + sum[h1][w1];
    }
    T getSum(int x1, int y1, int x2, int y2) {
        return this->getSum(std::make_pair(x1, y1), std::make_pair(x2, y2));
    }
    std::vector<std::vector<T>> getSumVec() {return sum;}
};

const int MAX = 1e5 + 10;
int N, K;
LL x[MAX], y[MAX];
char str[3];
const char color[] = "BW";
char c[MAX];
VVL vec(2222,VL(2222)), vec2(2222,VL(2222));
CumulativeSum2D<LL> sum, sum2;

int main(void) {
    scanf("%d%d", &N, &K);
    REP(i, N) {
        scanf("%lld%lld%s", x + i, y + i, str);
        c[i] = str[0];
    }
    REP(i, N) {
        int xx = x[i] % (K << 1);
        int yy = y[i] % (K << 1);
        if (c[i] == 'B') vec[xx][yy]++;
        else vec2[xx][yy]++;
        //cerr << xx << " " << yy << " " << (char)c[i] << endl;
    }
    sum.init(vec);
    sum2.init(vec2);
    sum.calcSum();
    sum2.calcSum();
    LL ans = 0;
    REP(i, K) {
        REP(j, K) {
            LL get = 0;
            {
                // black
                get += sum.getSum(0, 0, i, j);
                get += sum.getSum(i, j, i + K, j + K);
                get += sum.getSum(i + K, j + K, K << 1, K << 1);
                get += sum.getSum(0, j + K, i, K << 1);
                get += sum.getSum(i + K, 0, K << 1, j);
            }
            {
                // white
                get += sum2.getSum(0, 0, K << 1, K << 1);
                get -= sum2.getSum(0, 0, i, j);
                get -= sum2.getSum(i, j, i + K, j + K);
                get -= sum2.getSum(i + K, j + K, K << 1, K << 1);
                get -= sum2.getSum(0, j + K, i, K << 1);
                get -= sum2.getSum(i + K, 0, K << 1, j);

            }
            //cerr << i << " " << j << " " << get << endl;
            chmax(ans, max(get, N - get));
        }
    }
    cout << ans << endl;
}
