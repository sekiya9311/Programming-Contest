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

const int MAX = 2e5 + 10;
int N;
LL A[MAX];

map<LL, int> cnt;

int main(void) {
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    sort(A, A + N);
    reverse(A, A + N);
    int ans = 0;
    REP(i, N) {
        if (cnt.count(A[i]) == 0) continue;
        int now_cnt = cnt[A[i]];
        if (now_cnt > 0) {
            RREP(j, 31) {
                LL foo = (1 << j) - A[i];
                if (foo <= A[i]) break;
                if ((A[i] == foo && now_cnt > 1) || (A[i] != foo && cnt.count(foo) && cnt[foo] > 0)) {
                    if (now_cnt == 1) cnt.erase(A[i]);
                    else cnt[A[i]]--;
                    if (cnt[foo] == 1) cnt.erase(foo);
                    else cnt[foo]--;
                    ans++;
                    break;
                }
            }
        }
    }
    FORE(e, cnt) {
        while (__builtin_popcountll(e.first + e.first) == 1 && e.second > 1) {
            ans++;
            e.second -= 2;
        }
    }
    cout << ans << endl;
}
