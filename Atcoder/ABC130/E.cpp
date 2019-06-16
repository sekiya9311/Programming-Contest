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

class binary_indexed_tree {
private:
    int N;
     int M;
    std::vector<vector<LL>> bit;
public:
    binary_indexed_tree() : N(-1), M(-1) {}
    binary_indexed_tree(int n, int m) : N(n), M(m), bit(n, vector<LL>(m)) {}

    void init(int n, int m) {
        N = n;
        M = m;
        bit = VVL(N + 1, VL(M + 1));
    }

    void add(int x, int y, LL num) {
        for (int i = x; i <= N; i += i & (-i)) {
            for (int j = y; j <= M; j += j & (-j)) {
                (bit[i][j] += num) %= MOD;
            }
        }
    }
    LL sum(int x, int y) {
        LL res = 0;
        for (int i = x; i > 0; i -= i & (-i)) {
            for (int j = y; j > 0; j -= j & (-j)) {
                (res += bit[i][j]) %= MOD;
            }
        }
        return res;
    }

    LL sum(int x1, int y1, int x2, int y2) {
        return (sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1) + MOD + MOD) % MOD;
    }
};

const int MAX = 2e3 + 10;
int N, M;
binary_indexed_tree bit;

int main(void) {
    cin >> N >> M;
    VI S(N);
    REP(i, N) {
        cin >> S[i];
    }
    VI T(M);
    REP(i, M) {
        cin >> T[i];
    }
    bit.init(N + 1, M + 1);

    bit.add(1, 1, 1);
    REP(i, N) {
        REP(j, M) {
            if (S[i] == T[j]) {
                bit.add(i + 2, j + 2, bit.sum(i + 1, j + 1));
            }
        }
    }

    cout << bit.sum(N + 1, M + 1) << endl;
}
