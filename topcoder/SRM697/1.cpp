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
#define VSUM(a) accumulate(ALL(a),0)

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9;
const int MOD=INF+7;

class  TriangleMaking{
public:
     int maxPerimeter(int a, int b, int c){
         int res=0;
         FOR(i,1,a+1)FOR(j,1,b+1)FOR(k,1,c+1){
             if(i+j<=k || j+k<=i || k+i<=j) continue;
             res=max(res,i+j+k);
         }
         return res;
     }
};

int main(void){
    TriangleMaking c;
    cout<<c.maxPerimeter(1,2,3)<<endl;
}
