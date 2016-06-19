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

int main(void){
    long a,b,c; cin>>a>>b>>c;
    if(c>=0){
    	if(a>b) cout<<"NO"<<endl;
    	else{
    		if(c) b-=a;
    		if(c&&b%c==0) cout<<"YES"<<endl;
    		else if(!c&&a==b) cout<<"YES"<<endl;
    		else cout<<"NO"<<endl;
    	}
    }else{
    	if(a<=b) cout<<"NO"<<endl;
    	else{
    		b-=a;
    		if(b%c==0) cout<<"YES"<<endl;
    		else cout<<"NO"<<endl;
    	}
    }
}
