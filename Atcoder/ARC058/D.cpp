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

long memfact[200100];
long mempow[200100];

long powmod(long a,long p){
    if(p==0) return 1;
    if(p&1) return a*powmod(a,p-1)%MOD;
    long t=powmod(a,p/2);
    return t*t%MOD;
}

void setting(long n){
    memfact[0]=1;
    FOR(i,1,n+1) memfact[i]=(i*memfact[i-1])%MOD;
    REP(i,n+1) mempow[i]=powmod(memfact[i],MOD-2);
}

long calc(int H,int W){
    H--; W--;
    return memfact[H+W]*mempow[H]%MOD*mempow[W]%MOD;
}

int main (void){
    long H,W,A,B; cin>>H>>W>>A>>B;
    long ans=0;
    setting(H+W+10);
    FOR(i,B,W){
        ans+=(calc(H-A,i+1)*calc(A,W-i))%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
