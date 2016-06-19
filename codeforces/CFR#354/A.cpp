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

#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define RREP(i,a) for(long (i)=(a)-1;(i)>=0;(i)--)
#define FORR(i,a,b) for(long (i)=(a)-1;(i)>=(b);(i)--)
#define MOD 1000000007
#define PI acos(-1.0)
#define DEBUG(C) cout<<C<<endl;
#define PII pair<int,int>
#define PLL pair<long,long>
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).begin(),(a).end(),greater<int>())

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

long sigma(long a){
    if(a==1) return 1;
    return a+sigma(a-1);
}

struct Node{
    double num;
    Node* left;
    Node* right;
}

int main(){
    int n,t; cin>>n>>t;
    long mg=sigma(n);
    Node n[mg+10];
    FOR(i,1,mg+1){
        n[i].num=0;
        n[i].left=2*i<mg?&n[2*i]:NULL;
        n[i].right=2*i+1<mg?&n[2*i+1]:NULL;
    }
    FOR(i,1,mg+1){
        if(mg[i].num>1){
            double lef,rig;
            lef=(mg[i].num-1)/2;
            rig=lef; mg[i].num=1;
            if(n[i].left!=NULL) *n[i].left->num=lef;
            if(n[i].right!=NULL) *n[i].right->num=rig;
        }
    }
    int cnt=0;
    REP(i,1,mg+1){
        if(mg[i].num==1) cnt++;
    }
    cout<<cnt<<endl;
}
