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

/**
* Binary_Indexed_Tree(BIT)
* Fenwick Tree
* 1-indexed!!!
*/
template<typename T = int>
class BIT {
private:
    std::vector<T> bit;
    const int N;
public:
    BIT() : N(-1) {}
    BIT(int n) : N(n), bit(n + 1, 0) {}
    //bit[point]にnum追加
    void add(int point, T num) {
        assert(N != -1 && 0 <= point && point <= N);
        while (point <= N) {
            bit[point] += num;
            point += point & -point;
        }
    }
    //pointまでの値の和を返す
    T sum(int point) {
        assert(N != -1 && 0 <= point && point <= N);
        T res = 0;
        while (point > 0) {
            res += bit[point];
            point -= point & -point;
        }
        return res;
    }
    //left から right の区間和
    T sum(int left, int right) {
        return this->sum(right) - this->sum(left - 1);
    }
};

const int MAX = 3 * 1e5 + 10;
int N, M;
int l[MAX], r[MAX];
BIT<int> bit(MAX);
vector<int> v[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, N) {
        scanf("%d%d", l + i, r + i);
        v[r[i] - l[i] + 1].EB(i);
    }
    int worst = N;//取れる数の最低数
    FOR(d, 1, M + 1) {
        FORE(e, v[d - 1]) {
            bit.add(l[e], 1);
            bit.add(r[e] + 1, -1);
            worst--;
        }
        int ans = worst;
        for (int i = d; i <= M; i += d) {
            ans += bit.sum(i);
        }
        printf("%d\n", ans);
    }
}
