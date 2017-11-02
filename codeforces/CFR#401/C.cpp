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
int N, M;
VVI a;
int K;
pair<int, int> lr[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    a.resize(N, VI(M));
    REP(i, N) REP(j, M) {
        scanf("%d", &a[i][j]);
    }
    if (N >= 100) {
        VVI sum(N + 5, VI(M + 5, 1));
        REP(j, M) {
            //sum[0][j] = 0;
            REP(i, N - 1) {
                if (a[i + 1][j] >= a[i][j]) {
                    sum[i + 1][j] += sum[i][j];
                }
            }
        }
        scanf("%d", &K);
        REP(i, K) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;r--;
            bool f = false;
            REP(j, M) {
                if (sum[r][j] - sum[l][j] >= r - l) {
                    puts("Yes");
                    f = true;
                    break;
                }
            }
            if (!f) puts("No");
        }
    } else {
        set<pair<int, int>> ok;
        VT<VT<bool>> mas(N, VT<bool>(N, false));
        REP(i, N) mas[i][i] = true;
        REP(j, M) {
            REP(i, N) {
                FOR(k, i + 1, N) {
                    if (a[k - 1][j] <= a[k][j]) {
                        mas[i][k] = true;
                    } else {
                        break;
                    }
                }
            }
        }
        scanf("%d", &K);
        //FORE(e, ok) cout<<e.first<<" "<<e.second<<endl;
        REP(i, K) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;r--;
            puts(mas[l][r] ? "Yes" : "No");
        }
    }
}
