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
#define GREATER(T) T, VT<T>, greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const LL COUNT = 1e10;
const LL LENGTH = COUNT * 3;
const LL ONE_COUNT = COUNT * 2;
const LL ZERO_COUNT = COUNT;

bool valid(const string &S) {
    int one = 0, zero = 0;
    FORE(c, S) {
        if (c == '1') {
            one++;
            zero = 0;
            if (one == 3) return false;
        } else {
            one = 0;
            zero++;
            if (zero == 2) return false;
        }
    }
    return true;
}

bool check(const string &S) {
    if (S.length() % 3) return false;
    REP(i, S.length()) {
        if (i % 3 == 0 || i % 3 == 1) {
            if (S[i] != '1') return false;
        } else {
            if (S[i] != '0') return false;
        }
    }
    return true;
}

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    N = S.length();

    if (N == 1) {
        if (S == "1") cout << ONE_COUNT << endl;
        else cout << ZERO_COUNT << endl;
        return;
    }

    bool ok = false;
    REP(i, 3) REP(j, 3) {
        const auto left = i == 0 ? "" : i == 1 ? "1" : "11";
        const auto right = j == 0 ? "" : j == 1 ? "0" : "10";
        const auto cur = left + S + right;
        if (check(cur)) {
            S = cur;
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << 0 << endl;
        return;
    }

    const auto ans = COUNT - (S.length() / 3) + 1;
    cout << ans << endl;
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
