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

const int MAX = 1e5 + 10;
int N;
int s[MAX];
int Q;
int l[MAX], r[MAX];
unordered_map<LL, int> pow_two;

LL memo_c[MAX][60]; // [ left ][ pow of 2 ]
int memo_val[MAX][60];

LL calc(int left_idx, int pow_of_two) {
    if (memo_c[left_idx][pow_of_two] != -1) {
        return memo_c[left_idx][pow_of_two];
    }

    if (pow_of_two == 0) {
        return memo_c[left_idx][pow_of_two] = 0;
    }

    if (pow_of_two == 1) {
        memo_c[left_idx][pow_of_two] = 0;

        int sum = s[left_idx] + s[left_idx + 1];
        if (sum >= 10) memo_c[left_idx][pow_of_two]++;

        sum %= 10;
        memo_val[left_idx][pow_of_two] = sum;

        return memo_c[left_idx][pow_of_two];
    }

    const LL left_sum = calc(left_idx, pow_of_two - 1);
    const LL right_sum = calc(left_idx + (1 << (pow_of_two - 1)), pow_of_two - 1);
    memo_c[left_idx][pow_of_two] = left_sum + right_sum;

    const int l_val = memo_val[left_idx][pow_of_two - 1];
    const int r_val = memo_val[left_idx + (1 << (pow_of_two - 1))][pow_of_two - 1];
    int sum = l_val + r_val;
    if (sum >= 10) memo_c[left_idx][pow_of_two]++;

    sum %= 10;
    memo_val[left_idx][pow_of_two] = sum;

    return memo_c[left_idx][pow_of_two];
}

int main(void) {

    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", s + i);
    }
    scanf("%d", &Q);
    REP(i, Q) {
        scanf("%d%d", l + i, r + i);
    }

    memset(memo_c, -1, sizeof(memo_c));
    REP(i, 60) {
        pow_two[1LL << i] = i;
    }

    REP(i, Q) {
        printf("%lld\n", calc(l[i] - 1, pow_two[r[i] - l[i] + 1]));
    }
}
