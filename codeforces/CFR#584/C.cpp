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

const int MAX_T = 1e4 + 10;
const int MAX_N = 2e5 + 10;
int T;
int N;
string S;
int ans[MAX_N];

string next() {
    static char strbuf[MAX_N];
    scanf("%s", strbuf);
    return strbuf;
}

bool check() {
    int pre = -1;
    REP(d, 2) {
        REP(i, N) if (ans[i] == d + 1) {
            const int cur = S[i] - '0';
            if (pre > cur) return false;
            pre = cur;
        }
    }
    return true;
}

void calc() {
    scanf("%d", &N);
    S = next();

    {
        bool ok = true;
        FOR(i, 1, N) {
            if (S[i - 1] > S[i]) ok = false;
        }
        if (ok) {
            printf("%s\n", string(N, '1').c_str());
            return;
        }
    }


    REP(d, 10) {
        int sec_prev = d;
        REP(i, N) {
            const int cur = S[i] - '0';
            if (cur < d) {
                ans[i] = 1;
            } else if (cur == d) {
                if (sec_prev == d) ans[i] = 2;
                else ans[i] = 1;
            } else {
                ans[i] = 2;
                sec_prev = max(cur, sec_prev);
            }
        }

        string str = string(N, '0');
        REP(j, N) str[j] = ans[j] + '0';
        if (check()) {
            printf("%s\n", str.c_str());
            return;
        }
    }
    puts("-");
}

int main(void) {
    scanf("%d", &T);
    while (T--) {
        calc();
    }
}
