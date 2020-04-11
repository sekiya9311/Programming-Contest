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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int dx4[] = {0, 0, -1, 1};
const int dy4[] = {1, -1, 0, 0};

void solve(stringstream &out) {
    int R, C;
    scanf("%d%d", &R, &C);

    LL sum = 0;
    VPII cand;
    VT<VT<array<PII, 4>>> dirs(R, VT<array<PII, 4>>(C));
    VVI memo(R, VI(C, -1));

    VVI P(R, VI(C));
    REP(i, R) REP(j, C) {
        scanf("%d", &P[i][j]);

        sum += P[i][j];
        cand.EB(i, j);
        REP(k, 4) {
            const int ii = i + dx4[k];
            const int jj = j + dy4[k];
            dirs[i][j][k] = { ii, jj };
        }
    }

    const auto in_range = [R, C](const int r, const int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    };
    const auto in_range_p = [in_range](const PII &p) {
        return in_range(p.first, p.second);
    };

    LL ans = sum;
    for (int dance_cnt = 0; ; dance_cnt++) {
        VPII rem;
        FORE(p, cand) {
            const int r = p.first;
            const int c = p.second;
            if (P[r][c] == 0) continue;

            int neighbor_cnt = 0, neighbor_sum = 0;
            REP(d, 4) {
                int dcnt = 0;
                while (true) {
                    const int cur_r = dirs[r][c][d].first + dx4[d] * dcnt;
                    const int cur_c = dirs[r][c][d].second + dy4[d] * dcnt;
                    dcnt++;
                    if (!in_range(cur_r, cur_c)) {
                        dirs[r][c][d] = { cur_r, cur_c };
                        break;
                    }
                    if (P[cur_r][cur_c] == 0) continue;

                    neighbor_cnt++;
                    neighbor_sum += P[cur_r][cur_c];
                    dirs[r][c][d] = { cur_r, cur_c };
                    break;
                }
            }

            if (P[r][c] * neighbor_cnt < neighbor_sum) {
                rem.EB(r, c);
            }
        }

        if (rem.empty()) break;

        cand.clear();
        FORE(e, rem) {
            sum -= P[e.first][e.second];
            P[e.first][e.second] = 0;

            REP(d, 4) if (in_range_p(dirs[e.first][e.second][d])) {
                const auto nxt_r = dirs[e.first][e.second][d].first;
                const auto nxt_c = dirs[e.first][e.second][d].second;
                if (memo[nxt_r][nxt_c] == dance_cnt) {
                    continue;
                }
                cand.EB(nxt_r, nxt_c);
                memo[nxt_r][nxt_c] = dance_cnt;
            }
        }
        ans += sum;
    }

    out << ans << '\n';
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }

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
