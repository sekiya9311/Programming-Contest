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

const int MAX = 1e5 + 10;
int N;
int event[MAX * 2];

bool check(const VI &ans) {
    priority_queue<int, VI, greater<>> pq;
    int ptr = 0;
    REP(i, N * 2) {
        if (event[i] == -1) {
            pq.emplace(ans[ptr++]);
        } else {
            if (pq.top() != event[i]) return false;
            pq.pop();
        }
    }
    return true;
}

void solve() {
    scanf("%d", &N);
    REP(i, N * 2) {
        char str[10];
        scanf("%s", str);

        if (str[0] == '-') {
            scanf("%d", &event[i]);
            event[i]--;
        } else {
            event[i] = -1;
        }
    }

    {
        int cnt = 0;
        bool valid = true;
        int pre = -1;
        REP(i, N * 2) {
            if (event[i] == -1) {
                cnt++;
                pre = -1;
            } else {
                if (pre > event[i]) {
                    valid = false;
                    break;;
                }
                pre = event[i];
                cnt--;
            }
            if (cnt < 0) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            puts("NO");
            return;
        }
    }

    VI ans;
    priority_queue<int, VI, greater<>> pq;
    RREP(i, N * 2) {
        if (event[i] == -1) {
            ans.EB(pq.top());
            pq.pop();
        } else {
            pq.emplace(event[i]);
        }
    }

    REVERSE(ans);

    if (!check(ans)) {
        puts("NO");
        return;
    }

    puts("YES");
    REP(i, N) {
        printf("%d%c", ans[i] + 1, (i + 1 == N ? '\n' : ' '));
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
