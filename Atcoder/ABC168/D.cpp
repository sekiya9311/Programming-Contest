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
int N, M;
int A[MAX], B[MAX];
VI G[MAX];

int dist[MAX];
int ans[MAX];
void calc_dist() {
    fill(dist, dist + MAX, INF);
    fill(ans, ans + MAX, -1);
    queue<PII> que;
    que.emplace(0, -1);
    while (!que.empty()) {
        const auto el = que.front();
        que.pop();
        if (dist[el.first] != INF) continue;
        if (el.second != -1) {
            dist[el.first] = dist[el.second] + 1;
            ans[el.first] = el.second;
        } else {
            dist[el.first] = 0;
        }
        FORE(e, G[el.first]) if (e != el.second && dist[e] == INF) {
            que.emplace(e, el.first);
        }
    }
}

int main(void) {
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].EB(B[i]);
        G[B[i]].EB(A[i]);
    }
    calc_dist();

    REP(i, N - 1) if (ans[i + 1] == -1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    REP(i, N - 1) {
        cout << ans[i + 1] + 1 << endl;
    }
}
