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

int main(void) {
    string S;
    cin >> S;
    int l = S.size();
    {
        bool st = false, st2 = false;
        REP(i, S.size()) {
            if (!st) {
                if (S[i] == '[') {
                    st = true;
                }
            } else if (!st2) {
                if (S[i] == ':') {
                    st2 = true;
                     l = i;
                     break;
                }
            }
        }
    }
    int r = -1;
    {
        bool ed2 = false, ed = false;
        RREP(i, S.size()) {
            if (!ed) {
                if (S[i] == ']') {
                    ed = true;
                }
            } else if (!ed2) {
                if (S[i] == ':') {
                    ed2 = true;
                    r = i;
                    break;
                }
            }
        }
    }
    if (l < r) {
        int cnt = 0;
        FOR(i, l, r) {
            if (S[i] == '|') {
                cnt++;
            }
        }
        cout << cnt + 4 << endl;
    } else {
        cout << -1 << endl;
    }
}
