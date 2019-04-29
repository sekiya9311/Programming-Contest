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

// エラトステネスの篩,素数列挙
// O(N log log N)
std::vector<int> sieve_of_eratosthenes(const int n) {
    std::vector<bool> is(n + 1, true);
    std::vector<int> res;
    is[0] = false;
    is[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is[i]) {
            res.emplace_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is[j] = false;
            }
        }
    }
    return res;
}

const int MAX = 2e5 + 10;
int N;
int a_cnt[3];
VI primes;
int ans[MAX];

int main(void) {
    primes = sieve_of_eratosthenes(MAX * 2);
    scanf("%d", &N);
    REP(i, N) {
        int a;
        scanf("%d", &a);
        a_cnt[a]++;
    }

    int ptr = 0;
    int pre_p = 0;
    const int L = primes.size();
    REP(i, L) {
        const auto cur_p = primes[i];
        int diff = cur_p - pre_p;

        while (diff > 0 && ptr < N) {
            if (diff >= 2 && a_cnt[2]) {
                ans[ptr++] = 2;
                a_cnt[2]--;
                diff -= 2;
            } else if (a_cnt[1]) {
                ans[ptr++] = 1;
                a_cnt[1]--;
                diff--;
            } else if (diff < 2 && a_cnt[2]) {
                ans[ptr++] = 2;
                a_cnt[2]--;
                diff -= 2;
                break;
            } else {
                break;
            }
        }

        pre_p = cur_p - diff;
    }

    REP(i, N) printf("%d%c", ans[i], (i + 1 == N ? '\n' : ' '));
}
