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

const int MAX = 1e5 + 10;
int N, K;
int a[MAX];
string S[MAX];
VT<pair<int, string>> choice, notchoice;
char strbuf[MAX];
string next() {
    scanf("%s", strbuf);
    return strbuf;
}

int main(void) {
    scanf("%d%d", &N, &K);
    set<int> se;
    REP(i, K) {
        scanf("%d", a + i);
        a[i]--;
        se.insert(a[i]);
    }
    REP(i, N) {
        S[i] = next();
    }
    if (K == N) {
        cout << endl;
        return 0;
    }
    REP(i, N) {
        if (FIND(se, i)) choice.EB(MP(S[i].length(), S[i]));
        else notchoice.EB(MP(S[i].length(), S[i]));
    }
    SORT(choice);
    RSORT(notchoice);
    string ans = choice.front().second;
    int ma = 0;
    bool ng = true;
    se.clear();
    REP(i, ans.size()) {
        bool f = true;
        REP(j, notchoice.size()) {
            if (notchoice[j].first <= i) break;
            if (FIND(se, j)) continue;
            if (notchoice[j].second[i] == ans[i]) {
                f = false;
            } else {
                se.insert(j);
            }
        }
        if (f) {
            ans = ans.substr(0, i + 1);
            ng = false;
            break;
        }
    }
    if (ng) {
        cout << -1 << endl;
        return 0;
    }
    FORE(e, choice) {
        if (ans != e.second.substr(0, ans.size())) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
