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
int N, a[MAX];

int main(void) {
    scanf("%d", &N);
    int ma = 0, mi = INF;
    REP(i, N) {
        scanf("%d", a + i);
        chmin(mi, a[i]);
        chmax(ma, a[i]);
    }
    if (ma - mi >= 2) {
        cout << "No" << endl;
        return 0;
    }
    if (ma == mi) {
        if (ma == N - 1 || ma == 1) {
            cout << "Yes" << endl;
            return 0;
        }
        if (N / 2 < ma) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        int cnt[2];
        REP(i, 2) cnt[i] = 0;
        REP(i, N) {
            cnt[a[i] == mi]++;
        }
        if (mi == 1 && cnt[1] == 1) {
            cout << "Yes" << endl;
            return 0;
        }
        if (cnt[1] <= ma - 1) {
            if ((N - cnt[1]) / 2 < ma - cnt[1]) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}
