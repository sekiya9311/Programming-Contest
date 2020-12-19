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
#define GREATER(T) T, VT<T>, greater<T>
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
    binary_indexed_tree() {}
    binary_indexed_tree(int n) : N(n), bit(n, 0) {}
    // bit[point]にnum追加
    void add(int point, T val) {
        point++;

        for (int i = point; i - 1 < N; i += i & (-i)) {
            bit[i - 1] += val;
        }
    }
    // [0, point)
    T sum(int point) {
        T res = 0;
        for (int i = point; i > 0; i -= i & (-i)) {
            res += bit[i - 1];
        }

        return res;
    }
    // [left, right)
    T sum(int left, int right) {
        return this->sum(right) - this->sum(left);
    }
};

void solve() {
    int N;
    cin >> N;
    VT<pair<LL, int>> A(N);
    REP(i, N) {
        cin >> A[i].first;
        A[i].second = i;
    }
    SORT(A);

    binary_indexed_tree<LL> pos(N), neg(N), cnt_pos(N), cnt_neg(N);
    REP(i, N) {
        pos.add(A[i].second, A[i].first);
        cnt_pos.add(A[i].second, 1);
    }

    LL ans = 0;
    REP(i, N) {
        pos.add(A[i].second, -A[i].first);
        cnt_pos.add(A[i].second, -1);

        const auto pos_cnt = cnt_pos.sum(A[i].second + 1, N);
        const auto neg_cnt = cnt_neg.sum(A[i].second + 1, N);
        const auto pos_tmp = pos.sum(A[i].second + 1, N);
        const auto neg_tmp = neg.sum(A[i].second + 1, N);

        ans += pos_tmp - A[i].first * pos_cnt;
        ans += A[i].first * neg_cnt - neg_tmp;

        neg.add(A[i].second, A[i].first);
        cnt_neg.add(A[i].second, 1);
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
