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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

void simu(int N, VPII ans) {
    VI p(N);
    iota(ALL(p), 0);
    REP(_, N) {

        VPII battle;
        FORE(e, ans) {
            int l;
            REP(j, N) if (e.first == p[j]) l = j;
            int r;
            REP(j, N) if (e.second == p[j]) r = j;
            cout << "(" << l + 1 << ", " << r + 1 << "), ";
        }
        cout << endl;

        REP(i, N) p[i] = (p[i] + 1) % N;
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    VPII ans;
    {
        int r = M % 2 == 0 ? M : M - 1;
        REP(i, M / 2) {
            ans.EB(i, r--);
        }
    }
    {
        int l = (M % 2 == 0 ? M : M - 1) + 1;
        int r = l + (M % 2 == 0 ? M - 1 : M);
        REP(i, (M + 1) / 2) {
            ans.EB(l + i, r--);
        }
    }


    FORE(e, ans) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }

    // simu(N, ans);
}
