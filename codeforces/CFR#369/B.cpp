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
#define FIND(s,n) s.find(n)!=s.end()

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;
#define int LL
VLL a;
int n;
LL func(int num){
    LL res=0;
    REP(i,n) res+=a[num][i];
    return res;
}
LL sum(int num){
    LL res=0;
    REP(i,n) res+=a[i][num];
    return res;
}
PLL naname(){
    LL res1=0,res2=0;
    REP(i,n) res1+=a[i][i],res2+=a[n-i-1][i];
    return MP(res1,res2);
}
void vecout(VLL a){
    REP(i,a.size()){
        REP(j,a[i].size()) cout << a[i][j] << " ";
        cout << endl;
    }
}

signed main(void){
    cin >> n;
    a=VLL(n,VL(n));
    PII p;
    REP(i,n)REP(j,n){
        cin >> a[i][j];
        if(a[i][j]==0){
            p=MP(i,j);
        }
    }
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    bool f=true;
    LL ans=0;
    LL BUF;

//DEBUG(f)

    if(p.first){
        BUF=func(0);
        FOR(i,1,n){
            LL buf=func(i);
            if(p.first==i){
                ans=BUF-buf;
            }else{
                if(BUF!=buf) f=false;
            }
        }

    }else{
        BUF=func(1);
        ans=BUF-func(0);
        FOR(i,2,n){
            if(i==1) continue;
            LL buf=func(i);
            if(BUF!=buf) f=false;
        }
    }
    LL isum=BUF;
    BUF=0;

//DEBUG(f)

    if(p.second){
        BUF=sum(0);
        FOR(i,1,n){
            LL buf=sum(i);
            if(p.second==i){
                LL ansbuf=BUF-buf;
                if(ansbuf!=ans) f=false;
            }else{
                if(BUF!=buf) f=false;
            }
        }
    }else{
        BUF=sum(1);
        LL ansbuf=BUF-sum(0);
        if(ansbuf!=ans) f=false;
        FOR(i,2,n){
            LL buf=sum(i);
            if(BUF!=buf) f=false;
        }
    }

//DEBUG(f)

    if(isum!=BUF) f=false;
//DEBUG(isum)
//DEBUG(f)

    auto nm=naname();
    if(p.first==p.second && n&1 && (n-1)/2==p.first){
        if(!(nm.first==nm.second && nm.first+ans==BUF)) f=false;
    }else if(p.first==p.second){
        if(!(nm.second==nm.first+ans && nm.second==BUF)) f=false;
        //cout << " " <<nm.first << " " << nm.second << " " << ans << " " << BUF << endl;
    }else if(p.first+p.second==n-1){
        if(!(nm.first==nm.second+ans && nm.first==BUF)) f=false;
        //cout << " " <<nm.first << " " << nm.second << " " << ans << endl;
    }else{
        if(!(nm.first==nm.second && nm.first==BUF)) f=false;
        //cout << " " <<nm.first << " " << nm.second << " " << BUF << endl;
    }

//DEBUG(f)

    if(f && ans>0){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}
