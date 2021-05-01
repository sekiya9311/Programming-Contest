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

struct member {
    int A, B, C, D, E;

    member calc(member m) {
        chmax(m.A, A);
        chmax(m.B, B);
        chmax(m.C, C);
        chmax(m.D, D);
        chmax(m.E, E);
        return m;
    }

    int calc_min() {
        return min({A, B, C, D, E});
    }
};

void solve() {
    int N;
    cin >> N;
    VT<member> M(N);
    VT<pair<member, int>> av, bv, cv, dv, ev;
    REP(i, N) {
        cin >> M[i].A >> M[i].B >> M[i].C >> M[i].D >> M[i].E;
        av.EB(MP(M[i], i));
        bv.EB(MP(M[i], i));
        cv.EB(MP(M[i], i));
        dv.EB(MP(M[i], i));
        ev.EB(MP(M[i], i));
    }

    sort(ALL(av), [](const auto &l, const auto &r) {
        return l.first.A > r.first.A;
    });
    sort(ALL(bv), [](const auto &l, const auto &r) {
        return l.first.B > r.first.B;
    });
    sort(ALL(cv), [](const auto &l, const auto &r) {
        return l.first.C > r.first.C;
    });
    sort(ALL(dv), [](const auto &l, const auto &r) {
        return l.first.D > r.first.D;
    });
    sort(ALL(ev), [](const auto &l, const auto &r) {
        return l.first.E > r.first.E;
    });


    int ans = 0;
    REP(i, N) {
        REP(j, N) {
            member cur;
            cur.A = max(M[i].A, M[j].A);
            cur.B = max(M[i].B, M[j].B);
            cur.C = max(M[i].C, M[j].C);
            cur.D = max(M[i].D, M[j].D);
            cur.E = max(M[i].E, M[j].E);

            member cur_a = cur;
            {
                int idx = 0;
                while (av[idx].second == i || av[idx].second == j) {
                    idx++;
                }
                cur_a = av[idx].first.calc(cur);
            }

            member cur_b = cur;
            {
                int idx = 0;
                while (bv[idx].second == i || bv[idx].second == j) {
                    idx++;
                }
                cur_b = bv[idx].first.calc(cur);
            }

            member cur_c = cur;
            {
                int idx = 0;
                while (cv[idx].second == i || cv[idx].second == j) {
                    idx++;
                }
                cur_c = cv[idx].first.calc(cur);
            }

            member cur_d = cur;
            {
                int idx = 0;
                while (dv[idx].second == i || dv[idx].second == j) {
                    idx++;
                }
                cur_d = dv[idx].first.calc(cur);
            }

            member cur_e = cur;
            {
                int idx = 0;
                while (ev[idx].second == i || ev[idx].second == j) {
                    idx++;
                }
                cur_e = ev[idx].first.calc(cur);
            }

            chmax(ans, max({cur_a.calc_min(), cur_b.calc_min(), cur_c.calc_min(), cur_d.calc_min(), cur_e.calc_min(), }));
        }
    }

    cout << ans << endl;
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
