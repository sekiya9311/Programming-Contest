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

vector<int> a = {4, 8, 15, 16, 23, 42};

int ans[6];

void get_01(int val, int st, int ab) {
    cout << "? " << st + 2 << " " << st + 3 << endl;
    int bc;
    cin >> bc;
    if (bc %val == 0) {
        ans[st] = ab / val;
        ans[st + 1] = val;
        ans[st + 2] = bc / val;
    } else {
        ans[st] = val;
        ans[st + 1] = ab / val;
        ans[st + 2] = bc / ans[st + 1];
    }
}

void get_03(int st, int ab, int bc) {
    vector<int> a = {4, 8, 16};
    do {
        vector<int> foo;
        foo.EB(a[0] * a[1]);
        foo.EB(a[1] * a[2]);
        if (foo[0] == ab && foo[1] == bc) {
            ans[st] = a[0];
            ans[st + 1] = a[1];
            ans[st + 2] = a[2];
        }
    } while (next_permutation(ALL(a)));
}

void get_02_2(int st, int val, int ab, int bc) {
    ans[st + 2] = val;
    ans[st + 1] = bc / val;
    ans[st] = ab / ans[st + 1];
}

void get_02(int st, int ab) {
    cout << "? " << st + 2 << " " << st + 3 << endl;
    int bc;
    cin >> bc;
    if (bc % 42 == 0) {
        get_02_2(st, 42, ab, bc);
    } else if (bc % 23 == 0) {
        get_02_2(st, 23, ab, bc);
    } else if (bc % 15 == 0) {
        get_02_2(st, 15, ab, bc);
    } else {
        get_03(st, ab, bc);
    }

}

int main(void) {
    cout << "? 1 2" << endl;
    int ab;
    cin >> ab;
    if (ab % 42 == 0) {
        get_01(42, 0, ab);
    } else if (ab % 23 == 0) {
        get_01(23, 0, ab);
    } else if (ab % 15 == 0) {
        get_01(15, 0, ab);
    } else {
        get_02(0, ab);
    }
    cout << "? 4 5" << endl;
    cin >> ab;
    if (ab % 42 == 0) {
        get_01(42, 3, ab);
    } else if (ab % 23 == 0) {
        get_01(23, 3, ab);
    } else if (ab % 15 == 0) {
        get_01(15, 3, ab);
    } else {
        get_02(3, ab);
    }

    cout << "! ";
    REP(i, 6) cout << ans[i] << (i + 1 == 6 ? "" : " ");
    cout << endl;
}
