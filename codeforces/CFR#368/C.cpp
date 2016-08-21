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

/*Not Success*/

long long gcd(long long a,long long b){
    if(a<b) swap(a,b);
    long long ret=1;
    while(b){ret=b;b=a%b;a=ret;}
    return ret;
}
bool check_co_prime(LL a,LL b){
    return (gcd(a,b)==1?true:false);
}
LL calc1(LL a,LL b){return (a*a)-(b*b);}
LL calc2(LL a,LL b){return (a*a)+(b*b);}
void out(int a[]){REP(i,3)cout<<a[i]<<" ";cout<<endl;}

int main(void){
    LL n; cin >> n;
    LL nn=n*n;
    for(LL i=1;;i++){
        bool f=false;
        for(LL j=i+1;;j++){
            //cout<<i<<" "<<j<<endl;
            if(check_co_prime(i,j)!=1) continue;
            int buf[3];
            buf[0]=2*i*j,buf[1]=calc1(j,i),buf[2]=calc2(j,i);
            if(nn<buf[0] && nn<buf[1] && nn<buf[2]) break;
            //out(buf);
            f=true;
            if(n==buf[0] || n==buf[1] || n==buf[2]){
                bool ff=false;
                REP(i,3){
                    if(n==buf[i]) continue;
                    if(ff) cout<<" "<<buf[i];
                    else cout<<buf[i];
                    ff=true;
                }
                cout<<endl;
                return 0;
            }
        }
        if(!f) break;
    }
    cout<<-1<<endl;
}
