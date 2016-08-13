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
#define EP emplace_back
#define FORE(a,b) for(auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;

// int main(void){
//     string s; cin>>s;
//     map<char,int> mp;
//     REP(i,s.size()){
//         FOR(j,i,s.size()){
//             mp[s[j]]++;
//             if(j>i && mp[s[j]]*2>j-i+1){
//                 cout<<i+1<<" "<<j+1<<endl;
//                 return 0;
//             }
//         }
//         mp.clear();
//     }
//     cout<<-1<<" "<<-1<<endl;
// }


int main(){
    string s; cin>>s;
    map<char,int> mp;
    if(s.size()==2){
        if(s[0]==s[1]){
            cout<<1<<" "<<2<<endl;
            return 0;
        }else{
            cout<<-1<<" "<<-1<<endl;
            return 0;
        }
    }
    REP(i,s.size()-2){
        REP(j,5){
            if(i+j>=s.size()) break;
            mp[s[i+j]]++;
            if(j && mp[s[i+j]]*2>j+1){
                cout<<i+1<<" "<<i+1+j<<endl;
                return 0;
            }
        }
        mp.clear();
    }
    cout<<-1<<" "<<-1<<endl;
}
