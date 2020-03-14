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

void check(const string &a, const string &b, bool same[MAX]) {
    REP(i, a.size()) {
        bool ok = true;
        REP(j, b.size()) {
            if (i + j >= a.size()) break;
            if (a[i + j] != b[j] && a[i + j] != '?' && b[j] != '?') {
                ok = false;
                break;
            }
        }
        same[i] = ok;
    }
}

bool same_ab[MAX], same_bc[MAX], same_ac[MAX];
int solve(const string &a, const string &b, const string &c) {
    memset(same_ab, true, sizeof(same_ab));
    memset(same_bc, true, sizeof(same_bc));
    memset(same_ac, true, sizeof(same_ac));

    check(a, b, same_ab);
    check(b, c, same_bc);
    check(a, c, same_ac);

    int ans = INF;
    REP(ab, MAX) {
        REP(bc, MAX) {
            const int ac = ab + bc;
            if (same_ab[ab] && same_bc[bc] && (ac >= MAX || same_ac[ac])) {
                const int cur = max({
                    (int)a.size(),
                    ab + (int)b.size(),
                    ab + bc + (int)c.size()
                });
                chmin(ans, cur);
            }
        }
    }

    return ans;
}

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;
    string s[] = {a, b, c};

    int ans = INF;
    VI v(3);
    iota(ALL(v), 0);
    do {
        chmin(ans, solve(s[v[0]], s[v[1]], s[v[2]]));
    } while (next_permutation(ALL(v)));

    cout << ans << endl;
}
