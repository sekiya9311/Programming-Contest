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

bool isPrime(int a){
    if(a<2) return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}

vector<int> primeNum(int a){
    vector<int> res;
    REP(i,a){
        if(isPrime(i+1)) res.push_back(i+1);
        else if(i+1==4) res.push_back(4);
    }
    return res;
}

int main(void){
    string ans;
    vector<int> prime=primeNum(100);
    vector<int> neven;
    FOR(i,2,100) neven.push_back(i+1);
    prime.erase(prime.begin());

    int bin; bool bf,even;
    string res;
    cout<<2<<endl; fflush(stdout);
    cin>>res;
    if(res=="yes") even=true;
    else even=false;
    if(even){
        int i=0;
        while(1){
            if(prime[i]<=50){
                cout<<prime[i]<<endl; fflush(stdout);
                cin>>res;
                if(res=="yes"){
                    cout<<"composite"<<endl;
                    return 0;
                }else i++;
            }else break;
        }
        ans="prime";
    }else{
        int i=0;
        while(1){
            if(prime[i]*prime[i]<=100){
                cout<<prime[i]<<endl; fflush(stdout);
                cin>>res;
                if(res=="yes"){
                    int j=i;
                    while(1){
                        if(prime[i]*prime[j]<=100){
                            cout<<(prime[i]*prime[j])<<endl; fflush(stdout);
                            cin>>res;
                            if(res=="yes"){
                                cout<<"composite"<<endl;
                                return 0;
                            }else j++;
                        }else break;
                    }
                    cout<<"prime"<<endl;
                    return 0;
                }else i++;
            }else break;
        }
        ans="prime";
    }
    cout<<ans<<endl;
    return 0;
}
