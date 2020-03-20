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

string manachar(string S) {
    string ans = "";
    const int L = S.length();
    VI ma(L);
    if (L == 0) return "";
    if (L == 1) return S;
    int i = 0, j = 0;
    while (i < L) {
        while (i - j >= 0 && i + j < L && S[i - j] == S[i + j]) {
            j++;
        }
        ma[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < L && k + ma[i - k] < j) {
            ma[i + k] = ma[i - k];
            k++;
        }
        i += k;
        j -= k;
    }

    VPII v;
    REP(i, L) {
        if (ma[i] == i + 1 || ma[i] == L - i) {
            v.EB(ma[i], i);
        }
    }

    string res = "";
    if (v.size()) {
        RSORT(v);
        FOR(i, v[0].second - v[0].first + 1, v[0].second + v[0].first) {
            res += S[i];
        }
    }
    return res;
}

void solve(string &S) {
    const int L = S.length();
    int l = 0, r = L - 1;
    while (l < r && S[l] == S[r]) {
        l++;
        r--;
    }
    // S[l + 1] != S[r - 1]
    string front = "", back = "";
    REP(i, l) {
        front += S[i];
    }
    FOR(i, r + 1, L) {
        back += S[i];
    }

    string mid1 = "", mid2 = "";
    FOR(i, l, r + 1) {
        mid1 += S[i];
        mid2 += S[i];
        mid2 += "*";
    }
    if (mid2.length()) {
        mid2.pop_back();
    }

    string tmp1 = manachar(mid1);
    string tmp2 = manachar(mid2);
    string tmp3 = "";
    FORE(e, tmp2) if (e != '*') {
        tmp3 += e;
    }

    // DEBUG(l)
    // DEBUG(r)
    // DEBUG(front)
    // DEBUG(back)
    // DEBUG(mid1)
    // DEBUG(mid2)
    // DEBUG(tmp1)
    // DEBUG(tmp2)
    // cerr<<endl;

    if (tmp1.length() < tmp3.length()) {
        puts((front + tmp3 + back).c_str());
    } else {
        puts((front + tmp1 + back).c_str());
    }
}

const int MAX = 1e6 + 10;
char strbuf[MAX];

int main(void) {
    int t;
    cin >> t;
    int pre_l, pre_r;
    int ma = 0;
    REP(_, t) {
        scanf("%s", strbuf);
        string S = strbuf;
        solve(S);
    }
}
