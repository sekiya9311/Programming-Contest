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

void solve2() {
    int N, M;
    scanf("%d%d", &N, &M);
    VI a(N), b(N), c(M), copy_a(N);
    REP(i, N) {
        cin >> a[i];
        copy_a[i] = a[i];
    }
    REP(i, N) {
        cin >> b[i];
    }
    REP(i, M) {
        cin >> c[i];
    }
    const auto c_back = c.back();
    {
        bool f = false;
        REP(i, N) {
            if (b[i] == c_back) {
                f = true;
                break;
            }
        }
        if (!f) {
            puts("NO");
            return;
        }
    }

    unordered_map<int, VI> need;
    unordered_map<int, VI> ok;
    REP(i, N) {
        if (a[i] == b[i]) {
            ok[a[i]].EB(i);
        } else {
            need[b[i]].EB(i);
        }
    }

    VI ans(M);
    REP(i, M) {
        if (need.count(c[i])) {
            const auto cur = need[c[i]].back();

            need[c[i]].pop_back();
            if (need[c[i]].empty()) {
                need.erase(c[i]);
            }

            ok[c[i]].EB(cur);

            copy_a[cur] = c[i];

            ans[i] = cur;

            continue;
        }

        if (!need.empty()) {
            const auto cur = begin(need)->second[0];
            copy_a[cur] = c[i];
            ans[i] = cur;
            continue;
        }

        // need.empty() == true => すでに完成している!?
        {
            assert(ok.count(c_back));
            const auto cur = ok[c_back][0];
            copy_a[cur] = c[i];
            ans[i] = cur;
        }
    }

    if (!need.empty()) {
        puts("NO");
        return;
    }
    REP(i, N) {
        if (copy_a[i] != b[i]) {
            puts("NO");
            return;
        }
    }

    puts("YES");
    REP(i, M) {
        printf("%d%c", ans[i] + 1, (i + 1 == M ? '\n' : ' '));
    }
}

void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve2();
    }
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
