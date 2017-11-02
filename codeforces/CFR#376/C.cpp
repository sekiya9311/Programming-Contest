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
#include <random>

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for (int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for (int (i) = (a) - 1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cerr << C << endl;
#define VI vector <int>
#define VII vector <VI>
#define VL vector <LL>
#define VLL vector <VL>
#define VD vector <double>
#define VDD vector <VD>
#define PII pair <int, int>
#define PDD pair <double, double>
#define PLL pair <LL, LL>
#define VPII vector <PII>
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define EB emplace_back
#define FORE(a, b) for (auto &&a : b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;


/*** UnionFindクラス ***/
class UnionFind {
private:
    //uni[i]<0ならばiが親，そうでなければfind(uni[i])が親
    vector<int> uni;
    //グループ数
    int SIZE;
public:

    UnionFind(int size) {
        //初期状態では全ノード-1に設定し，よってすべてが親
        this->uni = vector<int>(size, -1);
        this->SIZE = size;
    }
     UnionFind() {}

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

int n, m, k;
VI c;
vector<map<int, int>> cnt;
//cnt[i][j] : 親iに連結している色jの個数
VPII lr;
UnionFind uf;

int main(void) {
    cin >> n >> m >> k;
    c.resize(200010);
    cnt.resize(200010);
    REP(i, n) {
        scanf("%d", &c[i]);
        c[i]--;
    }
    lr.resize(m);
    uf = UnionFind(200010);
    REP(i, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;r--;
        uf.unite(l, r);
        lr[i] = MP(l, r);
    }
    REP(i, n) cnt[uf.find(i)][c[i]]++;
    int ans = 0;
    set<int> usedRoot;
    REP(i, n) {
        int root = uf.find(i);
        if(FIND(usedRoot, root)) continue;
        usedRoot.insert(root);
        int maxuse = 0;
        int sum = 0;
        FORE(el, cnt[root]) {
            maxuse = max(el.second, maxuse);
            sum += el.second;
        }
        ans += sum - maxuse;
    }
    cout << ans << endl;
}
