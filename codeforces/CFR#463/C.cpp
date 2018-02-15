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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 1e6 + 10;
int P[MAX];
int N, A, B;
unordered_set<int> already;

void put(bool ok) {
    if (ok) {
        REP(i, N) printf("%d%c", P[i] + 1, (i + 1 == N ? '\n' : ' '));
    } else {
        puts("-1");
    }
    exit(0);
}

int main(void) {
    cin >> N >> A >> B;
    iota(P, P + N, 0);
    if (min(A, B) == 1) {
        put(true);
    }
    if (min(A, B) > N) {
        put(false);
    }
    if (N % A == 0) {
        REP(i, N / A) {
            REP(j, A - 1) swap(P[i * A + j], P[i * A + j + 1]);
        }
        put(true);
    } else if (N % B == 0) {
        REP(i, N / B) {
            REP(j, B - 1) swap(P[i * B + j], P[i * B + j + 1]);
        }
        put(true);
    } else {
        REP(i, N) {
            if ((i + 1) % A == 0 && (N - (i + 1)) % B == 0) {
                REP(j, (i + 1) / A) REP(k, A - 1) swap(P[j * A + k], P[j * A + k + 1]);
                REP(j, (N - (i + 1)) / B) {
                    int nj = j * B + i + 1;
                    REP(k, B - 1) swap(P[nj + k], P[nj + k + 1]);
                }
                put(true);
            } else if ((i + 1) % B == 0 && (N - (i + 1)) % A == 0) {
                REP(j, (i + 1) / B) REP(k, B - 1) swap(P[j * B + k], P[j * B + k + 1]);
                REP(j, (N - (i + 1)) / A) {
                    int nj = j * A + i + 1;
                    REP(k, A - 1) swap(P[nj + k], P[nj + k + 1]);
                }
                put(true);
            }
        }
        put(false);
    }
}
