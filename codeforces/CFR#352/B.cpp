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

int main(void){
    int n; cin>>n;
    string s; cin>>s;
    map<char,int> mp;
    char c='a';
    REP(i,26) mp[(char)(c+i)]=0;
    REP(i,s.size()) mp[s[i]]++;
    int cnt=0;
    REP(i,26){
        if(mp[(char)(c+i)]>1) cnt+=mp[(char)(c+i)]-1;
    }
    if(cnt<26 || s.size()<27) cout<<cnt<<endl;
    else cout<<-1<<endl;
}
