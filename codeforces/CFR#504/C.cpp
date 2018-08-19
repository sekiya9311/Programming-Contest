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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N, K;
string S;
const int MAX = 2e5 + 10;
unordered_set<LL> rankPairIdx[MAX];
bool valid[MAX], vis[MAX];

int dfs(int now, int rank) {
    FOR(i, now + 1, N) {
        if (S[i] == ')' && !vis[i]) {
            vis[i] = true;
            rankPairIdx[rank].emplace(1LL * now * MAX + i);
            return i;
        } else if (S[i] == '(' && !vis[i]) {
            vis[i] = true;
            i = dfs(i, rank + 1);
        }
    }
    return 0;
}

int main(void) {
    cin >> N >> K;
    cin >> S;
    REP(i, N) valid[i] = true;
    REP(i, N) if (!vis[i]) {
        vis[i] = true;
        dfs(i, 0);
    }

    int ma = 0;
    RREP(i, MAX) {
        if (rankPairIdx[i].size()) {
            ma = i;
            break;
        }
    }
    auto n = N;
    while (n > K) {
        if (rankPairIdx[ma].size() == 0) {
            ma--;
        } else {
            auto itr = rankPairIdx[ma].begin();
            valid[*itr / MAX] = false;
            valid[*itr % MAX] = false;
            n -= 2;
            rankPairIdx[ma].erase(itr);
        }
    }
    string ans = "";
    REP(i, N) {
        if (valid[i]) {
            //ans += S[i];
            //cout << S[i];
            putchar(S[i]);
        }
    }
    puts("");
    //cout << ans << endl;
}
