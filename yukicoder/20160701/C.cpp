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

bool isPrime(int a){
    if(a<2) return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}

int M,N;
vector<int> C;
vector<int> dp;
int ans=0;

int main(){
    cin>>M>>N;
    C=vector<int>(N);
    REP(i,N) cin>>C[i];
    SORT(C);
    int num=0;
    dp.push_back(0);
    while(num<=M){
        num+=*C.begin();
        dp.push_back(num);
    }
    set<int> p;
    while(1){
        int buf=ans; bool f=true;
        REP(i,C.size()){
            int m=M-dp[i]-C[i]; if(m>=0) f=false;
            if(isPrime(m)&&(p.find(m)==p.end())){
                ans+=i; i==C.size(); p.insert(m);
            }
        }
        if(ans==buf){
            if(f){
                cout<<ans<<endl; return 0;
            }else{
                bool f=true;
                REP(i,C.size()) if(C[i]>M){
                    ans+=(i-1); i=C.size(); M-=dp[i]; f=false;
                }
                if(f){
                    ans+=dp.size()-1; M-=dp.back();
                }
            }
        }
    }
}
