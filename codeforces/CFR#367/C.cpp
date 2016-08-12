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
#define VPII vector<PII>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define FORE(a,b) for(auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL INF=1e15;
const LL MOD=INF+7;

int main(void){
    int n; cin>>n;
    VI c(n);
    REP(i,n) scanf("%d",&c[i]);
    vector<vector<string>> sa(n,vector<string>(2));
    REP(i,n){
        char buf[100010];
        scanf("%s",buf);
        sa[i][0]=buf;
        sa[i][1]=buf;
        REVERSE(sa[i][1]);
    }
    //dp[i][j]=i-1番目までソートしていて，i番目をひっくり返すか(j=1)かえさないか(j=0)
    VLL dp(n,VL(2,INF));
    dp[0][0]=0;
    dp[0][1]=c.front();
    FOR(i,1,n)REP(j,2)REP(k,2){
        if(sa[i-1][k]<=sa[i][j]) dp[i][j]=min(dp[i][j],dp[i-1][k]+(j*c[i]));
        //if(sa[i-1][1]<=sa[i][j]) dp[i][j]=min(dp[i][j],dp[i-1][1]+(j*c[i]));
    }
    if(dp.back()[0]==INF && dp.back()[1]==INF){
        cout<<-1<<endl;
    }else{
        cout<<min(dp.back()[0],dp.back()[1])<<endl;
    }
}
