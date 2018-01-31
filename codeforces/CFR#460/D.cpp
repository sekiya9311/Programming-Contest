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

class TopologicalSort {
private:
    vector<bool> is;
    vector<vector<int>> g;
    vector<int> tsort;
    vector<long long> inCnt;
    void dfs(int now) {
        if (is[now]) return;
        is[now] = true;
        for (auto &&el : g[now]) {
            dfs(el);
        }
        tsort.emplace_back(now);
    }
public:
    TopologicalSort() {}
    TopologicalSort(const int N) {
        is.resize(N);
        g.resize(N);
        inCnt.resize(N);
    }
    vector<int> dfsTsort() {
        for (int i = 0; i < g.size(); i++) {
            dfs(i);
        }
        reverse(tsort.begin(), tsort.end());
        return tsort;
    }
    void addEdge(int src, int dst) {
        g[src].emplace_back(dst);
        inCnt[dst]++;
    }
    vector<int> bfsTsort() {
        queue<int> q;
        for (int i = 0; i < inCnt.size(); i++) {
            if (inCnt[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto now = q.front(); q.pop();
            tsort.emplace_back(now);
            for (auto &&el : g[now]) {
                if (--inCnt[el] == 0) q.push(el);
            }
        }
        bool endFlag = true;
        for (auto &&el : inCnt) {
            if (el) endFlag = false;
        }
        return (endFlag ? tsort : vector<int>());
    }
};

const int MAX = 3e5 + 10;
char strbuf[MAX];
string next() {
    scanf("%s", strbuf);
    return strbuf;
}
int N, M;
VI G[MAX], revG[MAX];
string S;
TopologicalSort ts;
int dp[MAX];

int main(void) {
    scanf("%d%d", &N, &M);
    ts = TopologicalSort(N);
    S = next();
    REP(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        G[a].EB(b);
        ts.addEdge(a, b);
    }
    auto tsn = ts.bfsTsort();
    if (tsn.size() == 0) {
        cout << -1 << endl;
    } else {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            memset(dp, 0, sizeof(dp));
            FORE(e, tsn) {
                if (S[e] == c) dp[e]++;
                FORE(ee, G[e]) {
                    chmax(dp[ee], dp[e]);
                }
            }
            REP(i, N) {
                chmax(ans, dp[i]);
            }
        }
        cout << ans << endl;
    }
}
