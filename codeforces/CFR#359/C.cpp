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
#define MOD 1000000007
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<long,long>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).begin(),(a).end(),greater<int>())
#define MP(a,b) make_pair(a,b)
#define FORE(a,b) for(auto &&a:b)

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL digCntSeven(LL a){
	if(!a) return 1;
	LL res=0;
	while(a){
		a/=7; res++;
	}
	return res;
}

void digCnt(vector<long> &v,LL a,LL dig){
	REP(i,dig){
		LL n=a%7; v[n]++; a/=7;
	}
}

int main(void){
	LL h,m; cin>>h>>m;
	LL hcnt=digCntSeven(h-1),mcnt=digCntSeven(m-1);
	if(hcnt+mcnt>7){
		cout<<0<<endl; return 0;
	}
	LL ans=0;
	REP(i,h)REP(j,m){
		vector<long> v(7,0);
		digCnt(v,i,hcnt);
		digCnt(v,j,mcnt);
		bool f=true;
		FORE(ve,v) if(ve>=2) f=false;
		if(f) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
