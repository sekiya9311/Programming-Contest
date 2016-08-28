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
const int INF=1e9;
const int MOD=INF+7;
#define int LL

const int NUM = (50*50)+1;
int N,A;
VI x;
LL dp[51][51][NUM]={0};

signed main(void){
    cin >> N >> A;
    x=VI(N);
    REP(i,N){
        cin >> x[i];
    }
    dp[0][0][0]=1;
    //先頭からi個の内，j個選んだ組み合わせで総和kが何通りか
    REP(i,N){
        REP(j,i+1){
            REP(k,NUM){
                dp[i+1][j][k]+=dp[i][j][k]; //x[i]を候補に追加して使用しなかった場合
                dp[i+1][j+1][k+x[i]]+=dp[i][j][k]; //x[i]を候補に追加して使用した場合
            }
        }
    }
    LL ans=0;
    //先頭からN個のうち，ave==(i*A)/i==A
    FOR(i,1,N+1){
        ans+=dp[N][i][i*A];
    }
    cout << ans << endl;
}
