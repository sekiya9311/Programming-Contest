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

const int MAX = 1e5 + 10;
int N;
int val[3];
string S[MAX];
int p[MAX][2];

void failed() {
    cout << "No" << endl;
    exit(0);
}

void go(VI &ans, int idx, int add_idx) {
    ans.EB(p[idx][add_idx]);
    val[p[idx][add_idx]]++;
    val[p[idx][add_idx ^ 1]]--;
}

void normal() {
    VI ans;
    REP(i, N) {
        if (val[p[i][0]] == 0 && val[p[i][1]] == 0) {
            failed();
        }
        if (val[p[i][0]] < val[p[i][1]]) {
            go(ans, i, 0);
        } else {
            go(ans, i, 1);
        }
    }

    cout << "Yes" << "\n";
    FORE(e, ans) cout << (char)(e + 'A') << "\n";
}

void irregular() {
    VI ans;
    REP(i, N) {
        if (val[p[i][0]] == 0 && val[p[i][1]] == 0) {
            failed();
        }
        if (val[p[i][0]] < val[p[i][1]]) {
            go(ans, i, 0);
        } else if (val[p[i][0]] > val[p[i][1]]) {
            go(ans, i, 1);
        } else if (val[p[i][0]] == val[p[i][1]]) {
            if (i + 1 == N) {
                go(ans, i, 0);
            } else {
                if (p[i][0] == p[i + 1][0] || p[i][0] == p[i + 1][1]) {
                    go(ans, i, 0);
                } else {
                    go(ans, i, 1);
                }
            }
        }
    }

    cout << "Yes" << "\n";
    FORE(e, ans) cout << (char)(e + 'A') << "\n";
}

int main(void) {
    cin >> N; REP(i, 3) cin >> val[i];
    REP(i, N) {
        cin >> S[i];
        REP(j, 2) p[i][j] = S[i][j] - 'A';
    }

    const auto sum = 1LL * val[0] + val[1] + val[2];
    if (sum == 0) {
        failed();
    } else if (sum == 2) {
        irregular();
    } else {
        normal();
    }
}
