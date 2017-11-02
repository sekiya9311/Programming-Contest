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

class UnionFind {
private:
    vector<int> uni;
    int SIZE;
public:

    UnionFind(int size) {
        this->uni.resize(size, -1);
        this->SIZE = size;
    }
     UnionFind() {}
     void resize(int size) {
         this->uni.resize(size, -1);
         this->SIZE = size;
     }

    //xの親を返す
    int find(int x) {
        if (uni[x] < 0) return x;
        return uni[x] = find(uni[x]);
    }

    //xとyが同じグループならばtrue
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    //xとyがそれぞれ属するグループを併合
    //併合処理を行ったならばtrueを返す
    //xとyがもともと同じグループならばfalseを返す
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (uni[x] > uni[y]) swap(x, y);
        uni[x] += uni[y];
        uni[y] = x;
        this->SIZE--;
        return true;
    }

    //グループ数を返す
    int size() {
        return this->SIZE;
    }

    //xが属するグループのノード数を返す
    int size(int x) {
        return -uni[find(x)];
    }
};

const int MAX = 1e5 + 10;
int N;
LL x[MAX], y[MAX];
pair<PLL, int> xy[MAX], yx[MAX];

void gutyoku() {
    UnionFind uf(N);
    VT<pair<LL, PII>> vec;
    REP(i, N) FOR(j, i + 1, N) {
        vec.EB(MP(min(llabs(x[i] - x[j]), llabs(y[i] - y[j])), MP(i, j)));
    }
    SORT(vec);
    LL res = 0;
    FORE(e, vec) {
        cerr << "(" << e.second.first << ", " << e.second.second << ") = " << e.first << endl;
        if (uf.unite(e.second.first, e.second.second)) {
            cerr << e.second.first << " " << e.second.second << endl;
            res += e.first;
        }
    }
    cout << res << endl;
}

void ans() {
    UnionFind uf(N);
    VT<pair<LL, PII>> vec;
    REP(i, N - 1) {
        vec.EB(min(llabs(xy[i].first.first - xy[i + 1].first.first), llabs(xy[i].first.second - xy[i + 1].first.second)), MP(xy[i].second, xy[i + 1].second));
        vec.EB(min(llabs(yx[i].first.first - yx[i + 1].first.first), llabs(yx[i].first.second - yx[i + 1].first.second)), MP(yx[i].second, yx[i + 1].second));
    }
    SORT(vec);
    LL res = 0;
    FORE(e, vec) {
        //cerr << "(" << e.second.first << ", " << e.second.second << ") = " << e.first << endl;
        if (uf.unite(e.second.first, e.second.second)) {
        //    cerr << e.second.first << " " << e.second.second << endl;
            res += e.first;
        }
    }
    cout << res << endl;
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld%lld", x + i, y + i);
        xy[i] = MP(MP(x[i], y[i]), i);
        yx[i] = MP(MP(y[i], x[i]), i);
    }
    sort(xy, xy + N);
    sort(yx, yx + N);
    //gutyoku();
    ans();
}
