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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

// xor_shift,ランダム
#include <random>
class xor_shift {
private:
    uint32_t x = 123456789;
    uint32_t y = 362436069;
    uint32_t z = 521288629;
    uint32_t w;
public:
    xor_shift(uint32_t seed = 0)
        : w(seed ? seed : 88675123) {this->random_loop();}
    void random_loop() {
        int loop_num = this->next() % 100;
        while (loop_num--) this->next();
    }
    uint32_t next(bool heavy_ok = false) {
        if (heavy_ok) this->random_loop();
        uint32_t t = this->x ^ (this->x << 11);
        this->x = this->y;
        this->y = this->z;
        this->z = this->w;
        return this->w = (this->w ^ (this->w >> 19))
                            ^ (t ^ (t >> 8));
    }
    uint64_t nextl(bool heavy_ok = false) {
        return ((((uint64_t)this->next(heavy_ok)) << 32)
                    | this->next(heavy_ok));
    }
    uint32_t operator()(bool heavy_ok = false) {
        return this->next(heavy_ok);
    }
};
std::random_device rnd;
std::mt19937 mt(rnd());
xor_shift xrnd(mt());

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

const int MAX = 1e5 + 10;
const int N = MAX;
const int T = 100;
const int L = 100;

int main(void) {
    cout << T << endl;
    for (int i = 0; i < T; i++) {
        auto primes = sieve_of_eratosthenes(MAX);
        vector<long long> p;
        for (int i = 0; i < 26; i++) {
            p.emplace_back(primes[xrnd() % primes.size()]);
        }
        sort(begin(p), end(p));
        vector<int> vals;
        long long prev = -1;
        set<int> used;
        for (int i = 0; i < 5; i++) vals.emplace_back(i % 2);
        for (int i = 5; i < L + 1; i++) {
            const int idx = xrnd() % p.size();
            vals.emplace_back(idx);
            used.emplace(idx);
        }

        while (set<int>(begin(vals), end(vals)).size() < 26) {
            DEBUG(set<int>(begin(vals), end(vals)).size())
            for (int i = 0; i < 26; i++) {
                if (used.count(i) == 0) {
                    while (true) {
                        const int idx = xrnd() % vals.size();
                        if (idx <= 5) continue;
                        vals[idx] = i;
                        break;
                    }
                }
            }
        }

        cout << 1LL * N * N << " " << L << endl;
        for (int i = 0; i < L; i++) {
            cout << p[vals[i]] * p[vals[i + 1]] << (i + 1 == L ? '\n' : ' ');
        }
    }
}
