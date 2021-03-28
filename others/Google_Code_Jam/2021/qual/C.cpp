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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
const int cout = 0;

int calc_cost(VI a) {
    const int N = a.size();
    int cost = 0;
    REP(i, N - 1) {
        int mi_idx = i;
        FOR(j, i, N) {
            if (a[j] < a[mi_idx]) {
                mi_idx = j;
            }
        }

        reverse(begin(a) + i, begin(a) + mi_idx + 1);
        cost += mi_idx + 1 - i;
    }
    return cost;
}

const string IMPOSSIBLE = "IMPOSSIBLE";
void solve(stringstream &out) {
    int N, C;
    scanf("%d%d", &N, &C);
    if (N * (N + 1) / 2 - 1 < C || C < N - 1) {
        out << IMPOSSIBLE << "\n";
        return;
    }
    const int tmp_c = C;

    VI v(N, 0);
    iota(ALL(v), 1);
    C -= N - 1;
    VI cand;
    for (int i = N - 1; i >= 1; i--) {
        if (C >= i) {
            cand.EB(i);
            C -= i;
        }
    }
    REVERSE(cand);

    FORE(e, cand) {
        reverse(begin(v) + N - e - 1, end(v));
    }

    const auto cost = calc_cost(v);
    if (cost != tmp_c) {
        cerr << "cost: " << cost << endl;
        assert(false);
    }
    REP(i, N) {
        out << v[i] << (i + 1 == N ? '\n' : ' ');
    }
}

int main(void) {
    int problem_count;
    scanf("%d", &problem_count);
    //string s;getline(cin, s);
    for (int test_no = 1; test_no <= problem_count; test_no++) {
        stringstream out;
        solve(out);
        printf("Case #%d: %s", test_no, out.str().c_str());
        cerr << "Case #" << test_no << ": solved" << endl;
    }
}
