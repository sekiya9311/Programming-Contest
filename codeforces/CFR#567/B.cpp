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

string calc_impl(string l, string r) {

    REVERSE(l);
    REVERSE(r);
    if (l.size() != r.size()) {
        if (l.size() < r.size()) l += string(r.size() - l.size(), '0');
        else r += string(l.size() - r.size(), '0');
    }

    const int len = l.size();
    string ret = string(len, '0');
    bool carry = false;
    REP(i, len) {
        int lv = l[i] - '0';
        int rv = r[i] - '0';
        int sum = lv + rv + carry;
        carry = false;
        if (sum >= 10) {
            carry = true;
            sum -= 10;
        }
        ret[i] = (char)(sum + '0');
    }
    if (carry) ret += "1";
    REVERSE(ret);

    return ret;
}

const int MAX = 1e5;
int L;
string S;

string calc2(int mid) {
    string l = S.substr(0, mid);
    string r = S.substr(mid);

    return calc_impl(l, r);
}

string min_str(string l, string r) {
    if (l.size() < r.size()) return l;
    else if (l.size() > r.size()) return r;

    return min(l, r);
}


string calc(int mid) {
    int tmp_m = mid;
    string tmp = S;

    while (mid + 1 < L && S[mid] == '0') mid++;
    if (mid + 1 < L) tmp = min_str(tmp, calc2(mid));

    mid = tmp_m;
    while (mid > 0 && S[mid] == '0') mid--;
    if (mid > 0) {
        tmp = min_str(tmp, calc2(mid));
    }

    return tmp;
}

int main(void) {
    cin >> L;
    cin >> S;

    if (L % 2 == 0) {
        cout << calc(L / 2) << endl;
    } else {
        auto ans = calc(L / 2);
        ans = min_str(ans, calc(L / 2 + 1));
        cout << ans << endl;
    }
}
