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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

bool check(const string &l, const string &r) {
    const int L = min(l.length(), r.length());
    REP(i, L) if (l[i] != r[i]) return false;
    return true;
}

void solve(int testNum) {
    stringstream ss;

    int N;
    cin >> N;
    VT<string> P(N);
    REP(i, N) cin >> P[i];

    bool dame = false;

    deque<char> mid;
    REP(i, N) {
        if (P[i].front() == '*' && P[i].back() == '*') {
            FORE(c, P[i]) if (c != '*') {
                mid.EB(c);
            }
        }
    }

    string front = "";
    REP(i, N) {
        if (P[i].front() != '*' && P[i].back() == '*') {
            bool overAst = false;
            string pre = "";
            FORE(c, P[i]) {
                if (c == '*') {
                    overAst = true;
                    continue;
                }
                if (overAst) {
                    mid.EB(c);
                } else {
                    pre += c;
                }
            }
            if (front.empty()) {
                front = pre;
            } else {
                if (!check(front, pre)) {
                    dame = true;
                    break;
                }
                if (front.length() < pre.length()) {
                    front = pre;
                }
            }
        }
    }

    string back = "";  // TODO: NEED REVERSE !!
    if (!dame) {
        REP(i, N) {
            if (P[i].front() == '*' && P[i].back() != '*') {
                bool overAst = false;
                string pre = "";
                RREP(j, P[i].length()) {
                    const auto c = P[i][j];
                    if (c == '*') {
                        overAst = true;
                        continue;
                    }
                    if (overAst) {
                        mid.emplace_front(c);
                    } else {
                        pre += c;
                    }
                }

                if (back.empty()) {
                    back = pre;
                } else {
                    if (!check(back, pre)) {
                        dame = true;
                        break;
                    }
                    if (back.length() < pre.length()) {
                        back = pre;
                    }
                }
            }
        }
    }

    if (!dame) {
        REP(i, N) {
            if (P[i].front() != '*' && P[i].back() != '*') {
                string f_pre = "", b_pre = "";
                int f_idx = P[i].length(), b_idx = -1;
                REP(j, P[i].length()) {
                    const auto c = P[i][j];
                    if (c == '*') {
                        f_idx = j;
                        break;
                    }
                    f_pre += c;
                }
                RREP(j, P[i].length()) {
                    const auto c = P[i][j];
                    if (c == '*') {
                        b_idx = j;
                        break;
                    }
                    b_pre += c;
                }
                
                FOR(j, f_idx, b_idx) {
                    const auto c = P[i][j];
                    if (c == '*') continue;
                    mid.EB(c);
                }

                if (!check(front, f_pre) || !check(back, b_pre)) {
                    dame = true;
                    break;
                }
                if (front.length() < f_pre.length()) {
                    front = f_pre;
                }
                if (back.length() < b_pre.length()) {
                    back = b_pre;
                }
            }
        }
    }

    if (!dame) {
        REVERSE(back);
        string ans = front;
        FORE(c, mid) ans += c;
        ans += back;
        ss << ans;
    } else {
        ss << "*";
    }

    cout << "Case #" << testNum << ": " << ss.str() << endl;
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
