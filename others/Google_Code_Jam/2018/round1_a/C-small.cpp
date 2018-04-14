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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

// 方針からして何もかもダメ

int N, P;
int W[111], H[111];
void solve(int testNum) {
    scanf("%d%d", &N, &P);
    double ans = 0;
    REP(i, N) {
        scanf("%d%d", W + i, H + i);
        ans += (W[i] + H[i]) << 1;
    }
    VT<pair<double, double>> vec(N);
    REP(i, N) {
        VD v{2. * W[i], 2. * H[i], 2 * sqrt(W[i] * W[i] + H[i] * H[i])};
        vec[i] = MP(*min_element(ALL(v)), *max_element(ALL(v)));
    }
    SORT(vec);
    double need = P - ans;
    int cut = N;
    REP(i, N) {
        if (vec[i].first <= need) {
            need -= vec[i].first;
            ans += vec[i].first;
        } else {
            cut = i;
            break;
        }
    }
    REP(i, cut) {
        if (vec[i].second - vec[i].first <= need) {
            need -= vec[i].second - vec[i].first;
            ans += vec[i].second - vec[i].first;
        } else {
            need = 0;
            ans = P;
            break;
        }
    }

    cout << "Case #" << testNum << ": " << ans << endl;
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }
    cout << fixed << setprecision(10);
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
