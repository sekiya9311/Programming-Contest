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

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N;
VI crash;

VVI nxt;
VI cnt;
void dfs(int start, int idx, int cntnum) {
    //cout << start << " " << idx << endl;
    if (cntnum > N + 1) return;
    nxt[start][cntnum] = idx;
    dfs(start, crash[idx], cntnum + 1);
}

long long gcd(long long a, long long b) {
    if(a < b) swap(a, b);
    long long ret = 1;
    while(b) {ret = b; b = a % b; a = ret;}
    return ret;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}


int main(void) {
    scanf("%d", &N);
    crash.resize(N);
    for_each(ALL(crash), [](int &e){scanf("%d", &e);});
    nxt.resize(N + 10, VI(N + 10));
    VT<bool> ok(N + 10, false);
    REP(i, N) {
        crash[i]--;
        ok[crash[i]] = true;
    }
    REP(i, N) {
        if (!ok[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    REP(i, N) {
        dfs(i, i, 0);
    }
    cnt.resize(N + 10);
    REP(i, N) REP(j, N) {
        //cout << nxt[i][j + 1] <<" "<< nxt[nxt[i][j + 1]][j + 1] << endl;
        if (i == nxt[nxt[i][j + 1]][j + 1]) {
            cnt[i] = j + 1; break;
        }
    }
    LL ans = cnt[0];
    FOR(i, 1, N) {
        ans = lcm(ans, cnt[i]);
    }
    cout << ans << endl;
}
