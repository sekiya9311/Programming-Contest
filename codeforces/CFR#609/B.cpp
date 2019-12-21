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

const int MAX = 2222;
int N;
LL M;
LL a[MAX], b[MAX];
map<LL, int> a_cnt, b_cnt;
VT<pair<LL, int>> a_p, b_p;

VT<pair<LL, int>> make(const map<LL, int> &mp) {
    VT<pair<LL, int>> res;
    FORE(e, mp) {
        res.EB(e.first, e.second);
    }
    return res;
}

LL check(int L, int st) {
    LL need = -1;
    REP(i, L) {
        const int idx1_1 = (st + i) % L;
        const int idx1_2 = (st + i + 1) % L;
        const int idx2_1 = i;
        const int idx2_2 = (i + 1) % L;
        if (need == -1) {
            need = (b_p[idx2_1].first - a_p[idx1_1].first + M) % M;
        }
        if (a_p[idx1_1].second != b_p[idx2_1].second) return -1;
        if (a_p[idx1_2].second != b_p[idx2_2].second) return -1;
        const auto tmp1 = (a_p[idx1_2].first - a_p[idx1_1].first + M) % M;
        const auto tmp2 = (b_p[idx2_2].first - b_p[idx2_1].first + M) % M;
        if (tmp1 != tmp2) return -1;
    }
    return need;
}

int main(void) {
    scanf("%d%lld", &N, &M);
    REP(i, N) {
        scanf("%lld", a + i);
        a_cnt[a[i]]++;
    }
    REP(i, N) {
        scanf("%lld", b + i);
        b_cnt[b[i]]++;
    }

    assert(a_cnt.size() == b_cnt.size());

    a_p = make(a_cnt);
    b_p = make(b_cnt);
    const int L = a_p.size();
    REP(i, L) {
        auto ans = check(L, i);
        if (ans != -1) {
            cout << ans << endl;
            return 0;
        }
    }
}
