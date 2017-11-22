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

const int MAX = 100010;
int N;
LL C;
LL L[MAX];
map<LL, int> mp, already;

int main(void) {
    scanf("%d%lld", &N, &C);
    REP(i, N) {
        scanf("%lld", L + i);
        mp[L[i]]++;
    }
    sort(L, L + N);
    reverse(L, L + N);
    int cnt = 0;
    REP(i, N) {
        if (mp.count(L[i]) == 0) continue;
        mp[L[i]]--;
        if (mp[L[i]] == 0) mp.erase(L[i]);
        LL ok = C - L[i];
        if (ok > 0) {
            auto it = mp.lower_bound(ok);
            if (it != mp.begin()) it--;
            auto it2 = it;
            REP(_, 5) if (it2 != mp.begin()) it2--;
            LL buf = -1;
            REP(_, 10) {
                if (it2 != mp.end() && it2->second > 0 && it2->first + L[i] + 1 <= C) {
                    buf = it2->first;
                } else if (it2 == mp.end()) break;
                it2++;
            }
            if (buf != -1) {
                mp[buf]--;
                if (mp[buf] == 0) mp.erase(buf);
            }
        }
        cnt++;
    }
    cout << cnt << endl;
}