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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX_P = 555;
const int MAX_Q = 1e5 + 10;
int P, Q;
int X[MAX_P], Y[MAX_P];
char D[MAX_P];

int x_imos[MAX_Q], y_imos[MAX_Q];

void solve(int testNum) {
    stringstream ss;
    scanf("%d%d", &P, &Q);
    REP(i, P) {
        scanf("%d%d", X + i, Y + i);
        char strbuf[10];
        scanf("%s", strbuf);
        D[i] = strbuf[0];
    }

    memset(x_imos, 0, sizeof(x_imos));
    memset(y_imos, 0, sizeof(y_imos));

    REP(i, P) {
        if (D[i] == 'N') {
            y_imos[Y[i] + 1]++;
            // y_min = max(y_min, Y[i] + 1);
        } else if (D[i] == 'S') {
            y_imos[0]++;
            y_imos[Y[i]]--;
            // y_max = min(y_max, Y[i] - 1);
        } else if (D[i] == 'E') {
            x_imos[X[i] + 1]++;
            // x_min = max(x_min, X[i] + 1);
        } else {
            x_imos[0]++;
            x_imos[X[i]]--;
            // x_max = min(x_max, X[i] - 1);
        }
    }

    REP(i, Q) {
        x_imos[i + 1] += x_imos[i];
        y_imos[i + 1] += y_imos[i];
    }

    int max_x = -1, max_y = -1;
    int ans_x = -1, ans_y = -1;
    REP(i, Q + 1) {
        if (x_imos[i] > max_x) {
            max_x = x_imos[i];
            ans_x = i;
        }
        if (y_imos[i] > max_y) {
            max_y = y_imos[i];
            ans_y = i;
        }
    }

    ss << ans_x << " " << ans_y << '\n';
    cout << "Case #" << testNum << ": " << ss.str();
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        //cerr << "Case #" << testNum << ": solved" << endl;
    }
}
