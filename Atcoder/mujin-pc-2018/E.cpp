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

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

const int MAX = 1111;
int N, M, K;
string D;
string S[MAX];

LL mi[MAX][MAX];
int si, sj, gi, gj;
set<int> up_set, down_set, right_set, left_set;

bool inside(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M && S[x][y] != '#';
}

bool debug1 = false;
bool debug2 = false;
bool debug3 = false;

int main(void) {
    cin >> N >> M >> K;
    cin >> D;
    REP(i, K) {
        switch (D[i]) {
        case 'U':
            if (up_set.empty())
                up_set.emplace(i + K);
            up_set.emplace(i);
            break;
        case 'D':
            if (down_set.empty())
                down_set.emplace(i + K);
            down_set.emplace(i);
            break;
        case 'R':
            if (right_set.empty())
                right_set.emplace(i + K);
            right_set.emplace(i);
            break;
        case 'L':
            if (left_set.empty())
                left_set.emplace(i + K);
            left_set.emplace(i);
            break;
        }
    }
    if (debug3) {
        cerr<<"up_set: ";FORE(e, up_set) cerr << e << " ";cerr<<endl;
        cerr<<"down_set: ";FORE(e, down_set) cerr << e << " ";cerr<<endl;
        cerr<<"right_set: ";FORE(e, right_set) cerr << e << " ";cerr<<endl;
        cerr<<"left_set: ";FORE(e, left_set) cerr << e << " ";cerr<<endl;
        cerr<<endl;
    }
    REP(i, N) {
        cin >> S[i];
        REP(j, M) {
            if (S[i][j] == 'S') {
                si = i, sj = j;
            } else if (S[i][j] == 'G') {
                gi = i, gj = j;
            }
        }
    }
    REP(i, N) {
        REP(j, M) {
            if (i == si && j == sj) {
                mi[i][j] = 0;
            } else {
                mi[i][j] = LLINF;
            }
        }
    }
    priority_queue<pair<LL, PII>, VT<pair<LL, PII>>, greater<pair<LL, PII>>> pq;
    pq.emplace(MP(0LL, MP(si, sj)));
    while (!pq.empty()) {
        auto el = pq.top();
        pq.pop();
        auto nowCost = el.first;
        auto now = el.second;
        if (debug2)cerr << now.first << " " << now.second << " " << nowCost << endl;
        if (mi[now.first][now.second] < nowCost) {
            continue;
        }
        mi[now.first][now.second] = nowCost;
        if (inside(now.first - 1, now.second) && up_set.size()) {
            if(debug1)cerr<<"up!"<<endl;
            auto el = up_set.upper_bound(nowCost % K - 1);
            assert(*el - nowCost % K >= 0);
            if (mi[now.first - 1][now.second] > nowCost + (*el - nowCost % K) + 1)
                pq.emplace(MP(nowCost + (*el - nowCost % K) + 1, MP(now.first - 1, now.second)));
        }
        if (inside(now.first + 1, now.second) && down_set.size()) {
            if(debug1)cerr<<"down!"<<endl;
            auto el = down_set.upper_bound(nowCost % K - 1);
            assert(*el - nowCost % K >= 0);
            if (mi[now.first + 1][now.second] > nowCost + (*el - nowCost % K) + 1)
                pq.emplace(MP(nowCost + (*el - nowCost % K) + 1, MP(now.first + 1, now.second)));
        }
        if (inside(now.first, now.second - 1) && left_set.size()) {
            if(debug1)cerr<<"left!"<<endl;
            auto el = left_set.upper_bound(nowCost % K - 1);
            assert(*el - nowCost % K >= 0);
            if (mi[now.first][now.second - 1] > nowCost + (*el - nowCost % K) + 1)
                pq.emplace(MP(nowCost + (*el - nowCost % K) + 1, MP(now.first, now.second - 1)));
        }
        if (inside(now.first, now.second + 1) && right_set.size()) {
            if(debug1)cerr<<"right!"<<endl;
            auto el = right_set.upper_bound(nowCost % K - 1);
            assert(*el - nowCost % K >= 0);
            if (mi[now.first][now.second + 1] > nowCost + (*el - nowCost % K) + 1)
                pq.emplace(MP(nowCost + (*el - nowCost % K) + 1, MP(now.first, now.second + 1)));
        }
    }

    if(debug2){
        cerr<<endl;
        REP(i, N) {
            REP(j, M) cerr << mi[i][j] << " ";cout << endl;
        }
    }

    cout << (mi[gi][gj] == LLINF ? -1 : mi[gi][gj]) << endl;
}
