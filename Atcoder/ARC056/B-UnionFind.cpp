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

#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(long (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(long (i)=(a)-1;(i)>=(b);(i)--)
#define MOD 1000000007
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define PII pair<int,int>
#define PLL pair<long,long>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).begin(),(a).end(),greater<int>())
#define MP(a,b) make_pair(a,b)
#define FORE(a,b) for(auto &&a:b)

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

template<typename T>
class UnionFind{
private:
    vector<T> v; //親
    vector<T> r; //木の深さ
    vector<T> d;//集合のサイズ
    T group;    //集合数
public:
    UnionFind(){}
    UnionFind(T n,T a=1){
        v=vector<T>(n);
        r=vector<T>(n);
        d=vector<T>(n,1);
        for(T i=0;i<n;i++){
            v[i]=i; r[i]=a;
        }
        group=n;
    };
    T find(T n){  //根を探す
        if(v[n]==n) return n;
        else return (v[n]=find(v[n]));
    }
    bool same(T x,T y){  //同じ根を持つか
        return (find(x)==find(y));
    }
    bool unite(T x,T y){  //併合
        x=find(x); y=find(y);
        if(x==y) return false;
        if(r[x]<r[y]) swap(r[x],r[y]);
        v[y]=x;
        d[x]+=d[y];
        if(r[x]==r[y]) r[x]++;
        group--;
        return true;
    }
    T size(T a){return d[find(a)];} //aを含む集合のサイズ
    T gSize(){return group;}    //集合数
};


int main(){
    LL N,M,S; cin>>N>>M>>S;
    S--;
    vector<LL> u(M),v(M);
    vector<vector<LL> > mp(N);
    REP(i,M){
        scanf("%d %d",&u[i],&v[i]);
        u[i]--;v[i]--;
        mp[u[i]].push_back(v[i]);
        mp[v[i]].push_back(u[i]);
    }
    UnionFind<LL> uf(N);
    vector<LL> ans;
    RREP(i,N){
        FORE(mm,mp[i]){
            if(mm>=i) uf.unite(mm,i);
        }
        if(uf.same(S,i)) ans.push_back(i+1);
    }
    RREP(i,ans.size()) printf("%lld\n",ans[i]);
}
