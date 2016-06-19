#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
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

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(int (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MOD 1e9+7
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int n; cin>>n;
    int w[]={0,0,0,0,0,1,1};
    int nn=n,mmin=1000000,mmax=0;
    REP(i,7){
        int wcnt=0,hcnt=0;
        REP(j,nn){
            if(w[(j+i)%7]) hcnt++;
            else wcnt++;
        }
        mmin=min(mmin,hcnt);
        mmax=max(mmax,hcnt);
    }
    cout<<mmin<<" "<<mmax<<endl;
}