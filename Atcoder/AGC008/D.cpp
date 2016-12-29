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
 
int N, NN;
VI a;
VI ans;
VPII vp;
VI nokori;
 
int main(void) {
    scanf("%d", &N);
    NN = N * N;
    a.resize(N);
    ans.resize(NN, 0);
    for_each(ALL(a), [](int &e){scanf("%d", &e);});
    vp.resize(N);
    nokori.resize(N);
    fill(ALL(nokori), N);
    REP(i, N) vp[i] = MP(a[i] - 1, i);
    RSORT(vp);
    int nowfreeid = N - 1, nowid = N - 1;
    bool free = false;
    REP(i, NN) {
        if (vp[nowid].first == i) {
            if (nokori[vp[nowid].second] == N - (vp[nowid].second)) {
                ans[i] = vp[nowid].second;
                nokori[vp[nowid].second]--;
                nowid--;
            } else {
                //FORE(e, ans) cout << e+1 << " ";cout<<endl;
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (free) {
                while (nokori[vp[nowfreeid].second] == 0) {
                    nowfreeid--;
                }
                if (nowfreeid <= nowid) {
                    cout << "No" << endl;
                    return 0;
                }
                ans[i] = vp[nowfreeid].second;
                nokori[vp[nowfreeid].second]--;
            } else {
                while (nowfreeid >= 0 && nokori[vp[nowfreeid].second] <= N - (vp[nowfreeid].second)) {
                    nowfreeid--;
                }
                if (nowfreeid == -1) {
                    free = true;
                    nowfreeid = N - 1;
                    i--;
                    continue;
                } else {
                    ans[i] = vp[nowfreeid].second;
                    nokori[vp[nowfreeid].second]--;
                }
            }
        }
    }
    printf("Yes\n");
    REP(i, NN) printf("%d%c", ans[i] + 1, (i + 1 == NN ? '\n' : ' '));
}
