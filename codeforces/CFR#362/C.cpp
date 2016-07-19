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

//http://codeforces.com/contest/697/submission/19130749

map<pair<LL,LL>,LL> mp;

void DEB(LL a,LL b){cout<<a<<" "<<b<<endl;}

//mapに値をセット
void mpset(LL v,LL u,LL w){
    LL sml=min(v,u),big=max(v,u);
    auto p=MP(sml,big);
    mp[p]+=w;
}

//mapから値を得る
LL mpget(LL v,LL u){
    LL sml=min(v,u),big=max(v,u);
    auto p=MP(sml,big);
    return mp[p];
}

//経路間の重みの更新
void make(LL v,LL u,LL w){
    if(v==u) return;
    LL big=max(v,u),sml=min(v,u);
    //DEB(sml,big);
    if(sml==1 && (big==2 || big==3)){
        mpset(sml,big,w); return;
    }
    if(big&1){
        mpset((big-1)/2,big,w);
        make(sml,(big-1)/2,w);
    }else{
        mpset(big/2,big,w);
        make(sml,big/2,w);
    }
}

//経路間の重みの総和を得る
LL get(LL v,LL u){
    if(v==u) return 0;
    LL big=max(v,u),sml=min(v,u);
    //DEB(sml,big);
    if(big==2 || big==3){
        if(sml==1){
            //return mpget(1,2); <--ダメ！！
            return mpget(sml,big);
        }else{
            LL ans=mpget(1,2)+mpget(1,3);
            return ans;
        }
    }
    LL ans=0;
    if(big&1){
        ans=mpget((big-1)/2,big);
        return ans+get(sml,(big-1)/2);
    }else{
        ans=mpget(big/2,big);
        return ans+get(sml,big/2);
    }
}

int main(void)
{
    int q; cin>>q;
    REP(i,q){
        int num; scanf("%d",&num);
        if(num==1){
            LL v,u,w; cin>>v>>u>>w;
            make(v,u,w); //DEBUG("MAKEEND");
        }else{
            LL v,u; cin>>v>>u;
            cout<<get(v,u)<<endl; //DEBUG("GETEND")
        }
    }
    return 0;
}
