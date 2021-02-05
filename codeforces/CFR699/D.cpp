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

string next() {
    static char strbuf[(int)1e5 + 10];
    scanf("%s", strbuf);
    return strbuf;
}

void solve2() {
    int N, M;
    scanf("%d%d", &N, &M);
    VT<string> S(N);
    REP(i, N) S[i] = next();

    REP(i, N) REP(j, N) {
            if (S[i][j] == '*') continue;
            if (S[i][j] == S[j][i]) {
                puts("YES");
                REP(k, M + 1) {
                    printf("%d%c", ((k % 2) ? i + 1 : j + 1), (k + 1 == M + 1 ? '\n' : ' '));
                }
                return;
            }
    }
    if (M % 2) {
        REP(i, N) REP(j, N) {
                if (S[i][j] == '*') continue;
                puts("YES");
                REP(k, M + 1) {
                    printf("%d%c", ((k % 2) ? i + 1 : j + 1), (k + 1 == M + 1 ? '\n' : ' '));
                }
                return;
        }
        puts("NO");
        return;
    }

    // M % 2 == 0
    VT<array<VI, 2>> G(N);
    REP(i, N) {
        REP(j, N) {
            if (S[i][j] == '*') continue;

            G[i][S[i][j] == 'a'].EB(j);
            G[j][S[j][i] == 'a'].EB(i);
        }
    }

    int cand_a = -1, cand_b = -1, cand_c = -1;
    REP(i, N) {
        FORE(nxt, G[i][0]) {
            if (!G[nxt][0].empty()) {
                cand_a = i;
                cand_b = nxt;
                cand_c = G[nxt][0][0];
            }
        }
        if (cand_c == -1) {
            FORE(nxt, G[i][1]) {
                if (!G[nxt][1].empty()) {
                    cand_a = i;
                    cand_b = nxt;
                    cand_c = G[nxt][1][0];
                }
            }
        }
        if (cand_c != -1) break;
    }

    if (cand_c == -1) {
        puts("NO");
        return;
    }

    VI l, r;
    l.EB(cand_a);
    r.EB(cand_c);
    while (l.size() + r.size() < M + 1) {
        if (l.size() + r.size() == M) {
            puts("YES");
            RREP(i, l.size()) {
                printf("%d ", l[i] + 1);
            }
            printf("%d ", cand_b + 1);
            REP(i, r.size()) {
                printf("%d%c", r[i] + 1, (i + 1 == r.size() ? '\n' : ' '));
            }
            return;
        }

        if (l.back() == cand_a) {
            l.EB(cand_b);
        } else {
            l.EB(cand_a);
        }
        if (r.back() == cand_c) {
            r.EB(cand_b);
        } else {
            r.EB(cand_c);
        }
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
