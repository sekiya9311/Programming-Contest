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

class AlphabetOrderDiv2 {
public:
    const string yes = "Possible";
    const string no = "Impossible";
    set<string> already;
    string isOrdered(vector <string> words) {
        const int L = words.size();
        set<char> mae[26], ushiro[26];
        REP(i, L) {
            if (FIND(already, words[i])) continue;
            already.insert(words[i]);
            set<char> moumita;
            REP(j, words[i].length()) {
                if (FIND(moumita, words[i][j])) {
                    if (words[i][j - 1] != words[i][j]) return no;
                } else {
                    moumita.insert(words[i][j]);
                }
            }
            REP(j, words[i].length()) {
                REP(k, j) {
                    if (words[i][j] != words[i][k]) {
                        mae[words[i][j] - 'a'].insert(words[i][k]);
                    }
                }
                FOR(k, j + 1, words[i].length()) {
                    if (words[i][j] != words[i][k]) {
                        ushiro[words[i][j] - 'a'].insert(words[i][k]);
                    }
                }
            }
            REP(j, words[i].length()) {
                REP(k, j) {//mae no ji
                    if (FIND(ushiro[words[i][j] - 'a'], words[i][k])) return no;
                }
                FOR(k, j + 1, words[i].length()) {//ushiro no ji
                    if (FIND(mae[words[i][j] - 'a'], words[i][k])) return no;
                }
            }
            REP(i, 26) {
                set<char> newset;
                FORE(el, mae[i]) {
                    FORE(e, mae[el - 'a']) newset.insert(e);
                }
                mae[i].insert(ALL(newset));
                newset.clear();
                FORE(el, ushiro[i]) {
                    FORE(e, ushiro[el - 'a']) newset.insert(e);
                }
                ushiro[i].insert(ALL(newset));
            }
            REP(i, 26) {
                FORE(e, mae[i]) if (FIND(ushiro[i], e)) return no;
            }
        }
        return yes;
    }
};

int main(void) {
    AlphabetOrderDiv2 c;
    cout << c.isOrdered(VT<string>{""}) << endl;
}
