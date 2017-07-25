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

const int MAX = 1e5 + 10;
string a, b;
int n;
char strbuf[MAX];
string next() {
scanf("%s", strbuf);
return strbuf;
}

bool check(const string S, const string s, set<char> se) {
    if (S.size() != s.size()) return false;
    REP(i, S.size()) {
        if (s[i] == '?' || s[i] == '*') {
            if (s[i] == '?' && se.count(S[i]) == 0) return false;
        } else {
            if (S[i] != s[i]) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    a = next();
    set<char> se;
    se.insert(ALL(a));
    b = next();
    bool includeAst = false;
    string SS = "", SS2 = "";
    REP(i, b.size()) {
        includeAst |= (b[i] == '*');
        if ((b[i] == '*')) continue;
        if (includeAst) SS2 += b[i];
        else SS += b[i];
    }
    scanf("%d", &n);
    REP(_, n) {
        string S = next();
        string ss = SS;
        string ss2 = SS2;
        bool ok = true;
        if (includeAst) {
            if (ss.size() > S.size()) {
                ok = false;
                goto nxt;
            }
            REP(i, ss.size()) {
                assert(ss[i] != '*');
                if (ss[i] == '?') {
                    if (se.count(S[i]) == 0) {
                        ok = false;
                        goto nxt;
                    }
                } else if (ss[i] != S[i]) {
                    ok = false;
                    goto nxt;
                }
            }
            REVERSE(S);
            REP(i, ss.size()) S.pop_back();
            REVERSE(ss2);
            if (ss2.size() > S.size()) {
                ok = false;
                goto nxt;
            }
            REP(i, ss2.size()) {
                assert(ss2[i] != '*');
                if (ss2[i] == '?') {
                    if (se.count(S[i]) == 0) {
                        ok = false;
                        goto nxt;
                    }
                } else if (ss2[i] != S[i]) {
                    ok = false;
                    goto nxt;
                }
            }
            REVERSE(S);
            REP(i, ss2.size()) S.pop_back();
            REP(i, S.size()) if (se.count(S[i])) {
                ok = false;
                goto nxt;
            }
        } else {
            if (ss.size() != S.size()) {
                ok = false;
                goto nxt;
            } else {
                REP(i, S.size()) {
                    if (ss[i] == '?') {
                        if (se.count(S[i]) == 0) {
                            ok = false;
                            goto nxt;
                        }
                    } else if (ss[i] != S[i]) {
                        ok = false;
                        goto nxt;
                    }
                }
            }
        }
        nxt:
        cout << (ok ? "YES" : "NO") << endl;
    }
}
