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

int calc2(int v) {
    while (v >= 10) v /= 10;
    return v;
}

int get(char high, int mid, char low, int zero_cnt) {
    return stoi(high + string(zero_cnt, '0') + to_string(mid) + low);
}

int N;
LL memo[10][10];

int main(void) {
    cin >> N;

    FOR(i, 1, 10) {
        FOR(j, 1, 10) {
            if (i == j && i > N) {
                continue;
            }
            if (i * 10 + j > N) {
                memo[i][j] = i == j;
                continue;
            }
            memo[i][j] = 1 + (i == j);
            for (int k = 0; ; k++) {
                int z = 0;
                for (; ; z++) {
                    const int v = get('0' + i, k, '0' + j, z);
                    if (v <= N) {
                        memo[i][j]++;
                    } else {
                        break;
                    }
                }
                if (z == 0) break;
            }
        }
    }

    LL cnt = 0;
    FOR(i, 1, N + 1) {
        if (i % 10 == 0) continue;
        //const auto cur = memo[calc2(i)][i % 10];
        const auto cur = memo[i % 10][calc2(i)];
        //cerr << i << " " << cur << endl;
        cnt += cur;
    }

    cout << cnt << endl;
}
