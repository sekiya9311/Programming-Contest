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

char strbuf[20];
int N;
VT<pair<int, string>> td;

int main(void) {
    scanf("%d", &N);
    td.resize(N);
    REP(i, N) {
        scanf("%d%s", &td[i].first, strbuf);
        td[i].second = strbuf;
    }
    int now = 0;
    REP(i, N) {
        if (td[i].second == "East" || td[i].second == "West") {
            if (now == 0 || now == 20000) {
                cout << "NO" << endl;
                return 0;
            } else {
                continue;
            }
        }
        if (td[i].second == "North") {//きた
            if (now == 0) {
                cout << "NO" << endl;
                return 0;
            }
            now -= td[i].first;
            if (now < 0) {
                cout << "NO" << endl;
                return 0;
            }
        } else {//みなみ
            if (now == 20000) {
                cout << "NO" << endl;
                return 0;
            }
            now += td[i].first;
            if (now > 20000) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << (now == 0 ? "YES" : "NO") << endl;
}
