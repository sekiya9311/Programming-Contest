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

const int MAX = 1111;
int N;
int A[MAX][MAX];
int day[MAX][MAX];
int ptr[MAX];
unordered_set<int> already_battled_day[MAX];

int main(void) {
    cin >> N;
    REP(i, N) {
        REP(j, N - 1) {
            cin >> A[i][j];
            A[i][j]--;
        }
        A[i][N - 1] = -1;
    }

    memset(day, -1, sizeof(day));

    queue<int> que;
    {
        set<int> al;
        REP(i, N) {
            const int enemy = A[i][0];
            if (i == A[enemy][0] && al.count(i) == 0 && al.count(enemy) == 0) {
                que.emplace(i);
                que.emplace(enemy);

                al.emplace(i);
                al.emplace(enemy);

                day[i][0] = 1;
                day[enemy][0] = 1;

                ptr[i]++;
                ptr[enemy]++;
            }
        }
    }

    while (!que.empty()) {
        const auto cur = que.front();
        que.pop();

        const int enemy = A[cur][ptr[cur]];
        if (A[enemy][ptr[enemy]] == cur) {
            const int nxt_battle_day = max(
                ptr[cur] > 0 ? day[cur][ptr[cur] - 1] : 0,
                ptr[enemy] > 0 ? day[enemy][ptr[enemy] - 1] : 0
            ) + 1;
            day[cur][ptr[cur]] = nxt_battle_day;
            day[enemy][ptr[enemy]] = nxt_battle_day;

            ptr[cur]++;
            ptr[enemy]++;

            que.emplace(cur);
            que.emplace(enemy);
        }
    }

    int ans = 0;
    REP(i, N) {
        if (day[i][N - 2] == -1) {
            cout << -1 << endl;
            return 0;
        }
        chmax(ans, day[i][N - 2]);
    }
    cout << ans << endl;
}
