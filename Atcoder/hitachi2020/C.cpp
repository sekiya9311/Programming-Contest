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

const int MAX = 2e5 + 10;
int N;
VI G[MAX];
int ans[MAX];

int match[MAX];
void dfs_match(int cur, int par) {
    match[cur] = par == -1 ? 0 : (match[par] ^ 1);
    FORE(e, G[cur]) if (e != par) {
        dfs_match(e, cur);
    }
}

int main(void) {
    cin >> N;
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].EB(b);
        G[b].EB(a);
    }

    dfs_match(0, -1);

    int cnt[2] = {};
    REP(i, N) {
        cnt[match[i]]++;
    }

    int cand[3] = {3, 1, 2};
    if (cnt[0] > N / 3 && cnt[1] > N / 3) {
        REP(i, N) {
            int idx = match[i] ? 1 : 2;
            if (cand[idx] > N) {
                idx = 0;
            }
            ans[i] = cand[idx];
            cand[idx] += 3;
        }
    } else if (cnt[0] <= N / 3) {
        REP(i, N) if (!match[i]) {
            ans[i] = cand[0];
            cand[0] += 3;
        }
        REP(i, N) if (match[i]) {
            int idx;
            REP(j, 3) if (cand[j] <= N) {
                idx = j;
                break;
            }
            ans[i] = cand[idx];
            cand[idx] += 3;
        }
    } else {
        REP(i, N) if (match[i]) {
            ans[i] = cand[0];
            cand[0] += 3;
        }
        REP(i, N) if (!match[i]) {
            int idx;
            REP(j, 3) if (cand[j] <= N) {
                idx = j;
                break;
            }
            ans[i] = cand[idx];
            cand[idx] += 3;
        }
    }

    REP(i, N) {
        printf("%d%c", ans[i], (i + 1 == N ? '\n' : ' '));
    }
}
