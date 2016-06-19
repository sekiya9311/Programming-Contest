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
    //h: pro height k : each second de kezuru ryou
    long n,k,h; cin>>n>>h>>k;
    vector<long> a(n);
    REP(i,n) cin>>a[i];
    LL ph=0;
    ULL ans=0;
    REP(i,n){
        ph+=a[i];
        if((i!=n-1 && ph+a[i+1]>h) || i==n-1){
            for(;;){
                ans+=ph/k?ph/k:1;
                ph=ph/k?ph%k:0;
                if(i!=n-1){
                    if(ph+a[i+1]<=h) break;
                }else{
                    if(!ph) break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
