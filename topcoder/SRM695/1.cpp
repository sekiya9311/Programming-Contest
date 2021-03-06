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

#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(long (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(long (i)=(a)-1;(i)>=(b);(i)--)
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define VI vector<int>
#define VII vector<VI>
#define VL vector<long>
#define VLL vector<VL>
#define VD vector<double>
#define VDD vector<VD>
#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<long,long>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define FORE(a,b) for(auto &&a:b)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;

class BearNSWE{
public:
    double totalDistance(vector <int> a, string dir){
        double ret=0;
        PDD p=MP(0.0,0.0);
        REP(i,dir.size()){
            if(dir[i]=='N'){
                p.second+=a[i];
            }
            if(dir[i]=='S'){
                p.second-=a[i];
            }
            if(dir[i]=='W'){
                p.first-=a[i];
            }
            if(dir[i]=='E'){
                p.first+=a[i];
            }
            ret+=a[i];
        }
        //cout<<p.first<<" "<<p.second<<endl;
        ret+=sqrt((p.first*p.first)+(p.second*p.second));
        return ret;
    }
};

int main (void){
    BearNSWE c;
    vector<int> a{1,3,3};
    string s="NES";
    cout<<fixed<<setprecision(10)<<c.totalDistance(a,s)<<endl;
}
