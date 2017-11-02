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

int cnt = 0;
vector<VVI> used;
int n, m;
int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};
bool inside(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}
int main(void) {
    cin >> n >> m;
    used.resize(n, VVI(m, VI(4, 0)));
    queue<pair<PII, int>> q;
    REP(i, n)REP(j, m) {
        int a; cin >> a;
        cnt += a * 4;
        if (a)REP(k, 4)q.push(MP(MP(i, j), k));
    }
    while (!q.empty()) {
        int ni, nj, muki;
        PII nij;
        tie(nij, muki) = q.front();
        tie(ni, nj) = nij;
        used[ni][nj][muki] = 1;
        q.pop();
            int ii = ni + di[muki], jj = nj + dj[muki];
            if (!inside(ii, jj)) continue;
            if (used[ii][jj][muki]) continue;
            //used[ii][jj][muki] = 1;
            //cout << ii << " " << jj << " " <<  muki << endl;
            q.push(MP(MP(ii, jj), muki));
    }
    int ans = 0;
    REP(i, n)REP(j, m) REP(k, 4) {
        ans += used[i][j][k];
        // if (used[i][j][k]) {
        //     cout << i+1 << " " << j+1 << " " << k << endl;
        // }
    }
    cout << ans - cnt << endl;
}
