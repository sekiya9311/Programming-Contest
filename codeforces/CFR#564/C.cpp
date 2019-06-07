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
int a[MAX], b[MAX];
int one_idx;

int calc1() {
    priority_queue<int, VI, greater<int>> pq;
    REP(i, N) {
        if (a[i] == 0) pq.emplace(INF);
        else pq.emplace(a[i]);
    }

    int nxt_need = b[N - 1] + 1;
    int cnt = 0;
    int b_idx = 0;
    while (b_idx < one_idx) {
        auto cur = pq.top();
        if (cur != nxt_need) {
            cnt = INF;
            break;
        }
        pq.pop();
        if (b[b_idx]) pq.emplace(b[b_idx]);
        else pq.emplace(INF);
        b_idx++;
        cnt++;
        nxt_need++;
    }

    return cnt;
}

int calc_impl(int mid) {

    priority_queue<int, VI, greater<int>> pq;
    REP(i, N) {
        if (a[i]) pq.emplace(a[i]);
        else pq.emplace(INF);
    }
    int cnt = 0;
    REP(i, mid) {
        if (b[i]) pq.emplace(b[i]);
        else pq.emplace(INF);
        cnt++;
    }

    queue<int> que;
    FOR(i, mid, N) {
        que.emplace(b[i]);
    }

    REP(i, N) {
        auto cur = pq.top();
        if (cur != i + 1) {
            cnt = INF;
            break;
        }

        pq.pop();
        if (!que.empty() && que.front()) {
            pq.emplace(que.front());
        } else {
            pq.emplace(INF);
        }
        if (!que.empty()) que.pop();
        cnt++;
    }


    return cnt;
}

int calc2() {

    int ok = N, ng = -1;
    while (ok - ng > 1) {
        const int mid = (ok + ng) / 2;

        const auto res = calc_impl(mid);
        if (res == INF) {
            ng = mid;
        } else {
            ok = mid;
        }
    }

    return calc_impl(ok);
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", a + i);
    REP(i, N) scanf("%d", b + i);

    bool beautiful = false;
    REP(i, N) {
        if (b[i] == 1) {
            beautiful = true;
            one_idx = i;
            FOR(j, i + 1, N) {
                if (b[j] != j - i + 1) {
                    beautiful = false;
                    break;
                }
            }
            break;
        }
    }

    int ans = INF;

    if (beautiful) {
        chmin(ans, calc1());
    }

    chmin(ans, calc2());

    cout << ans << endl;
}
