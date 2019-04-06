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

/**
* Binary_Indexed_Tree(BIT)
* Fenwick Tree
* 0-indexed!!!
* O(log N)
*/
template<typename T = int>
class binary_indexed_tree {
private:
    int N;
    std::vector<T> bit;
public:
    binary_indexed_tree() : N(-1) {}
    binary_indexed_tree(int n) : N(n), bit(n, 0) {}
    // bit[point]にnum追加
    void add(int point, T num) {
        point++;
        while (point - 1 < N) {
            bit[point - 1] += num;
            point += point & -point;
        }
    }
    // [0, point)
    T sum(int point) {
        T res = 0;
        while (point > 0) {
            res += bit[point - 1];
            point -= point & -point;
        }
        return res;
    }
    // [left, right)
    T sum(int left, int right) {
        return this->sum(right) - this->sum(left);
    }
};


const int MAX = 1e5 + 10;
int N;
LL S[MAX];
int q;
LL l[MAX], r[MAX];
LL ans[MAX];

int main(void) {
    scanf("%d", &N);
    REP(i, N) scanf("%lld", S + i);
    scanf("%d", &q);
    REP(i, q) scanf("%lld%lld", l + i, r + i);

    VT<LL> s_dist;
    binary_indexed_tree<LL> bit;
    LL mi = LLINF, ma = -LLINF;
    {
        set<LL> se;
        REP(i, N) {
            se.emplace(S[i]);
        }
        memset(S, 0, sizeof(S));
        N = 0;
        FORE(e, se) {
            S[N++] = e;
            chmin(mi, e);
            chmax(ma, e);
        }
        s_dist.resize(N - 1);
        REP(i, N - 1) {
            s_dist[i] = S[i + 1] - S[i];
        }
        SORT(s_dist);
        bit = binary_indexed_tree<LL>(N - 1);
        REP(i, N - 1) {
            bit.add(i, s_dist[i]);
        }
    }
    VT<pair<LL, int>> vec(q);
    REP(i, q) {
        vec[i] = {r[i] - l[i] + 1, i};
    }
    SORT(vec);
    REP(i, q) {
        const auto dist = vec[i].first;
        const int idx = vec[i].second;

        const auto d = distance(begin(s_dist), upper_bound(ALL(s_dist), dist));

        if (d < N - 1) {
            ans[idx] = bit.sum(d) + (N - d) * dist;
        } else {
            ans[idx] = (ma - mi + 1) + dist - 1;
        }
    }

    REP(i, q) {
        printf("%lld%c", ans[i], (i + 1 == N ? '\n' : ' '));
    }
}
