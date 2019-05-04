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

int dame(char val) {
    // R: 0, P: 1, S: 2
    if (val == 'R') return 2;
    else if (val == 'P') return 0;
    else return 1;
}

char conv(int val) {
    if (val == 0) return 'R';
    else if (val == 1) return 'P';
    else return 'S';
}

// win: 1, lose: 0, draw: -1
int win(char me, char target) {
    if (me == target) return -1;
    if (me == 'R' && target == 'S') return 1;
    if (me == 'P' && target == 'R') return 1;
    if (me == 'S' && target == 'P') return 1;
    return 0;
}

void solve(int testNum) {
    stringstream ss;
    int N;
    cin >> N;
    VT<string> C(N);
    REP(i, N) {
        cin >> C[i];
    }

    bool exists = false;
    string ans = "";
    VT<bool> already(N);
    int already_cnt = 0;
    REP(i, 500) {
        bool ok[3];
        REP(j, 3) ok[j] = true;
        REP(j, N) {
            if (already[j]) {
                continue;
            }
            const auto str = C[j];
            const auto val = str[i % str.length()];
            
            ok[dame(val)] = false;
        }

        set<int> cnt;
        REP(j, 3) if(ok[j]) cnt.emplace(j);

        if (cnt.size() == 1) {
            ans += conv(*cnt.begin());
        } else if (cnt.size() == 2) {
            int one = *cnt.begin();
            int two = *next(cnt.begin());
            if (win(conv(one), conv(two)) == 1) {
                ans += conv(one);
            } else {
                ans += conv(two);
            }
        } else {
            ans = "";
            break;
        }
        char cur = ans.back();
        REP(j, N) {
            if (already[j]) {
                continue;
            }
            const auto str = C[j];
            const auto val = str[i % str.length()];
            const auto res = win(cur, val);
            if (res == 1) {
                already[j] = true;
                already_cnt++;

            }
            assert(res != 0);
        }
        if (already_cnt == N) {
            ss << ans << '\n';
            exists = true;
            break;
        }
    }
    if (!exists) {
        ss << "IMPOSSIBLE" << '\n';
    }
    cout << "Case #" << testNum << ": " << ss.str();
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
