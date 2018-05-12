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
class binary_indexed_tree {
private:
    std::vector<T> bit;
    const int N;
public:
    binary_indexed_tree() : N(-1) {}
    binary_indexed_tree(int n) : N(n), bit(n + 1, 0) {}
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
inline pair<char, int> get() {
    string s;
    cin >> s;
    int i;
    cin >> i;
    return MP(s[0], i);
}

const int MAX = 4444;
int N;
char c[MAX];
int a[MAX];
int black[MAX], white[MAX];
binary_indexed_tree<int> bRaq(MAX);
LL dp[2222][2222]; // dp[i][j] := 左に黒をi個，白をj個条件に沿って並ばせたときの最小コスト

int main(void) {
    cin >> N;
    REP(i, N * 2) {
        tie(c[i], a[i]) = get();
        (c[i] == 'W' ? white : black)[a[i]] = i;
    }
    REP(i, 2222) REP(j, 2222) dp[i][j] = LLINF;
    dp[0][0] = 0;
    REP(b, N + 1) {
        // reset white
        binary_indexed_tree<int> wRaq(MAX);
        REP(w, N + 1) {
            if (w == 0 && b == 0) continue;
            // min(dp[b - 1][w] + (move cost pair('B', b)), dp[b][w - 1] + (move cost pair('W', w)))
            auto &minCost = dp[b][w];
            const int targetIdx = b + w - 1;
            if (w > 0) {
                // move white (ball pair('W', w))
                const int nowIdx = white[w];
                if (b > 0) {
                    bRaq.add(black[b] + 1, 1);
                }
                chmin(minCost, dp[b][w - 1] + llabs(targetIdx - (nowIdx + bRaq.sum(nowIdx + 1, MAX) + wRaq.sum(nowIdx + 1, MAX))));
                wRaq.add(white[w] + 1, 1);
                if (b > 0) {
                    bRaq.add(black[b] + 1, -1);
                }
            }
            if (b > 0) {
                // move black (ball pair('B', b))
                const int nowIdx = black[b];
                chmin(minCost, dp[b - 1][w] + llabs(targetIdx - (nowIdx + bRaq.sum(nowIdx + 1, MAX) + wRaq.sum(nowIdx + 1, MAX))));
            }
        }
        if (b > 0) {
            bRaq.add(black[b] + 1, 1);
        }
    }
    cout << dp[N][N] << endl;
}
