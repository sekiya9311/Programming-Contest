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

int main(void) {
    int T;
    scanf("%d", &T);
    REP(i, T) {
        LL A, B, N, M;
        scanf("%lld%lld%lld%lld", &A, &B, &N, &M);

        // A: バニラ
        // B: チョコ
        // N: A > B のとき、A--。A <= B のとき、B--。
        // M: A > B のとき、B--。A <= B のとき、A--。
        if (A + B < N + M) {
            puts("NO");
            continue;
        }

        if (abs(A - B) > N) {
            if (min(A, B) < M) {
                puts("NO");
                continue;
            }
        } else {
            if (A > B) swap(A, B);
            // A <= B
            const auto ab = abs(A - B);
            B -= ab;
            N -= ab;

            const auto mi = min(N, M);
            A -= mi;
            B -= mi;
            N -= mi;
            M -= mi;

            if (A < 0 || B < 0) {
                puts("NO");
                continue;
            }
            if (min(A, B) < M) {
                puts("NO");
                continue;;
            }
        }

        puts("YES");
    }
}
