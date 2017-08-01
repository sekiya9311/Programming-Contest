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
    T getSum(std::pair<int, int> p1, std::pair<int, int> p2) {
        if (invalid) return 0;
        int h1, w1, h2, w2;
        tie(h1, w1) = p1; tie(h2, w2) = p2;
        return sum[h2 + 1][w2 + 1] - sum[h2 + 1][w1] - sum[h1][w2 + 1] + sum[h1][w1];
    }
    std::vector<std::vector<T>> getSumVec() {return sum;}
};

const int MAX = 1e5 + 10;
int n, q, c;
LL x[MAX], y[MAX], s[MAX];
LL t[MAX], x1[MAX], y1[MAX], x2[MAX], y2[MAX];
VT<PII> vec[11];
CumulativeSum2D<int> csum[11];

int main(void) {
    scanf("%d%d%d", &n, &q, &c);
    REP(i, n) {
        scanf("%lld%lld%lld", x + i, y + i, s + i);
        x[i]--;y[i]--;
        vec[s[i]].EB(MP(x[i], y[i]));
    }
    REP(i, 11) {
        VVI v(111, VI(111, 0));
        FORE(ee, vec[i]) {
            v[ee.first][ee.second]++;
        }
        csum[i] = CumulativeSum2D<int>(v);
        csum[i].calcSum();
    }
    REP(i, q) {
        scanf("%lld%lld%lld%lld%lld", t + i, x1 + i, y1 + i, x2 + i, y2 + i);
        x1[i]--;y1[i]--;
        x2[i]--;y2[i]--;
        LL ret = 0;
        LL numsum = 0;
        REP(j, 11) {
            LL num = csum[j].getSum(MP(x1[i], y1[i]), MP(x2[i], y2[i]));
            numsum += num;
            ret += num * ((j + t[i]) % (c + 1));
        }
        //DEBUG(numsum)
        printf("%lld\n", ret);
    }
}
