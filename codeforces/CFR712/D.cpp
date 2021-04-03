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

const int dx4[] = {0, 0, -1, 1};
const int dy4[] = {1, -1, 0, 0};

PII next(int N, PII p) {
    int tmp = p.first * N + p.second;
    if (N % 2 == 1 || p.second + 2 < N) {
        tmp += 2;

    } else {
        if (p.second % 2 == 0) {
            tmp += 3;
        } else {
            tmp += 1;
        }
    }
    return {tmp / N, tmp % N};
}

int ar[111][111];
void solve() {
    int N;
    cin >> N;

    const int base = 1;
    const int sub = 2;
    const int amari = 3;
    int b_cnt = 0, s_cnt = 0;
    PII b = {0, 0}, s = {0, 1};
    REP(i, N * N) {
        int dame;
        cin >> dame;
        int cur;
        PII p;
        if (dame != base) {
            if (b_cnt == (N * N + 1) / 2) {
                cur = dame == sub ? amari : sub;
                // sub を塗る
                p = s;
                s = next(N, s);
                s_cnt++;
            } else {
                cur = base;
                // base を塗る
                p = b;
                b = next(N, b);
                b_cnt++;
            }
        } else {
            // dame == base
            if (s_cnt == (N * N) / 2) {
                cur = amari;
                // base を塗る
                p = b;
                b = next(N, b);
                b_cnt++;
            } else {
                cur = sub;
                // sub を塗る
                p = s;
                s = next(N, s);
                s_cnt++;
            }
        }

        cout << cur << " " << p.first + 1 << " " << p.second + 1 << endl;
        cout.flush();
        ar[p.first][p.second] = cur;
    }

    {
        REP(i, N) REP(j, N) {
            if (ar[i][j] < 1 || 3 < ar[i][j]) {
                assert(false);
            }

            REP(d, 4) {
                const auto di = i + dx4[d];
                const auto dj = j + dy4[d];
                if (0 <= di && di < N && 0 <= dj && dj < N) {
                    if (ar[i][j] == ar[di][dj]) {
                        assert(false);
                    }
                }
            }
        }
    }
}

int main(void) {
//#ifndef ONLINE_JUDGE
//    const auto in_stream = freopen("../in.txt", "r", stdin);
//    if (in_stream == nullptr) {
//        cerr << "ERROR!" << endl;
//        return 1;
//    }
//#endif

    solve();

//#ifndef ONLINE_JUDGE
//    fclose(in_stream);
//#endif
}
