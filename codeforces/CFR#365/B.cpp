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
/**
* define LL
*/
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

signed main (void){
    int n,k;
    cin>>n>>k;
    VI c(n);
    set<int> ids;
    REP(i,n) scanf("%d",&c[i]);
    LL sum=accumulate(ALL(c),0);
    LL ans=0;
    LL ss=0;
    REP(i,n){
        ans+=(c[i]*c[(i+1)%n]);
    }
    REP(i,k){
        int id;
        scanf("%d",&id);
        id--;
        ans+=sum*c[id]; ans-=c[id]*c[id];
        ans-=(c[id]*c[(id+1)%n]);
        ans-=(c[id]*c[((n+id-1)%n)]);
        ans-=(c[id]*ss);
        if(ids.find(((n+id-1)%n))!=ids.end()) ans+=c[id]*c[((n+id-1)%n)];
        if(ids.find(((id+1)%n))!=ids.end()) ans+=c[id]*c[((id+1)%n)];
        ids.insert(id);
        ss+=c[id];
    }
    cout<<ans<<endl;
}
