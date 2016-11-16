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

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

#define X first
#define Y second
using soldier = pair<string, PII>;
int n;
PII king;
vector<soldier> enemy;

//if checked true else false
bool Bishop(PII me, PII target) {
    if (abs(me.X - target.X) == abs(me.Y - target.Y)) return true;
    return false;
}
bool Rook(PII me, PII target) {
    if (me.X == target.X) return true;
    if (me.Y == target.Y) return true;
    return false;
}
bool Queen(PII me, PII target) {
    return Bishop(me, target) || Rook(me, target);
}

//
int place(PII me, PII target) {
    if (me.X == target.X) {
        if (me.Y > target.Y) return 6;
        else return 1;
    }
    if (me.Y == target.Y) {
        if (me.X > target.X) return 4;
        else return 3;
    }
    if (me.X < king.X && me.Y < king.Y) return 0;
    if (me.X < king.X && me.Y > king.Y) return 5;
    if (me.X > king.X && me.Y < king.Y) return 2;
    return 7;
}

//チェックしてればtrue
bool func(int dim, soldier me) {
    switch (dim) {
    case 0:
        if (me.first == "B" || me.first == "Q") return true;
        break;
    case 2:
        if (me.first == "B" || me.first == "Q") return true;
        break;
    case 5:
        if (me.first == "B" || me.first == "Q") return true;
        break;
    case 7:
        if (me.first == "B" || me.first == "Q") return true;
        break;
    default:
        if (me.first == "R" || me.first == "Q") return true;
    }
    return false;
}

/*0     X
   0 1 2
   3 K 4
   5 6 7
 Y */

int main(void) {
    scanf("%d", &n);
    scanf("%d%d", &king.X, &king.Y);
    enemy.resize(n);
    for_each(ALL(enemy), [](soldier &e) {
        char c[2]; int x, y;
        scanf("%s%d%d", c, &x, &y);
        e = MP(c, MP(x, y));
    });
    soldier def = MP("", MP(INF + 1, INF + 1));
    vector<soldier> match(8, def);
    VL dist(8);
    REP(i, n) {
        string c = enemy[i].first;
        if (!Queen(enemy[i].second, king)) continue;
        //DEBUG(i)
        int id = place(enemy[i].second, king);
        if (match[id] == def) {
            match[id] = enemy[i];
            dist[id] = pow(enemy[i].second.X - king.X, 2) + pow(enemy[i].second.Y - king.Y, 2);
        } else {
            LL dis = pow(enemy[i].second.X - king.X, 2) + pow(enemy[i].second.Y - king.Y, 2);
            if (dis < dist[id]) {
                match[id] = enemy[i];
                dist[id] = dis;
            }
        }
    }
    REP(i, 8) {
        if (match[i] == def) continue;
        //cout << i << " " << match[i].first << " " << match[i].second.X << " " << match[i].second.Y << endl;
        if (func(i, match[i])) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
