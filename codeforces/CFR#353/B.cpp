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

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(int (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MOD 1e9+7
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define PII pair<int,int>
#define PLL pair<long,long>
#define SORT(a) sort((a).begin(),(a).end())
#define ALL(a) (a).begin(),(a).end()
typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int s[3][3]={{0}};

long sqsq(int x,int y){
	long ans=0;
	FOR(i,x,x+2){
		FOR(j,y,y+2) ans+=s[i][j];
	}
	return ans;
}

int main(void){
    long n,a,b,c,d;
    LL cnt=0;
    cin>>n>>a>>b>>c>>d;
    s[0][1]=a; s[1][0]=b; s[1][2]=c; s[2][1]=d;
    long ab,bd,dc,ca;
    ab=a+b; bd=b+d; dc=d+c; ca=c+a;
    long ma=max({ab,bd,dc,ca}),mi=min({ab,bd,dc,ca});
    //if(ab<=n*2 && bd<=n*2 && dc<=n*2 && ca<=n*2){
    	if(mi+n>=ma) cnt+=n*((mi+n)-ma);
    //}
    if(!a||!b||!c||!d) cnt=0;
    if(cnt<0) cnt=0;
    cout<<cnt<<endl;
}
