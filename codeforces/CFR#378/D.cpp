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
const int MOD = INF+7;
const LL LLINF = 1e18;
#define int LL
int n;
vector<tuple<int, int, int>> abc;
map<PII, set<PII>> mp; //二つの辺からひとつを確定(num, id)

inline PII f(const int &a, const int &b) {
    return MP(min(a, b), max(a, b));
}

signed main(void) {
    scanf("%lld", &n);
    abc.resize(n);
    PII ans = MP(-1, -1);//答えのidx
    int ansnum = 0;//答えのサイズ
    REP(i, n) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        abc[i] = make_tuple(a, b, c);
        mp[MP(min(a, b), max(a, b))].insert(MP(c, i));
        mp[MP(min(a, c), max(a, c))].insert(MP(b, i));
        mp[MP(min(b, c), max(b, c))].insert(MP(a, i));
        int buf = max(ansnum, min({a, b, c}));
        if (buf > ansnum) {
            ansnum = buf;
            ans.first = i;
        }
    }
    REP(i, n) {
        int minnum, mbuf;
        int a, b, c;
        tie(a, b, c) = abc[i];
        auto itr = mp[f(a, b)].rbegin();

        mp[f(a, b)].erase(MP(c, i));    // <- これから比較するから消してOK！
        if (mp[f(a, b)].size() == 0) goto next1;
        minnum = min(a, b);
        itr = mp[f(a, b)].rbegin();
        mbuf = min(minnum, c + (*itr).first);
        if (ansnum < mbuf) {
            ansnum = mbuf;
            ans.first = i;
            ans.second = (*itr).second;
        }
        next1:
        mp[f(b, c)].erase(MP(a, i));    // <- これから比較するから消してOK！
        if (mp[f(b, c)].size() == 0) goto next2;
        minnum = min(b, c);
        itr = mp[f(b, c)].rbegin();
        mbuf = min(minnum, a + (*itr).first);
        if (ansnum < mbuf) {
            ansnum = mbuf;
            ans.first = i;
            ans.second = (*itr).second;
        }
        next2:
        mp[f(c, a)].erase(MP(b, i));    // <- これから比較するから消してOK！
        if (mp[f(c, a)].size() == 0) continue;
        minnum = min(c, a);
        itr = mp[f(c, a)].rbegin();
        mbuf = min(minnum, b + (*itr).first);
        if (ansnum < mbuf) {
            ansnum = mbuf;
            ans.first = i;
            ans.second = (*itr).second;
        }
    }
    if (ans.second == -1) {
        cout << 1 << endl;
        cout << ans.first + 1 << endl;
    } else {
        cout << 2 << endl;
        cout << ans.first + 1 << " " << ans.second + 1 << endl;
    }
}
