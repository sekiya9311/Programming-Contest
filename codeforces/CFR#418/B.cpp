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

const int MAX = 1111;
int N;
int a[MAX], b[MAX];
set<int> se;

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", a + i);
        se.insert(a[i]);
    }
    REP(i, N) {
        scanf("%d", b + i);
        se.insert(b[i]);
    }
    vector<int> difIdx;
    REP(i, N) {
        if (a[i] != b[i]) {
            difIdx.EB(i);
        }
    }
    if (difIdx.size() == 0) {
        int now = 1;
        while (se.count(now)) ++now;
        printf("%d ", now);
        FOR(i, 1, N) {
            printf("%d%c", a[i], (i + 1 == N ? '\n' : ' '));
        }
    } else if (difIdx.size() == 1) {
        REP(i, N) {
            int now = 1;
            if (difIdx[0] == i) {
                while (se.count(now)) ++now;
            } else {
                now = a[i];
            }
            printf("%d%c", now, (i + 1 == N ? '\n' : ' '));
        }
    } else {
        set<int> eq, neq;
        REP(i, N) {
            if (a[i] == b[i]) {
                eq.insert(a[i]);
            }
        }
        REP(i, N) {
            if (a[i] != b[i]) {
                if (eq.count(a[i]) == 0) {
                    neq.insert(a[i]);
                }
                if (eq.count(b[i]) == 0) {
                    neq.insert(b[i]);
                }
            }
        }
        if (neq.count(a[difIdx[0]]) && neq.count(b[difIdx[1]])) {
            REP(i, N) {
                int out = a[i];
                if (a[i] != b[i]) {
                    if (i == difIdx[0]) {
                        out = a[i];
                    } else {
                        out = b[i];
                    }
                }
                printf("%d%c", out, (i + 1 == N ? '\n' : ' '));
            }
        } else {
            REP(i, N) {
                int out = a[i];
                if (a[i] != b[i]) {
                    if (i == difIdx[0]) {
                        out = b[i];
                    } else {
                        out = a[i];
                    }
                }
                printf("%d%c", out, (i + 1 == N ? '\n' : ' '));
            }
        }
    }
}
