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

const int MAX = 1e5 + 10;
char strbuf[MAX];
string next() {
scanf("%s", strbuf);
return strbuf;
}

string S, T;
int N;
int sb[MAX], tb[MAX];

int main(void) {
    S = next();
    T = next();
    REP(i, S.size()) sb[i] = (S[i] == 'B') + 1;
    REP(i, (int)S.size() - 1) sb[i + 1] += sb[i];
    REP(i, T.size()) tb[i] = (T[i] == 'B') + 1;
    REP(i, (int)T.size() - 1) tb[i + 1] += tb[i];
    scanf("%d", &N);
    REP(i, N) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        --a;--b;--c;--d;
        int ss = (a == 0 ? sb[b] : sb[b] - sb[a - 1]);
        int tt = (c == 0 ? tb[d] : tb[d] - tb[c - 1]);
        printf("%s\n", (ss % 3 == tt % 3 ? "YES" : "NO"));
    }
}
