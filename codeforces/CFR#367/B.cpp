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

VI x,m;
int s(int num){
    if(x[0]>num) return 0;
    int high=x.size()-1,low=0;
    while(high-low>1){
        int mid=(high+low)/2;
        if(x[mid]<=num) low=mid;
        else high=mid;
    }
    if(x[high]<=num) return high+1;
    else return low+1;
}

int main(void){
    int n; cin>>n;
    x=VI(n);
    REP(i,n) scanf("%d",&x[i]);
    int q; cin>>q;
    m=VI(q);
    REP(i,q) scanf("%d",&m[i]);
    SORT(x);
    VI ans(q);
    REP(i,q){
        ans[i]=s(m[i]);
    }
    FORE(el,ans){
        cout<<el<<endl;
    }
}
