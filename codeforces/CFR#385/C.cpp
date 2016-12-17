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

/*** UnionFindクラス(集合の要素列挙できるよ) ***/
class UnionFindSetList {
private:
    //uni[i]<0ならばiが親，そうでなければfind(uni[i])が親
    vector<int> uni;
    //グループ数
    int SIZE;
    //各要素の集合の最後のidx
    vector<int> last;
public:
    //for (int now = uf.root(x); now != -1; now = uf.next[now])
    //の形で集合の要素辿れるやつ
    vector<int> next;

    UnionFind(int size) {
        //初期状態では全ノード-1に設定し，よってすべてが親
        resize(size);
    }
     UnionFind() {}
     void resize(int size) {
         this->uni.resize(size, -1);
         this->next.resize(size, -1);
         this->last.resize(size);
         iota(ALL(this->last), 0);
         this->SIZE = size;
     }

    //xの親を返す
    int find(int x) {
        //uni[x]<0なのでxは親
        if (uni[x] < 0) return x;
        //uni[x]に親ノードを入れることで連続での探索時間の短縮
        return uni[x] = find(uni[x]);
    }

    //xとyが同じグループならばtrue
    bool same(int x, int y) {
        //xとyの親が同じならば同じグループに属するといえる
        return find(x) == find(y);
    }

    //xとyがそれぞれ属するグループを併合
    //併合処理を行ったならばtrueを返す
    //xとyがもともと同じグループならばfalseを返す
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        //木の深さが小さいノードから大きいノードへ辺をはる
        if (uni[x] > uni[y]) swap(x, y);
        //yのグループをxに足す
        uni[x] += uni[y];
        //yの親をxとする
        uni[y] = x;
        //集合登録
        next[last[x]] = y;
        last[x] = last[y];
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

int N, M, K;
VI c;
VI rootcnt;
VI bossgrouprootcnt;
VI bossgroupsize;
UnionFindSetList uf;

void out(const VI &v) {
    FORE(e, v) cout << e << " ";cout << endl;
}

int main(void) {
    scanf("%d%d%d", &N, &M, &K);
    c.resize(K);
    REP(i, K) {
        scanf("%d", &c[i]);
        c[i]--;
    }
    rootcnt.resize(N, 0);
    uf.resize(N);
    REP(i, M) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        rootcnt[u]++;
        rootcnt[v]++;
        uf.unite(u, v);
    }
    LL ans = 0;
    bossgrouprootcnt.resize(K, 0);
    bossgroupsize.resize(K, 0);
    LL rootgroupsum = 0, bossrootsum = 0;
    REP(i, K) {
        for (int now = uf.find(c[i]); now != -1; now = uf.next[now]) {
            bossgrouprootcnt[i] += rootcnt[now];
        }
        bossgrouprootcnt[i] /= 2;
        bossrootsum += bossgrouprootcnt[i];
        int buf = uf.size(c[i]);
        ans += (buf * (buf - 1) / 2) - bossgrouprootcnt[i];
        bossgroupsize[i] = buf;
        rootgroupsum += buf;
    }
    int maxsize = *max_element(ALL(bossgroupsize));
    int amari = N - rootgroupsum;
    if (amari != 0) {
        ans += amari * maxsize + ((amari * (amari - 1) / 2) - (M - bossrootsum));
    }
    //out(bossgroupsize);
    //out(bossgrouprootcnt);
    cout << ans << endl;
}
