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

// ローリングハッシュ,文字列比較
// これはクソ実装

class rolling_hash {
private:
    long long mods[2] = {(long long)(1e9 + 7), (long long)(1e9 + 9)};
    std::vector<long long> hs[2], pm[2];
    std::vector<long long> x; //基数
    int len;
    std::string S;
public:

    rolling_hash() {}

    //文字列, 基数1, 基数2
    // 基数はランダムで指定する(hack怖い)
    rolling_hash(const std::string& str, long long num1, long long num2) {
        x.resize(2);
        x[0] = num1; x[1] = num2;
        S = str;
        len = str.length();
        for (int i = 0; i < 2; i++) {
            pm[i].resize(1000000);
            pm[i][0] = 1;
            for (int j = 0; j < (int)pm[i].size(); j++) {
                pm[i][j + 1] = (pm[i][j] * x[i]) % mods[i];
            }
        }
        init(S);
    }
    void init(const std::string& str) {
        len = str.length();
        for (int i = 0; i < 2; i++) {
            hs[i].resize(len + 5);
            hs[i][0] = 0;
            for (int j  = 0; j < len; j++) {
                hs[i][j + 1] = ((hs[i][j] * x[i]) + str[j]) % mods[i];
            }
        }
    }
    //strのハッシュ値生成
    std::pair<long long, long long> make_hash(const std::string& str) {
        long long res[2];
        const int slen = str.length();
        for (int i = 0; i < 2; i++) {
            res[i] = 0;
            for (int j = 0; j < slen; j++) {
                res[i] = ((res[i] * x[i]) + str[j]) % mods[i];
            }
        }
        return std::make_pair(res[0], res[1]);
    }
    //S[l..r)のハッシュ値返す
    std::pair<long long, long long> get_hash(int l, int r) {
        r--;
        if (l > r) {
            throw std::invalid_argument("");
        }
        long long res[2];
        while ((int) pm[0].size() < r + 5) {
            for (int i = 0; i < 2; i++) {
                pm[i].emplace_back((pm[i].back() * x[i]) % mods[i]);
            }
        }
        for (int i = 0; i < 2; i++) {
            res[i] = (hs[i][r + 1] - (hs[i][l] * pm[i][r - l + 1] % mods[i]) + mods[i]) % mods[i];
        }
        return std::make_pair(res[0], res[1]);
    }
    //Sのハッシュ配列返す
    std::vector<std::vector<long long>> get_hash_array() {
        return std::vector<std::vector<long long>>{hs[0], hs[1]};
    }
    std::vector<long long> get_mod() {
        return std::vector<long long>{mods[0], mods[1]};
    }
    std::vector<long long> get_base_num() {
        return x;
    }
};

// UnionFind,素集合データ構造,DisjointSet

template<typename weight_type = int>
class union_find {
    static_assert(
        std::is_arithmetic<weight_type>::value,
        "Invalid weight type");
private:
    std::vector<int> uni;
    std::vector<int> edge_count_;
    std::vector<weight_type> weights;
    int size_;
    const void check(const int n) const {
        if (this->group_size() < 0) {
            assert(false);
        }
        if (!(0 <= n && n < this->all_size())) {
            assert(false);
        }
    }
public:
    union_find() : uni(0), edge_count_(0), weights(0), size_(-1) {}
    union_find(const int n)
        : uni(n, -1), edge_count_(n), weights(n), size_(n) {
        this->check(n - 1);
    }
    union_find(const std::vector<weight_type> &_weights)
        : uni(_weights.size(), -1), edge_count_(_weights.size()),
        weights(_weights), size_(_weights.size()) {
        this->check((int)_weights.size() - 1);
    }
    bool same(const int a, const int b) {
        this->check(a);
        this->check(b);
        return this->find(a) == this->find(b);
    }
    int find(const int a) {
        this->check(a);
        return this->uni[a] < 0 ?
                a :
            this->uni[a] = this->find(this->uni[a]);
    }
    bool unite(int a, int b) {
        a = this->find(a);
        b = this->find(b);
        this->edge_count_[a]++;
        if (a == b) {
            return false;
        }
        this->size_--;
        if (this->uni[a] > this->uni[b]) {
            std::swap(a, b);
        }
        this->uni[a] += this->uni[b];
        this->weights[a] += this->weights[b];
        this->edge_count_[a] += this->edge_count_[b];
        this->uni[b] = a;
        return true;
    }
    const int group_size() const {
        return this->size_;
    }
    const int all_size() const {
        return this->uni.size();
    }
    const int size(const int a) {
        this->check(a);
        return -this->uni[this->find(a)];
    }
    const int edge_count(const int a) {
        this->check(a);
        return this->edge_count_[this->find(a)];
    }
    const weight_type weight(const int a) {
        this->check(a);
        return this->weights[this->find(a)];
    }
};

const int rad[] = { 114514, 173205 };
string S, T;
int s_len, t_len;
rolling_hash s_h, t_h;

int ret_nxt_idx(int t_begin_idx) {
    int cur_s_idx = 0;
    int cur_t_idx = t_begin_idx;
    while (cur_s_idx < s_len) {
        const int left_over_t = t_len - cur_t_idx;

        const int need_s_len = s_len - cur_s_idx;
        if (need_s_len <= left_over_t) {
            const auto s_hash = s_h.get_hash(cur_s_idx, s_len);
            const auto t_hash = t_h.get_hash(cur_t_idx, cur_t_idx + need_s_len);

            if (s_hash != t_hash) {
                return -1;
            }

            cur_s_idx = s_len;
            (cur_t_idx += need_s_len) %= t_len;

        } else {

            // need_s_len > left_over_t
            const auto s_hash = s_h.get_hash(cur_s_idx, cur_s_idx + left_over_t);
            const auto t_hash = t_h.get_hash(cur_t_idx, t_len);

            if (s_hash != t_hash) {
                return -1;
            }
            cur_s_idx += left_over_t;
            cur_t_idx = 0;
        }
    }
    return cur_t_idx % t_len;
}

int main(void) {
    cin >> S >> T;
    swap(S, T);
    s_len = S.length();
    t_len = T.length();
    s_h = rolling_hash(S, rad[0], rad[1]);
    t_h = rolling_hash(T, rad[0], rad[1]);

    union_find<> t_uf(t_len);
    REP(i, t_len) {
        const int nxt = ret_nxt_idx(i);
        if (nxt < 0) continue;
        //DEBUG(nxt)
        if (!t_uf.unite(i, nxt)) {
            //cerr << i << " " << nxt + 1 << endl;
            cout << -1 << endl;
            return 0;
        }
    }

    int ans = 0;
    REP(i, t_len) {
        if (t_uf.find(i) == i) {
            chmax(ans, t_uf.size(i) - 1);
        }
    }
    cout << ans << endl;
}
