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
#define EP emplace_back
#define FORE(a,b) for(auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;

int main (void){
    int n; cin>>n;
    VI x(n); REP(i,n)cin>>x[i];
    VII dp(n+1,VI(3,INF));
    //dp[i日目][i-1日目の動作] = ここまでの最小の休み日数
    //x[i]:i日目の状況
    dp[0][0]=0;
    REP(i,n){
        //いつでも休むことは出来る
        dp[i+1][0]=min({dp[i+1][0],dp[i][0]+1,dp[i][1]+1,dp[i][2]+1});
        //活動するときは前日と同じものは出来ないことを考慮して計算
        if(x[i]&1) dp[i+1][1]=min({dp[i+1][1],dp[i][0],dp[i][2]});
        if(x[i]&2) dp[i+1][2]=min({dp[i+1][2],dp[i][0],dp[i][1]});
    }
    // REP(i,n+1){
    //     REP(j,3) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<*min_element(ALL(dp[n]))<<endl;
}
