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

int N;
string S;

int main(void) {
    cin >> N >> S;

    map<pair<string, string>, LL> left_mp;
    {
        REP(i, (1 << N)) {
            string red = "", blue = "";
            REP(j, N) {
                if (i & (1 << j)) {
                    red = red + S[j];
                } else {
                    blue = S[j] + blue;
                }
            }
            left_mp[MP(red, blue)]++;
        }
    }

    map<pair<string, string>, LL> right_mp;
    {
        REP(i, (1 << N)) {
            string red = "", blue = "";
            REP(j, N) {
                if (i & (1 << j)) {
                    red = red + S[N + j];
                } else {
                    blue = S[N + j] + blue;
                }
            }
            right_mp[MP(red, blue)]++;
        }
    }

    LL ans = 0;
    FORE(e, left_mp) {
        ans += e.second * right_mp[MP(e.first.second, e.first.first)];
    }
    cout << ans << endl;
}
