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
#include <tuple>

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

int main(void){
    vector<int> t(5);
    int ans=0;
    REP(i,5){
        cin>>t[i]; ans+=t[i];
    }
    vector<int> a;
    SORT(t);
    int minus=0;
    REP(i,4){
        if(t[i]==t[i+1] && t[i+1]==t[i+2]){
            minus=max(minus,(int)t[i]*3);
        }else if(t[i]==t[i+1]){
            minus=max(minus,(int)t[i]*2);
        }
    }
    cout<<ans-minus<<endl;
}
