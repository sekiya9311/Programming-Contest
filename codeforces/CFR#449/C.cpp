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

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string addFront = "What are you doing while sending \"";
const string addMiddle = "\"? Are you busy? Will you send \"";
const string addTop = "\"?";
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

// f[i].size() = f[i - 1] * 2 + (addFront + addMiddle + addTop).size()
LL fSize[56];

char dfs(LL now, LL fIdx) {
    if (fIdx == 0) {
        if (now < fSize[0]) {
            return f0[now];
        } else {
            return '.';
        }
    }
    if (now < addFront.size()) {
        return addFront[now];
    }
    now -= addFront.size();
    if (fIdx >= 56) {
        return dfs(now, fIdx - 1);
    }
    if (now < fSize[fIdx - 1]) {
        return dfs(now, fIdx - 1);
    }
    now -= fSize[fIdx - 1];
    if (now < addMiddle.size()) {
        return addMiddle[now];
    }
    now -= addMiddle.size();
    if (now < fSize[fIdx - 1]) {
        return dfs(now, fIdx - 1);
    }
    now -= fSize[fIdx - 1];
    if (now < addTop.size()) {
        return addTop[now];
    }
    return '.';
}

int main(void) {
    int q;
    scanf("%d", &q);
    string ans = "";
    fSize[0] = f0.size();
    FOR(i, 1, 56) {
        fSize[i] = fSize[i - 1] * 2 + (addFront + addMiddle + addTop).size();
    }
    REP(i, q) {
        LL k, n;
        cin >> n >> k;
        k--;
        ans += dfs(k, n);
    }
    cout << ans << endl;
}
