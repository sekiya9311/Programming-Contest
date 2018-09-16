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

const int MAX = 1111;
int N;
int a[MAX], b[MAX];
VPII ans;

int main(void) {
    cin >> N;
    REP(i, N - 1) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    set<int> se;
    VI cnt(N - 1);
    REP(i, N - 1) se.emplace(i);
    REP(i, N - 1) {
        if (max(a[i], b[i]) != N - 1) {
            cout << "NO" << endl;
            return 0;
        }
        cnt[min(a[i], b[i])]++;
        se.erase(min(a[i], b[i]));
    }
    REP(i, N - 1) {
        int foo = N - 1;
        if (cnt[i] == 0) continue;
        REP(j, cnt[i] - 1) {
            if (se.empty() || *se.begin() > i) {
                cout << "NO" << endl;
                return 0;
            }
            ans.emplace_back(foo, *se.begin());
            foo = *se.begin();
            se.erase(se.begin());
        }
        ans.emplace_back(foo, i);
    }
    puts("YES");
    FORE(e, ans) printf("%d %d\n", e.first + 1, e.second + 1);
}
