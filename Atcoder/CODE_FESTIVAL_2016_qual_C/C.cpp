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
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back

const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e18;
#define int LL
VI A, T;
VI M;

signed main(void) {
    int N;
    cin >> N;
    A.resize(N);
    T.resize(N);
    M.resize(N);
    REP(i, N) scanf("%d", &T[i]);
    REP(i, N) scanf("%d", &A[i]);
    int aa = LLINF,tt = 0;
    REP(i, N) {
        if (aa < A[i] || tt > T[i]) {
            cout << 0 << endl;
            return 0;
        } else {
            aa = A[i]; tt = T[i];
        }
    }
    int ans = 1;
    REP(i, N) {
        if (i == 0) {
            if (T[0] > A[0]) {
                cout << 0 << endl;
                return 0;
            }
            M[i] = 1;
        } else if (i == N - 1) {
            if (A.back() > T.back()) {
                cout << 0 << endl;
                return 0;
            }
            M[i] = 1;
        } else {
            if (T[i] == T[i-1]&&A[i] == A[i+1]) {
                M[i] = min(T[i], A[i]);
            } else if (T[i] == T[i-1]) {
                if (A[i] > T[i]) {
                    cout << 0 << endl;
                    return 0;
                }
                M[i] = 1;
            } else if (A[i] == A[i+1]) {
                if (T[i] > A[i]) {
                    cout << 0 << endl;
                }
                M[i] = 1;
            } else {
                if (T[i] != A[i]) {
                    cout << 0 << endl;
                    return 0;
                } else {
                    M[i] = 1;
                }
            }
        }
    }
    if (T.back() != A[0]) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, N) {
        ans = (ans * M[i]) % MOD;
    }
    cout << ans << endl;
}
