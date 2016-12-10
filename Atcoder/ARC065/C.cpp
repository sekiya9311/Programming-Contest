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

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

set<string> se;

int main(void) {
    string s;
    cin >> s;
    se.insert("dream");
    se.insert("dreamer");
    se.insert("erase");
    se.insert("eraser");
    int cnt = 0;
    if (s.size() < 5) {
        cout << "NO" << endl;
        return 0;
    }
    if (FIND(se, s)) {
        cout << "YES" << endl;
        return 0;
    } else if (s.size() < 10) {
        cout << "NO" << endl;
        return 0;
    }
    while (s.size() != 0) {
        if (FIND(se, s)) {
            cout << "YES" << endl;
            return 0;
        } else if (s.size() < 10) {
            cout << "NO" << endl;
            return 0;
        }
        string buf = "";
        if (s.front() == 'd') {
            buf = s.substr(0, 8);
            if (buf.substr(0, 5) != "dream") {
                cout << "NO" << endl;
                return 0;
            }
            if (buf.back() == 'a' || buf[5] == 'd') {
                s.erase(s.begin(), s.begin() + 5);
            } else if (buf.substr(0, 7) == "dreamer" && (buf.back() == 'e' || buf.back() == 'd')) {
                s.erase(s.begin(), s.begin() + 7);
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (s.front() == 'e') {
            buf = s.substr(0, 7);
            if (buf.substr(0, 5) != "erase") {
                cout << "NO" << endl;
                return 0;
            }
            if ((buf[5] == 'e' || buf[5] == 'd') && buf[6] == 'r') {
                s.erase(s.begin(), s.begin() + 5);
            } else if (buf.substr(0, 6) == "eraser" && (buf[6] == 'd' || buf[6] == 'e')) {
                s.erase(s.begin(), s.begin() + 6);
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            cout << "NO" << endl;
            return 0;
        }
        DEBUG(s)
    }
    cout << "YES" << endl;
}
