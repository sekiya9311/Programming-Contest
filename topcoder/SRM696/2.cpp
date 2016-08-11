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

/*Success!!*/
class Arrfix{
public:
    int mindiff(vector <int> A, vector <int> B, vector <int> F){
        vector<pair<int,PII>> dif;
        REP(i,A.size()){
            if(A[i]!=B[i]) dif.emplace_back(MP(i,MP(A[i],B[i])));
        }
        if(dif.size()==0){
            int res=0;
            REP(i,B.size()){
                bool f=false;
                REP(j,F.size()){
                    if(B[i]==F[i]){
                        f=true;
                        F.erase(F.begin()+j);
                        break;
                    }
                }
                if(!f) res++;
            }
            return res;
        }
        //cout<<dif.size()<<" "<<F.size()<<endl;
        //int ds=dif.size(),fs=F.size();
        REP(j,dif.size()){
            REP(i,F.size()){
                if(F[i]==dif[j].second.second){
                    F.erase(F.begin()+i);
                    dif.erase(dif.begin()+j);
                    j--;
                    break;
                }
            }
        }

        //cout<<dif.size()<<" "<<F.size()<<endl;
        return dif.size()+F.size();
    }
};

int main (void){
    Arrfix c;
    cout<<c.mindiff({2,2,2},{2,2,2},{1,2,3})<<endl;
}
