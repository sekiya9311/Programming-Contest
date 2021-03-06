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

set<int> se;
string S;
int cnt = 0;

void dfs(int l, int r) {
    if (S[l] != S[r]) return;
    cnt++;
    se.erase(l);
    se.erase(r);
    auto l_it = se.lower_bound(l);
    auto r_it = se.upper_bound(r);
    if (r_it != end(se) && l_it != r_it && S[*l_it] == S[*r_it]) {
        dfs(*l_it, *r_it);
    }
}

int main(void) {
    cin >> S;
    const int L = S.length();
    REP(i, L) se.emplace(i);
    while (true) {
        int pre = cnt;
        auto it = begin(se);
        while (it != end(se)) {
            bool foo = false;
            if (it != begin(se)) {
                auto it2 = prev(it);
                if (it2 != end(se) && *it != *it2 && S[*it] == S[*it2]) {
                    auto tmp = *it;
                    dfs(*it2, *it);
                    it = se.lower_bound(tmp);
                    foo = true;
                }
            }
            if (it != end(se)) {
                auto it2 = next(it);
                if (it2 != end(se) && *it != *it2 && S[*it] == S[*it2]) {
                    auto tmp = *it;
                    dfs(*it, *it2);
                    it = se.lower_bound(tmp);
                    foo = true;
                }
            }
            if (!foo) {
                it++;
            }
        }
        if (pre == cnt) break;
    }
    DEBUG(cnt)
    cout << (cnt % 2 ? "Yes" : "No")  << endl;
}
