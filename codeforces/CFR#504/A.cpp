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

vector<string> split(const string &originalStr, char sep) {
    vector<string> res;
    string element = "";
    for (const char c : originalStr) {
        if (c == sep) {
            res.emplace_back(element);
            element.clear();
        } else {
            element += c;
        }
    }
    if (!element.empty()) {
        res.emplace_back(element);
    }
    return res;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (s[0] == '*') {
        REVERSE(s);
        REVERSE(t);
    }
    if (s.back() == '*') {
        REP(i, s.size() - 1) {
            if (s[i] != t[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    } else {
        auto sp = split(s, '*');
        if (sp.size() == 2) {

            if (sp[0].size() + sp[1].size() > t.size()) {
                cout << "NO" << endl;
                return 0;
            }
            REP(i, sp[0].size()) {
                if (sp[0][i] != t[i]) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            int foo = t.size() - 1;
            RREP(i, sp[1].size()) {
                if (sp[1][i] != t[foo]) {
                    cout << "NO" << endl;
                    return 0;
                }
                foo--;
            }
            cout << "YES" << endl;

        } else {
            if (s == t) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
