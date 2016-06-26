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

vector<vector<LL> > mp; //mp[i]にi地点から行ける場所
vector<bool> used;  //訪問済みならtrue
vector<LL> dis; //dis[i]にi地点まで来るのに使った数値最大の道
void dijkstra(LL s){
    dis[s]=s;
    priority_queue<pair<LL,LL> > q; //dis,地点
    q.push(MP(s,s));
    while(!q.empty()){
        LL qd=q.top().first,qp=q.top().second;
        q.pop();
        if(used[qp]) continue;
        used[qp]=true;
        REP(i,mp[qp].size()){
            LL nxt=mp[qp][i];
            LL d=min(nxt,dis[qp]);
            if(dis[nxt]<d){
                dis[nxt]=d; q.push(MP(d,nxt));
            }
        }
    }
    return;
}


int main(){
    LL N,M,S; cin>>N>>M>>S;
    S--;
    vector<LL> u(M),v(M);
    mp=vector<vector<LL> >(N);
    used=vector<bool>(N,false);
    dis=vector<LL>(N,INT_MIN);
    REP(i,M){
        scanf("%d %d",&u[i],&v[i]);
        u[i]--;v[i]--;
        mp[u[i]].push_back(v[i]);
        mp[v[i]].push_back(u[i]);
    }
    dijkstra(S);
    REP(i,dis.size()){
        if(i<=dis[i]) printf("%ld\n",i+1);
    }
}
