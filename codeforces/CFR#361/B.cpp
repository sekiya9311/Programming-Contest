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
#define VI vector<int>
#define VL vector<long>
#define VD vector<double>
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
int n;
const LL INF=1e15;
vector<LL> dijkstra(vector<vector<PLL> > edge){
    vector<LL> res(n,INF);
    priority_queue<PLL,vector<PLL>,greater<PLL> > q;  //cost, pos
    q.push(MP(0,0));
    while(!q.empty()){
        auto now=q.top(); q.pop();
        LL pos=now.second,cost=now.first;
        if(res[pos]==INF) res[pos]=cost;
        else continue;
        FORE(el,edge[pos]){
            q.push(MP(el.second+cost,el.first));
        }
    }
    return res;
}

int main(void){
    cin>>n;
    VI a(n),p(n);
    REP(i,n){
        cin>>a[i]; a[i]--;
        p[i]=i;
    }
    vector<vector<PLL> > edge(n);
    int buf=0;
    REP(i,n){
        if(i==a[i]){
            edge[buf].push_back(MP(i,1));
            edge[i].push_back(MP(i+1,1));
            buf=i+1;
        }else{
            edge[i].push_back(MP(i+1,1));
            edge[i+1].push_back(MP(i,1));
        }
    }
    auto ans=dijkstra(edge);
    REP(i,n) cout<<ans[i]<<endl;
}
