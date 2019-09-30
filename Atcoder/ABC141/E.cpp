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

const int ord[] = {114514, 11970311};

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

const int MAX = 5 * 1e3 + 10;
int N;
string S;
rolling_hash rh;

bool calc(int len) {
    map<PLL, VPII> cnt;
    REP(i, N) {
        if (i + len > N) break;
        cnt[rh.get_hash(i, i + len)].EB(i, i + len);
    }
    FORE(e, cnt) if (e.second.size() > 1) {
        const auto l = e.second.front();
        const auto r = e.second.back();
        if (l.second <= r.first) return true;
    }
    return false;
}

int main(void) {
    cin >> N;
    cin >> S;

    rh = rolling_hash(S, ord[0], ord[1]);
    
    int ok = 0, ng = N;
    while (ng - ok > 1) {
        const int mid = (ng + ok) / 2;
        if (calc(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
