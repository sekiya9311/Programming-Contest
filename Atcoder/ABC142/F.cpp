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

const int MAX_N = 1111;
const int MAX_M = 2222;
int N, M;
int A[MAX_M], B[MAX_M];
VI G[MAX_N], prev_G[MAX_N];

VI ans;
int vis[MAX_N];

bool check(const int start, int total_cost) {
    set<int> pre;
    int cur = start;

    do {
        FORE(e, prev_G[cur]) {
            if (vis[e] == total_cost - 1) {
                pre.emplace(e);
                cur = e;
                total_cost--;
                break;
            }
        }
    } while (cur != start);

    FORE(e, pre) {
        int cnt = 0;
        FORE(nxt, G[e]) cnt += pre.count(nxt);
        if (cnt != 1) return false;
    }

    FORE(e, pre) {
        ans.EB(e);
    }
    return true;
}

bool bfs(const int start) {
    memset(vis, -1, sizeof(vis));
    queue<PII> que;

    que.emplace(start, 0);
    while (!que.empty()) {
        const auto cur = que.front();
        que.pop();

        if (vis[cur.first] != -1) {
            if (cur.first == start) {
                if (check(start, cur.second)) {
                    return true;
                }
            }
            continue;
        }
        vis[cur.first] = cur.second;

        FORE(e, G[cur.first]) if (vis[e] == -1 || e == start) {
            que.emplace(e, cur.second + 1);
        }
    }

    return false;
}

int main(void) {
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        G[A[i]].EB(B[i]);
        prev_G[B[i]].EB(A[i]);
    }

    REP(i, N) {
        if (bfs(i)) {
            break;
        }
    }

    if (ans.empty()) cout << -1 << endl;
    else {
        printf("%d\n", (int)ans.size());
        FORE(e, ans) printf("%d\n", e + 1);
    }
}
