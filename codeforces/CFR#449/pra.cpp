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

const string f0 = "(f0)";
const string addFront = "(Front)";
const string addMiddle = "(Middle)";
const string addTop = "(Top)";
// f[i] = addFront + f[i - 1] + addMiddle + f[i - 1] + addTop
// f[i + 1] = addFront + f[i] + addMiddle + f[i] + addTop
// = addFront + addFront + f[i - 1] + addMiddle + f[i - 1] + addTop + addMiddle + addFront + f[i - 1] + addMiddle + f[i - 1] + addTop + addTop
// = addFront + addFront + addFront + f[i - 2] + addMiddle + f[i - 2] + addTop + addMiddle + addFront + f[i - 2] + addMiddle + f[i - 2] + addTop + addTop + addMiddle + addFront + addFront + f[i - 2] + addMiddle + f[i - 2] + addTop + addMiddle + addFront + f[i - 2] + addMiddle + f[i - 2] + addTop + addTop + addTop
// n, k <- f[n]のk文字目求めてね♪

// f[1] = addFront + f0 + addMiddle + f0 + addTop
// f[2] = addFront + f[1] + addMiddle + f[1] + addTop
//      = addFront + addFront + f0 + addMiddle + f0 + addTop + addMiddle + addFront + f0 + addMiddle + f0 + addTop + addTop
//      = (addFront * 2) + f0 + addMiddle + f0 + addTop + addMiddle + addFront + f0 + addMiddle + f0 + (addTop * 2)
// f[3] = addFront + f[2] + addMiddle + f[2] + addTop
//      = addFront + addFront + f[1] + addMiddle + f[1] + addTop + addMiddle + addFront + f[1] + addMiddle + f[1] + addTop + addTop
//      = addFront + addFront + addFront + f0 + addMiddle + f0 + addTop + addMiddle + addFront + f0 + addMiddle + f0 + addTop + addTop + addMiddle + addFront + addFront + f0 + addMiddle + f0 + addTop + addMiddle + addFront + f0 + addMiddle + f0 + addTop + addTop + addTop
//      = (aF * 3) + f0 + aM + f0 + aT + aM + aF + f0 + aM + f0 + (aT) * 2 + aM + (af) * 2 + f0 + aM + f0 + aT + aM + aF + f0 + aM + f0 + (aT) * 3
pair<pair<LL, LL>, int> nk[11];

int main(void) {
    string now = f0;
    REP(i, 5) {
        now = addFront + now + addMiddle + now + addTop;
        cout << now << endl;
    }
}
