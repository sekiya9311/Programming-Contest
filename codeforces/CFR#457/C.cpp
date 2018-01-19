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

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> is(n + 1, true);
    vector<int> res;
    is[0] = false;
    is[1] = false;
    for (int i = 2; i <= n; i++) if (is[i]) {
        res.emplace_back(i);
        for (int j = i * 2; j <= n; j += i) {
            is[j] = false;
        }
    }
    return res;
}

const int MAX = 1e5 + 10;
int N, M;
int a[MAX], b[MAX];
LL c[MAX];
int ptr = 0;
LL MST;
set<int> primes;

int main(void) {
    {
        auto v = sieve_of_eratosthenes(MAX);
        primes = set<int>(ALL(v));
    }
    cin >> N >> M;
    {
        // make 1 to n route
        auto itr = primes.lower_bound(N);
        if (*itr < N - 1) {
            itr++;
        }
        const int one_to_n_cost = *itr;
        const int a_cost = one_to_n_cost / (N - 1);
        const int amari = one_to_n_cost % (N - 1);
        MST = one_to_n_cost;
        REP(i, N - 1) {
            a[ptr] = i;
            b[ptr] = i + 1;
            c[ptr] = a_cost + (i < amari);
            ptr++;
        }
    }
    {
        int na = 0, nb = 2;
        for (; ptr < M; ptr++) {
            a[ptr] = na;
            b[ptr] = nb;
            c[ptr] = INF - 1;
            nb++;
            if (nb == N) {
                na++;
                nb = na + 2;
            }
        }
    }
    printf("%lld %lld\n", MST, MST);
    REP(i, M) {
        printf("%d %d %lld\n", a[i] + 1, b[i] + 1, c[i]);
    }
}
