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

int N, M;

LL calc_rev(LL v) {
    LL ret = 0;
    while (v) {
        ret = ret * 10 + v % 10;
        v /= 10;
    }
    return ret;
}

int ans[1111][1111];

bool check(LL x, LL y) {
    unordered_set<LL> se;
    while (se.count(min(x, y) * 1000 + max(x, y)) == 0) {
        se.emplace(min(x, y) * 1000 + max(x, y));
        if (x == 0 || y == 0) {
            FORE(e, se) ans[e / 1000][e % 1000] = 0;
            return false;
        }
        if (x < y) {
            x = calc_rev(x);
        } else {
            y = calc_rev(y);
        }
        if (x < y) {
            y -= x;
        } else {
            x -= y;
        }
    }
    FORE(e, se) ans[e / 1000][e % 1000] = 1;
    return true;
}

bool check2(int x, int y) {
    if (ans[x][y] == -2) {
        ans[x][y] = 1;
    } else if (ans[x][y] == -1) {
        if (x == 0 || y == 0) {
            ans[x][y] = 0;
        } else {
            ans[x][y] = -2;
            int nx = x, ny = y;
            if (nx < ny) {
                nx = calc_rev(nx);
            } else {
                ny = calc_rev(ny);
            }
            if (nx < ny) {
                ny -= nx;
            } else {
                nx -= ny;
            }
            ans[x][y] = check2(nx, ny);
        }
    }
    return ans[x][y];
}

int main(void) {
    cin >> N >> M;

    memset(ans, -1, sizeof(ans));
    int cnt = 0;
    for (int i = N; i > 0; i--) {
        for (int j = M; j > 0; j--) {
            if (ans[min(i, j)][max(i, j)] == -1) {
                check2(min(i, j), max(i, j));
            }
            cnt += ans[min(i, j)][max(i, j)];
        }
    }
    cout << cnt << endl;
}
