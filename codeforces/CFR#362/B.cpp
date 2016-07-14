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
#define VL vector<long>
#define VD vector<double>
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

int main(void)
{
    char buf[200];
    int a,d,b=0; scanf("%d.%s",&a,buf);
    string sb=buf,dd="";
    REP(i,sb.size()){
        if(sb[i]=='e'){
            dd=sb.substr(0,i);
            FOR(j,i+1,sb.size()){
                b*=10;
                b+=sb[j]-'0';
            }
        }
    }
    if(!(a==0 && b>0)) cout<<a;
    int len=dd.size();
    REP(i,b){
        if(i<len){
            cout<<dd[0];
            dd.erase(dd.begin());
        }else{
            cout<<0;
        }
    }
    if(dd.size()==1 && dd[0]=='0'){
        return 0;
    }
    if(dd.size()!=0) cout<<'.'<<dd<<endl;
    return 0;
}
