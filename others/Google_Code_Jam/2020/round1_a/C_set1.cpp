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

void deb(VVI vev) {
    FORE(v, vev) {
        FORE(e, v) cerr << e << " ";
        cerr<<endl;
    }
}

void solve(int testNum) {
    stringstream ss;

    int R, C;
    cin >> R >> C;
    VVI S(R, VI(C));
    REP(i, R) REP(j, C) cin >> S[i][j];

    assert(R * C <= 111);

    LL ans = 0;
    while (true) {
        REP(i, R) REP(j, C) ans += S[i][j];
//DEBUG(ans)

        auto nxt = S;
        // deb(nxt);
        bool changed = false;
        REP(i, R) REP(j, C) {
            if (S[i][j] == 0) continue;

            int sum = 0, cnt = 0;
            REP(k, 4) {
                int dcnt = 1;
                while (true) {
                    const int dr = i + dx4[k] * dcnt;
                    const int dc = j + dy4[k] * dcnt;
                    dcnt++;
                    if (0 <= dr && dr < R && 0 <= dc && dc < C) {
                        if (S[dr][dc] > 0) {
                            cnt++;
                            sum += S[dr][dc];
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
            if (S[i][j] * cnt < sum) {
                nxt[i][j] = 0;
                changed = true;
            }

        }
        ///deb(nxt);
        if (S == nxt) break;
        S = nxt;
    }

    ss << ans << endl;

    cout << "Case #" << testNum << ": " << ss.str();
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
