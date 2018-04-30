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

struct Creature {
    LL hp, dmg;
    int idx;
};

const int MAX = 2e5 + 10;
int N, A, B;
LL h[MAX], d[MAX];
Creature C[MAX];

int main(void) {
    scanf("%d%d%d", &N, &A, &B);
    REP(i, N) scanf("%lld%lld", h + i, d + i);
    REP(i, N) {
        C[i].hp = h[i];
        C[i].dmg = d[i];
        C[i].idx = i;
    }
    sort(C, C + N, [](const Creature &a, const Creature &b) {
        return a.hp - a.dmg > b.hp - b.dmg;
    });
    LL not_a = 0;
    REP(i, N) {
        if (i < B && C[i].hp > C[i].dmg) not_a += C[i].hp;
        else not_a += C[i].dmg;
    }
    LL ans = not_a;
    if (A && B) {
        REP(i, N) {
            LL pre = not_a;
            if (i < B) {
                pre += (C[i].hp << A) - max(C[i].dmg, C[i].hp);
            } else {
                const LL add = (C[i].hp << A) - C[i].dmg;
                if (add > 0 && C[B - 1].hp > C[B - 1].dmg) {
                    pre = pre + add - (C[B - 1].hp - C[B - 1].dmg);
                }
            }
            chmax(ans, pre);
        }
    }
    cout << ans << endl;
}
