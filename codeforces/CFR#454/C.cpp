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
string beh[MAX], word[MAX];
int n;
set<char> key, notKey;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        cin >> beh[i] >> word[i];
    }
    // REP(i, 26) {
    //     key.emplace((char)('a' + i));
    // }
    int ans = 0;
    VT<string> atode;
    REP(i, n) {
        //cerr << "notKey = ";FORE(e, notKey) cerr << e << " ";cerr << endl;
        //cerr << "key = ";FORE(e, key) cerr << e << " ";cerr << endl;cerr << endl;
        if (key.size() == 1 || notKey.size() == 25) {
            // kakutei
            if (beh[i] == "!") {
                ans++;
            } else if (beh[i] == "?") {
                ans += (i + 1 != n);
            }
        } else {
            if (beh[i] == "!") {
                // 現在の言葉の中にダメ文字あり
                if (key.empty()) {
                    // とりあえずダメじゃない文字確定じゃないやつはダメ文字候補に全部突っ込む
                    FORE(e, word[i]) {
                        if (notKey.count(e) == 0) {
                            key.emplace(e);
                        }
                    }
                } else {
                    // ダメ文字候補がすでにある
                    FORE(e, word[i]) {
                        if (key.count(e) == 0) {
                            notKey.emplace(e);
                        }
                    }
                    string buf = "";
                    FORE(e, key) {
                        bool find = false;
                        FORE(e1, word[i]) {
                            find |= e1 == e;
                        }
                        if (!find) {
                            buf += e;
                        }
                    }
                    FORE(e, buf) {
                        key.erase(e);
                        notKey.emplace(e);
                    }
                }
            } else if (beh[i] == ".") {
                FORE(e, word[i]) {
                    notKey.emplace(e);
                    key.erase(e);
                }
            } else {
                key.erase(word[i][0]);
                notKey.emplace(word[i][0]);
            }
        }
        FORE(e, notKey) {
            key.erase(e);
        }
    }
    cout << ans << endl;
}
