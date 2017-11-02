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

const int MAX = (2 * 1e6);

int N, K, L;
UnionFind uf1, uf2;

int main(void) {
    scanf("%d%d%d", &N, &K, &L);
    uf1.resize(N);
    uf2.resize(N);
    REP(i, K) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        uf1.unite(a, b);
    }
    REP(i, L) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        uf2.unite(a, b);
    }
    map<PII, int> cnt;
    REP(i, N) {
        cnt[MP(uf1.find(i), uf2.find(i))]++;
    }
    REP(i, N) {
        printf("%d", cnt[MP(uf1.find(i), uf2.find(i))]);
        printf(i == N - 1 ? "\n" : " ");
    }
}
