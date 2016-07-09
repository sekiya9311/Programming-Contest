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
#define VL vector<long>
#define VD vector<double>
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

class DistinguishableSetDiv2{
public:
     int count(vector<string> ans){
         int res=0; int len=1<<ans[0].size();
         int cnt=0;
         FOR(i,1,len+1){
             set<string> s;
             bool f=true;
             FORE(el,ans){
                 int bit=1;
                 string buf;
                 for(int j=0;(bit<<j)<=len;j++){
                     if(i&(bit<<j)) buf.push_back(el[j]);
                 }
                 if(s.find(buf)!=s.end()){
                     f=false; break;
                 }else s.insert(buf);
             }
             if(f) res++;
         }
         return res;
     }
};

int main(void){
    DistinguishableSetDiv2 c;
    vector<string> s{"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"};
    cout<<c.count(s)<<endl;
    return 0;
}
