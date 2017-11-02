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

int N;
string S;
VT<string> anses;

int main(void) {
    cin >> N >> S;
    anses.EB("SS");
    anses.EB("WW");
    anses.EB("WS");
    anses.EB("SW");
    FOR(i, 1, N - 1) {
        REP(j, 4) {
            if (anses[j][i] == 'S') {
                if (S[i] == 'o') {
                    anses[j] += anses[j][i - 1];
                } else {
                    anses[j] += anses[j][i - 1] == 'W' ? 'S' : 'W';
                }
            } else {
                if (S[i] == 'o') {
                    anses[j] += anses[j][i - 1] == 'W' ? 'S' : 'W';
                } else {
                    anses[j] += anses[j][i - 1];
                }
            }
        }
    }
    VT<string> buf;
    FORE(e, anses) {
        assert(e.length() == N);
        bool ok = true;
        REP(i, N) {
            if (e[i] == 'S') {
                if (S[i] == 'o') {
                    if (e[(i - 1 + N) % N] != e[(i + 1) % N]) ok = false;
                } else {
                    if (e[(i - 1 + N) % N] == e[(i + 1) % N]) ok = false;
                }
            } else {
                if (S[i] == 'o') {
                    if (e[(i - 1 + N) % N] == e[(i + 1) % N]) ok = false;
                } else {
                    if (e[(i - 1 + N) % N] != e[(i + 1) % N]) ok = false;
                }
            }
        }
        if (ok) buf.EB(e);
    }
    anses = buf;
    if (anses.size()) {
        cout << anses[0] << endl;
    } else {
        cout << -1 << endl;
    }
}
