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
#define INF 1e9

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int main(void)
{
    int N,M; cin>>N>>M;
    VI x(M),y(M);
    REP(i,M){
        cin>>x[i]>>y[i];
        x[i]--; y[i]--;
    }
    vector<bool> check(1<<N,true);
    REP(i,1<<N)REP(j,M){
        if((!((i>>x[j])&1)) && ((i>>y[j])&1)) check[i]=false;
    }
    vector<LL> dp(1<<N,0);
    dp[0]=1;
    REP(i,1<<N)if(check[i]){
        REP(j,N) if(check[i|(1<<j)] && !((i>>j)&1)) dp[i|(1<<j)]+=dp[i];
    }
    //REP(i,1<<N) cout<<check[i]<<" "<<dp[i]<<endl;
    cout<<dp.back()<<endl;
}
