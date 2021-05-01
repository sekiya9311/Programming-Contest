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

long double naive(LL N, LL K, VL P) {
    long double ans = 0;
    FOR(i, 1, K + 1) {
        FOR(j, 1, K + 1) {
            int all = 0, win = 0;
            FOR(c, 1, K + 1) {
                LL ma = LLINF;
                FORE(p, P) chmin(ma, abs(p - c));

                if (abs(i - c) < ma || abs(j - c) < ma) {
                    win++;
                }
                all++;
            }
            if (chmax(ans, (long double)win / all)) {
                cerr << "(i, j, ans): " << "(" << i << ", " << j << ", " << ans << ")" << "\n";
            }
        }
    }
    return ans;
}

LL calc(const VL &P, LL cur) {
    LL res = LLINF;
    FORE(p, P) {
        chmin(res, abs<LL>(p - cur));
    }
    return res;
}

PLL calc(const LL &K, const VL &P, const LL cur) {
    PLL res;
    if (abs(1 - cur) < calc(P, 1)) {
        res.first = 1;
    } else {
        LL ng = 1, ok = cur;
        while (abs(ok - ng) > 1) {
            const auto mid = (ok + ng) / 2;
            if (abs(mid - cur) < calc(P, mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        res.first = ok;
    }

    if (abs(K - cur) < calc(P, K)) {
        res.second = K;
    } else {
        LL ng = K, ok = cur;
        while (abs(ok - ng) > 1) {
            const auto mid = (ok + ng) / 2;
            if (abs(mid - cur) < calc(P, mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        res.second = ok;
    }
    return res;
}

long double fast(LL N, LL K, VL P) {
    long double ans = 0;

    set<LL> cand;
    FORE(p, P) {
        if (count_if(ALL(P), [&](auto pp) { return pp == p + 1; }) == 0 && 1 <= p + 1 && p + 1 <= K) {
            cand.emplace(p + 1);
        }
        if (count_if(ALL(P), [&](auto pp) { return pp == p - 1; }) == 0 && 1 <= p - 1 && p - 1 <= K) {
            cand.emplace(p - 1);
        }
    }

    FORE(cur1, cand) {
        FORE(cur2, cand) {
            LL all = K, win = 0;

            const auto win1 = calc(K, P, cur1);
            const auto win2 = calc(K, P, cur2);
            PLL win12 = {-1LL, -1LL};

            if (win1.first <= win2.first && win2.second <= win1.second) {
                win12 = win1;
            } else if (win2.first <= win1.first && win1.second <= win2.second) {
                win12 = win2;
            } else if (win1.first <= win2.first && win2.first <= win1.second && win1.second <= win2.second) {
                win12 = {win1.first, win2.second};
            } else if (win2.first <= win1.first && win1.first <= win2.second && win2.second <= win1.second) {
                win12 = {win2.first, win1.second};
            }

            if (win12.first != -1) {
                win = win12.second - win12.first + 1;
            } else {
                win = (win1.second - win1.first + 1) + (win2.second - win2.first + 1);
            }

            chmax(ans, (long double)win / all);
        }
    }
    return ans;
}

void solve(stringstream &out) {
    LL N, K;
    cin >> N >> K;
    VL P(N);
    REP(i, N) cin >> P[i];
    SORT(P);

    long double ans = fast(N, K, P);

    out << fixed << setprecision(10) << ans << endl;
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
