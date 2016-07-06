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

#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(long (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(long (i)=(a)-1;(i)>=(b);(i)--)
#define MOD 1000000007
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define VI vector<int>
#define VL vector<long>
#define VD vector<double>
#define PII pair<int,int>
#define PLL pair<long,long>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).begin(),(a).end(),greater<int>())
#define MP(a,b) make_pair(a,b)
#define FORE(a,b) for(auto &&a:b)
#define INF 1e9

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

map<char,PII> mp;
int main(void){
    int n; cin>>n;
    string s; cin>>s;
    REP(i,3){
        REP(j,3) mp[(i*3)+j+'0']=MP(i,j);
    }
    mp['0']=MP(3,1);
    int maxh=0,maxw=0,minh=INF,minw=INF;
    REP(i,n){
        PII buf=mp[s[i]];
        minh=min(minh,buf.first);
        maxh=max(maxh,buf.first);
        minw=min(minw,buf.second);
        maxw=max(maxw,buf.second);
    }
    if(maxw-minw<2&&maxh-minh<3) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
