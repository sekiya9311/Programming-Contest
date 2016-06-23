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
#define PII pair<int,int>
#define PLL pair<long,long>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).begin(),(a).end(),greater<int>())
#define MP(a,b) make_pair(a,b)
#define FORE(a,b) for(auto &&a:b)

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

string memo[1000010];
bool f[1000010];
LL ncnt=0,mcnt=0;
LL mnmax=0;

LL ff(LL num){
    LL cnt=0;
    while(num){
        num/=7;
        cnt++;
    }
    return cnt;
}

bool c(LL n){
    memo[n]="";
    LL buf=n;
    string s;
    while(n){
        LL num=n%7;
        char c=num+'0';
        REP(i,s.size()){
            if(s[i]==c) return false;
        }
        s.push_back(c);
        n/=7;
    }
    //reverse(ALL(s))
    if(s.empty()&&buf!=0) return false;
    if(mnmax-s.size()>=2) return false;
    if(buf!=0) memo[buf]=s;
    else memo[buf]="0";
    return true;
}

bool cc(string s){
    set<char> ss;
    REP(i,s.size()){
        if(ss.find(s[i])!=ss.end()) return false;
        else ss.insert(s[i]);
    }
    if(mcnt+ncnt-s.size()>=2) return false;
    return true;
}

int main(){ //一日n時間，一時間m分，七進表記
    LL n,m; cin>>n>>m;
    LL ans=0;
    LL num=max(n,m);
    ncnt=ff(n); mcnt=ff(m);
    mnmax=max(ncnt,mcnt);
    num=min(num,(LL)1000000);
    REP(i,num){
        f[i]=c(i);
    }
    REP(i,min(n,(LL)1000000)){
        if(f[i]){
            REP(j,min(m,(LL)1000000)){
                if(f[j]){
                    string ss=memo[i]+memo[j];
                    //cout<<memo[i]<<" "<<memo[j]<<endl;
                    if(cc(ss)) ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
