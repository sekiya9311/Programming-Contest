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

/*Not Success!!*/
class Ropestring{
public:
    string makerope(string s){
        string ret="";
        int rn=1,dl=0;
        REP(i,s.size()) if(s[i]=='.') dl++;
        FOR(i,1,s.size()){
            if(s[i-1]=='-' && s[i]=='.') rn++;
        }
        if(rn==1) return s;
        VI num(rn,0);
        map <int,int> mp;
        int i=0;
        REP(k,s.size()){
            if(k && s[k-1]=='-' && s[k]=='.') i++;
            if(s[k]=='-') num[i]++;
        }
        // FORE(el,num) cout<<el<<" ";
        // cout<<endl;
        FORE(el,num) mp[el]++;
        set<PII> se;
        FORE(el,mp){
            se.insert(MP(el.second,el.first));
        }
        //FORE(el,se) cout<<el.first<<" "<<el.second<<endl;
        ret+=str('.',dl-rn-1);
        FORE(el,se){
            REP(i,el.first){
                ret+=str('-',el.second);
                if(i!=el.first-1 || el.first==1) ret+='.';
            }
        }
        REVERSE(ret);
        ret+=str('.',s.size()-ret.size());
        return ret;
    }

    string str(char c,int len){
        string ret="";
        REP(i,len) ret+=c;
        return ret;
    }
};

int main (void){
    Ropestring c;
    cout<<c.makerope("..-..-")<<endl;
}
