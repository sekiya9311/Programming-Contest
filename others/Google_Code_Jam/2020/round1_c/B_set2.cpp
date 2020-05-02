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


// xor_shift,ランダム
#include <random>
class xor_shift {
public:
    using result_type = uint32_t;

    static result_type min() {
        return std::numeric_limits<result_type>::min();
    }

    static result_type max() {
        return std::numeric_limits<result_type>::max();
    }

private:
    result_type x = 123456789;
    result_type y = 362436069;
    result_type z = 521288629;
    result_type w;
public:
    xor_shift(result_type seed = 0)
        : w(seed ? seed : 88675123) {this->random_loop();}
    void random_loop() {
        int loop_num = this->next() % 100;
        while (loop_num--) this->next();
    }
    result_type next(bool heavy_ok = false) {
        if (heavy_ok) this->random_loop();
        const auto t = this->x ^ (this->x << 11);
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
    result_type operator()(bool heavy_ok = false) {
        return this->next(heavy_ok);
    }
};
std::random_device rnd;
std::mt19937 mt(rnd());
xor_shift xrnd(mt());

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

char strbuf[111];
string get_str() {
    scanf("%s", strbuf);
    return strbuf;
}

int diff(const PII &p) {
    return p.second - p.first;
}

const int MAX = 1e4;
int U;
pair<LL, string> in[MAX];

bool check2(const string &ans) {
    unordered_map<char, int> mp;
    REP(i, ans.size()) {
        mp[ans[i]] = i;
    }

    REP(i, MAX) {
        const auto str = in[i].second;
        LL val = 0;
        FORE(c, str) val = val * 10 + mp[c];
        if (val == 0 || (in[i].first != -1 && in[i].first < val)) return false;
    }
    return true;
}

bool check(const string &ans, bool is_left) {
    unordered_map<char, int> mp;

    REP(i, ans.size()) {
        mp[ans[i]] = i + (is_left ? 0 : 5);
    }

    REP(i, MAX) {
        const auto str = in[i].second;
        LL val = 0;
        REP(j, str.length()) {
            const auto c = str[j];
            if (mp.count(c)) {
                val = val * 10 + mp[c];
            } else {
                if (is_left) {
                    val = val * 10 + 5;
                } else {
                    val = val * 10 + (j == 0);
                }
            }
        }
        if (val == 0 || (in[i].first != -1 && in[i].first < val)) return false;
    }
    return true;
}

VT<string> calc(string ans, bool is_left) {
    VT<string> res;
    SORT(ans);
    do {

        if (check(ans, is_left)) {
            res.EB(ans);
        }

    } while (next_permutation(ALL(ans)));
    return res;
}

void solve(stringstream &out) {
    unordered_set<char> candset;
    VT<char> ans(10, -1);
    scanf("%d", &U);
    REP(i, MAX) {
        scanf("%lld", &in[i].first);

        in[i].second = get_str();
        FORE(c, in[i].second) {
            candset.emplace(c);
        }
    }
    string cands = "";
    FORE(e, candset) {
        cands += e;
    }

    REP(i, (1 << 10)) {
        if (__builtin_popcount(i) != 5) {
            continue;
        }

        string left, right;
        REP(j, 10) {
            if ((i & (1 << j))) {
                left += cands[j];
            } else {
                right += cands[j];
            }
        }

        const auto res_l = calc(left, true);
        const auto res_r = calc(right, false);
        FORE(l, res_l) FORE(r, res_r) {
            string ans;
            FORE(c, l) ans += c;
            FORE(c, r) ans += c;

            if (check2(ans)) {
                out << ans << endl;
                return;
            }
        }
    }
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }

    int problem_count;
    scanf("%d", &problem_count);
    //string s;getline(cin, s);
    for (int test_no = 1; test_no <= problem_count; test_no++) {
        stringstream out;
        solve(out);
        printf("Case #%d: %s", test_no, out.str().c_str());
        // cerr << "Case #" << test_no << ": solved" << endl;
    }
}
