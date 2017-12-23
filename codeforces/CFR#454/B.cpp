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

string s[3][3][3];
int ni, nj, nk, nl;

int main(void) {
    REP(i, 3) {
        REP(k, 3) {
            REP(j, 3) {
                cin >> s[i][j][k];
            }
        }
    }
    {
        int x, y;
        cin >> x >> y;
        x--;y--;
        ni = x / 3;
        nj = y / 3;
        nk = x % 3;
        nl = y % 3;
    }
    bool ok = false;
    REP(i, 3) {
        REP(j, 3) {
            if (s[nk][nl][i][j] == '.') {
                ok = true;
                s[nk][nl][i][j] = '!';
            }
        }
    }
    if (!ok) {
        REP(i, 3) {
            REP(j, 3) {
                REP(k, 3) {
                    REP(l, 3) {
                        if (s[i][j][k][l] == '.') {
                            s[i][j][k][l] = '!';
                        }
                    }
                }
            }
        }
    }
    REP(i, 3) {
        REP(k, 3) {
            REP(j, 3) {
                cout << s[i][j][k] << " ";
            }cout << endl;
        }cout << endl;
    }
}
