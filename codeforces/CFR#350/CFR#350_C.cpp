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
    vector<int> a(n);
    map<int,int> mp;
    REP(i,n){
        cin>>a[i];
        if(mp.find(a[i])!=mp.end()) mp[a[i]]++;
        else{
            mp[a[i]]=1;
        }
    }
    int m; cin>>m;
    vector<int> b(m),c(m);
    REP(i,m) cin>>b[i];
    REP(i,m) cin>>c[i];
    int ans=0,ansvp=0,ansas=0;
    REP(i,m){
        if(ansvp!=mp[b[i]]){
            ansvp=max(ansvp,mp[b[i]]);
            if(ansvp==mp[b[i]]) {ans=i+1; ansas=mp[c[i]];}
        }else{
            //if(ansas==mp[c[i]]) continue;
            ansas=max(ansas,mp[c[i]]);
            if(ansas==mp[c[i]]) {ans=i+1; ansvp=mp[b[i]];}
        }
    }
    cout<<ans<<endl;
}
