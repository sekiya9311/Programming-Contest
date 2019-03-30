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

const int MAX = 2e5 + 10;
int N, Q;
string S;
char t[MAX], d[MAX];

int main(void) {
    cin >> N >> Q;
    cin >> S;
    REP(i, Q) {
        string tmp;
        cin >> tmp;
        t[i] = tmp[0];
        cin >> tmp;
        d[i] = tmp[0];
    }

    int l;
    {
        int ok = -1, ng = N;
        while (ng - ok > 1) {
            const int mid = (ng + ok) / 2;
            bool fall = false;
            int cur = mid;
            REP(i, Q) {
                if (t[i] == S[cur]) {
                    if (d[i] == 'L') cur--;
                    else cur++;
                    if (cur == -1) {
                        fall = true;
                        break;
                    } else if (cur == N) {
                        break;
                    }
                }
            }
            if (fall) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        l = ok;
    }

    int r;
    {
        int ok = N, ng = -1;
        while (ok - ng > 1) {
            const int mid = (ok + ng) / 2;
            bool fall = false;
            int cur = mid;
            REP(i, Q) {
                if (t[i] == S[cur]) {
                    if (d[i] == 'L') cur--;
                    else cur++;
                    if (cur == N) {
                        fall = true;
                        break;
                    } else if (cur == -1) {
                        break;
                    }
                }
            }
            if (fall) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        r = ok;
    }
    cout << N - (l + 1) - (N - r) << endl;
}
