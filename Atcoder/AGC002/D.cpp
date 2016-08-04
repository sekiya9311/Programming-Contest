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

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(int (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define VI vector<int>
#define VII vector<VI>
#define VL vector<LL>
#define VLL vector<VL>
#define VD vector<double>
#define VDD vector<VD>
#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<LL,LL>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define EP emplace_back
#define FORE(a,b) for(auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;

/**
*   TLE!!
*/

/*** UnionFindクラス ***/
class UnionFind{
private:
    //uni[i]<0ならばiが親，そうでなければfind(uni[i])が親
    vector<int> uni;
    //グループ数
    int size;
public:
    UnionFind(){}
    UnionFind(int size){
        //初期状態では全ノード-1に設定し，よってすべてが親
        this->uni=vector<int>(size,-1);
        this->size=size;
    }

    //xの親を返す
    int find(int x){
        //uni[x]<0なのでxは親
        if(uni[x]<0) return x;
        //uni[x]に親ノードを入れることで連続での探索時間の短縮
        return uni[x]=find(uni[x]);
    }

    //xとyが同じグループならばtrue
    bool same(int x,int y){
        //xとyの親が同じならば同じグループに属するといえる
        return find(x)==find(y);
    }

    //xとyがそれぞれ属するグループを併合
    //併合処理を行ったならばtrueを返す
    //xとyがもともと同じグループならばfalseを返す
    bool unite(int x,int y){
        x=find(x); y=find(y);
        if(x==y) return false;
        //木の深さが小さいノードから大きいノードへ辺をはる
        if(uni[x]>uni[y]) swap(x,y);
        //yのグループをxに足す
        uni[x]+=uni[y];
        //yの親をxとする
        uni[y]=x;
        size--;
        return true;
    }

    //グループ数を返す
    int get_all_size(){
        return size;
    }

    //xが属するグループのノード数を返す
    int get_size(int x){
        return -uni[find(x)];
    }
};

bool c(int c,int num){
    return num>=c;
}

int main (void){
    int N,M;
    cin>>N>>M;
    vector<UnionFind> ufs(M+1,N);
    UnionFind uf(N);
    REP(i,M){
        int a,b; scanf("%d%d",&a,&b);
        a--; b--;
        uf.unite(a,b);
        ufs[i+1]=uf;
    }
    int Q; cin>>Q;
    vector<int> ans(Q);
    REP(i,Q){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--; y--;
        int ok=M,ng=0;
        while(ok-ng>1){
            int mid=(ok+ng)/2;
            int res=0;
            if(ufs[mid].same(x,y)){
                res=ufs[mid].get_size(x);
            }else{
                res=ufs[mid].get_size(x)+ufs[mid].get_size(y);
            }
            //cout<<"(z,res) = ("<<z<<", "<<res<<")"<<endl;
            if(res>=z) ok=mid;
            else ng=mid;
        }
        ans[i]=ok;
    }
    FORE(el,ans){
        printf("%d\n",el);
    }
}
