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
const int MOD = INF + 7;
const LL LLINF = 1e18;

using State = pair<PII, vector<string>>;

int H, W;
vector<string> A;
bool inside(int nh, int nw) {
    return 0 <= nh && nh < H && 0 <= nw && nw < W;
}
int dh[] = {0, 1};
int dw[] = {1, 0};
bool check(vector<string> v) {
    FORE(el, v)FORE(e, el) {
        if (e == '#') return false;
    }
    return true;
}
int main(void) {
    cin >> H >> W;
    A.resize(H);
    for_each(ALL(A), [](string &e){cin >> e;});
    queue<State> q;
    A[0][0] = '.';
    q.push(MP(MP(0, 0), A));
    vector<vector<string>> goal;
    while (!q.empty()) {
        State now = q.front(); q.pop();
        if (now.first == MP(H - 1, W - 1)) {
            goal.EB(now.second);
        }
        int h = now.first.first;
        int w = now.first.second;
        auto mp = now.second;
        REP(i, 2) {
            auto cpmp = mp;
            int nh = h + dh[i], nw = w + dw[i];
            if (!inside(nh, nw)) continue;
            if (cpmp[nh][nw] != '#') continue;
            cpmp[nh][nw] = '.';
            q.push(MP(MP(nh, nw), cpmp));
        }
    }
    FORE(el, goal) {
        if (check(el)) {
            cout << "Possible" << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
}
