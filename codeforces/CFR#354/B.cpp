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

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

long sigma(long a){
    if(a==1) return 1;
    return a+sigma(a-1);
}


int main(){
    int n,t; cin>>n>>t;
    long mg=sigma(n);
    vector<vector<double> > gl(n+10,vector<double>(n+10,0));
    gl[0][0]=t;
    REP(i,n){
        REP(j,n+1){
            if(gl[i][j]>1){
                double num=(gl[i][j]-1)/2;
                gl[i][j]=1;
                gl[i+1][j]+=num; gl[i+1][j+1]+=num;
            }
        }
    }
    int cnt=0;
    REP(i,n){
        REP(j,n+1){
            if(gl[i][j]==1) cnt++;
        }
    }
    cout<<cnt<<endl;
}
