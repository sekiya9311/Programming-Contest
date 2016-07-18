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

#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(long (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(long (i)=(a)-1;(i)>=(b);(i)--)
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define VI vector<int>
#define VII vector<VI>
#define VL vector<long>
#define VLL vector<VL>
#define VD vector<double>
#define VDD vector<VD>
#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<long,long>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define FORE(a,b) for(auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;

int N,K;
VII G;

//n:現在のノード, r:親ノード, ml:残り経路長
long dfs(int n,int r,int ml){
    if(ml<0) return 0;
    int ret=1;
    FORE(nxt,G[n]){
        if(nxt!=r) ret+=dfs(nxt,n,ml-1);
    }
    return ret;
}

int main(void)
{
    cin>>N>>K;
    G=VII(N);
    REP(i,N-1){
        int a,b; cin>>a>>b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    long ans=LONG_MAX;
    if(K&1){
        REP(i,N)FORE(j,G[i]){
//連結している2頂点i,jのうち片方を親ノードとしてもう片方のノードについて探索をそれぞれ行い，それらを足すことで辺を中心とした探索とみなす
            long buf=N-(dfs(i,j,(K-1)/2)+dfs(j,i,(K-1)/2)); DEBUG(buf)
            ans=min(ans,buf);
        }
    }else{
        REP(i,N) ans=min(ans,N-dfs(i,-1,K/2));
    }
    cout<<ans<<endl;
    return 0;
}
