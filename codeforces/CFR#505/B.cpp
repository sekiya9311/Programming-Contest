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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

bool is_prime(long long n) {
    if (n < 2) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<long long> divisor(const long long n) {
    std::vector<long long> ret;
    if (n > 1) for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
             ret.emplace_back(i);
             if (i != n / i && i != 1) {
                 ret.emplace_back(n / i);
             }
        }
    }
    return ret;
}

const int MAX = 150010;
int N;
LL A[MAX], B[MAX];

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld%lld", A + i, B + i);
    }
    set<LL> se;
    auto div = divisor(A[0]);
    FORE(e, div) if (is_prime(e)) se.emplace(e);
    div = divisor(B[0]);
    FORE(e, div) if (is_prime(e)) se.emplace(e);
    if (is_prime(A[0])) {
        se.emplace(A[0]);
    }
    if (is_prime(B[0])) {
        se.emplace(B[0]);
    }
    REP(i, N) {
        auto itr = se.begin();
        while (itr != se.end()) {
            if (A[i] % *itr != 0 && B[i] % *itr != 0) {
                itr = se.erase(itr);
            } else {
                itr++;
            }
        }
    }
    if (se.size() == 0) cout << -1 << endl;
    else cout << *se.begin() << endl;
}
