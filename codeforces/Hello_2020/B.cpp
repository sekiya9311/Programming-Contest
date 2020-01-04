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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 1e5 + 10;
int N;
VI S[MAX];
int mi[MAX], ma[MAX];
int sum[MAX * 10];
bool exists[MAX];

void naive() {
    int cnt = 0;
    REP(i, N) {
        REP(j, N) {
            bool f = false;
            int mi = INF;
            FORE(e, S[i]) {
                chmin(mi, e);
                if (mi < e) {
                    f = true;
                }
            }
            FORE(e, S[j]) {
                chmin(mi, e);
                if (mi < e) {
                    f = true;
                }
            }
            if(f) {
                cerr << i << " " << j << endl;
            }
            cnt += f;
        }
        DEBUG(cnt)
    }
    DEBUG(cnt)
}

int main(void) {
    scanf("%d", &N);
    int already_cnt = 0;
    REP(i, N) {
        int l;
        scanf("%d", &l);
        S[i].resize(l);
        REP(j, l) {
            scanf("%d", &S[i][j]);
        }
        mi[i] = *min_element(ALL(S[i]));
        ma[i] = *max_element(ALL(S[i]));

        int mi = INF;
        FORE(e, S[i]) {
            chmin(mi, e);
            if (mi < e) {
                exists[i] = true;
                already_cnt++;
            }
        }
    }
//naive();
    REP(i, N) if (!exists[i]) {
        sum[ma[i]]++;
    }
    REP(i, MAX * 10 - 1) {
        sum[i + 1] += sum[i];
    }

    LL ans = 0;
    REP(i, N) {
        if (exists[i]) {
            ans += N;
        } else {
            auto cur = sum[MAX * 10 - 1] - sum[mi[i]] + already_cnt;
            ans += cur;
        }
    }

    cout << ans << endl;
}
