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


int main(void) {
    int N; cin >> N;
    auto primes = sieve_of_eratosthenes(N + 1);
    VI ans;
    REP(i, primes.size()) {
        while (N - primes[i] >= 0) {
            N -= primes[i];
            ans.EB(primes[i]);
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << (i ? " " : "") << ans[i] + (i + 1 == ans.size() ? N : 0);
    }
    cout << endl;
}
