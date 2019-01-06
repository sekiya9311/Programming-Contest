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

string S;
int K;

int main(void) {
    cin >> S >> K;
    const int L = S.length();
    int c = 0, s = 0;
    FORE(e, S) {
        if (e == '?') c++;
        if (e == '*') s++;
    }
    int mi_len = L - c * 2 - s * 2;
    int ma_len = s == 0 ? L - c : INF;
    if (mi_len <= K && K <= ma_len) {
        string ans = "";
        const int original = L - c - s;
        if (K <= original) {
            int del = original - K;
            REP(i, L) {
                char el = S[i];
                if (i + 1 < L && (S[i + 1] == '?' || S[i + 1] == '*')) {
                    i++;
                    if (del > 0) {
                        del--;
                        continue;
                    }
                }
                ans += el;
            }
        } else {
            int add = K - original;
            REP(i, L) {
                char el = S[i];
                if (i + 1 < L && (S[i + 1] == '?' || S[i + 1] == '*')) {
                    i++;
                    while (add && S[i] == '*') {
                        add--;
                        ans += el;
                    }
                }
                ans += el;
            }
        }
        assert(ans.length() == K);
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
