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

LL fact(LL v) {
    if (v == 0) return 1;
    else return v * fact(v - 1);
}

LL N;
string S;
int cnt[10];
bool exist[10];
set<LL> se;

int main(void) {
    cin >> N;
    S = to_string(N);
    FORE(e, S) {
        cnt[e - '0']++;
        exist[e - '0'] = true;
    }
    int ma = S.length();
    int mi = 0;
    {
        REP(i, 10) mi += (cnt[i] != 0);
    }
    LL ans = 0;
    REP(i, (1 << ma)) {
        if (__builtin_popcount(i) < mi) {
            continue;
        }
        memset(cnt, 0, sizeof(cnt));
        int zero = 0;
        VI v;
        REP(j, ma) {
            if (i & (1 << j)) {
                v.EB(S[j] - '0');
                cnt[S[j] - '0']++;
            }
        }
        {
            bool c = true;
            REP(j, 10) {
                if (exist[j] && cnt[j] == 0) {
                    c = false;
                }
            }
            if (!c) continue;
        }
        RSORT(v);
        {
            LL foo = 0;
            FORE(e, v) foo = foo * 10 + e;
            if (se.count(foo)) {
                continue;
            }
            se.emplace(foo);
        }
        FOR(j, 1, 10) {
            LL pre = 1;
            if (cnt[j]) {
                cnt[j]--;
                LL foo = 0;
                REP(k, 10) {
                    foo += cnt[k];
                    pre *= fact(cnt[k]);
                }
                ans += fact(foo) / pre;
                cnt[j]++;
            }
        }
    }
    cout << ans << endl;
}
