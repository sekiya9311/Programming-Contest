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
#define SUM(a) accumulate(ALL(a),0)
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define FORE(a,b) for(auto &&a:b)
#define FIND(s,n) s.find(n)!=s.end()

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;
const LL LLINF=1e18;

LL dp[105][105][105];
//dp[i][j][k] = i番目の木をjで塗り，グループ数がk個の時の最小コスト

int main(void){
    int N,M,K;
    cin >> N >> M >> K;
    VL c(N+1);
    REP(i,N) cin >> c[i+1];//現在の木の色
    VLL p(N+1,VL(M+1));
    REP(i,N)REP(j,M) cin >> p[i+1][j+1];//木i+1にj+1を塗るコスト
    REP(i,105)REP(j,105)REP(k,105) dp[i][j][k]=LLINF;
    //REP(i,105) dp[0][i][0]=0;
    dp[0][0][0]=0;
    REP(i,N){
        REP(j,M+1){
            REP(k,i+1){
                if(c[i+1]==0){
                    FOR(l,1,M+1){
                        if(j==l){
                            dp[i+1][l][k]=min(dp[i+1][l][k],dp[i][j][k]+p[i+1][l]);
                        }else{
                            dp[i+1][l][k+1]=min(dp[i+1][l][k+1],dp[i][j][k]+p[i+1][l]);
                        }
                    }
                }else{
                    if(c[i+1]==j){
                        dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
                    }else{
                        dp[i+1][c[i+1]][k+1]=min(dp[i+1][c[i+1]][k+1],dp[i][j][k]);
                    }
                }
            }
        }
    }
    LL ans=LLINF;
    REP(i,M) ans=min(dp[N][i+1][K],ans);
    cout << ((ans!=LLINF)?ans:(-1)) << endl;
}
