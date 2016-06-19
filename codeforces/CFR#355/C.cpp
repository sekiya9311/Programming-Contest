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
    char s[100000]; scanf("%s",s);
    long len=strlen(s);
    LL ans=1;
    vector<int> a(64,0);
    REP(i,64)REP(j,64) a[i&j]++;
    REP(i,len){
        long num=0;
        if(s[i]>='0'&&s[i]<='9') num=s[i]-'0';
        if(s[i]>='A'&&s[i]<='Z') num=s[i]-55;
        if(s[i]>='a'&&s[i]<='z') num=s[i]-(97-36);
        if(s[i]=='-') num=62;
        if(s[i]=='_') num=63;
        ans=ans*a[num]%MOD;
    }
    cout<<ans<<endl;
}
