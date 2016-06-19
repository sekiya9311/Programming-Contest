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
#include <tuple>
#include <sstream>

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
#define MP(a,b) make_pair(a,b)

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

vector<long> a;
vector<PLL> pc;
set<long> s;

struct node{
    int num;
    node *right,*left,*mom;
    node(){
        right=NULL;
        left=NULL;
        mom==NULL;
    }
};

int main(void){
    int n; cin>>n;
    vector<node> tree(n);
    a=vector<long>(n);  //num in the vertex i
    pc=vector<PLL>(n-1);  //connect (i)&p[i] with root cost c[i]
    REP(i,n){
        cin>>a[i];
        tree[i].num=a[i];
    }
    REP(i,n-1){
        cin>>pc[i].first>>pc[i].second;
        pc[i].first--;
        s.insert(pc[i].first);
        if(tree[pc[i].first]->left==NULL) tree[pc[i].first]->left=&tree[i];
        else tree[pc[i].first]->right=&tree[i];
        tree[i]->mom=&tree[pc[i].first];
    }
    LL cnt=0;
    while(1){
        bool f=false;
        FOR(i,1,n){
            if(tree[i]->right!=NULL || tree[i]->left!=NULL) continue;
            if(abs(pc[i-1].second)>tree[i].num){
                node *buf; buf=&tree[i]->mom;
                tree[i]->mom=NULL;
                if(buf->left==&tree[i]) buf->left=NULL;
                else buf->right=NULL;
                cnt++;
                f=true;
            }
        }
        if(!f) break;
    }
    cout<<cnt<<endl;
}
