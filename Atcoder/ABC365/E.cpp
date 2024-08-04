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
#define GREATER(T) T, VT<T>, greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 2e5 + 10;
int N;
LL A[MAX];

void naive() {
    LL ans = 0;
    vector<int> cnt(MAX);
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            LL cur = 0;
            for (int k = i; k <= j; k++) {
                cur ^= A[k];
                cnt[k]++;
            }
            ans += cur;
        }
    }
    cout << ans << "\n";
}

LL calc_cnt(LL k/*zero base*/) {
    return N * (k + 1) - 1;
}

void solve() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0;

    for (int bit = 0; bit < 64; bit++) {
        vector<LL> B(N), C(N + 1);
        for (int i = 0; i < N; i++) {
            B[i] = (A[i] >> bit) & 1;
        }
        for (int i = 0; i < N; i++) {
            C[i + 1] = C[i] ^ B[i];
        }

        LL zero = 0, one = 0;
        for (int i = 0; i < N + 1; i++) {
            (C[i] ? one : zero)++;
        }
        ans += (1LL << bit) * (one * zero - accumulate(ALL(B), 0LL));
    }

    cout << ans << "\n";
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
