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

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for (int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for (int (i) = (a) - 1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cout<< C <<endl;
#define VI vector <int>
#define VII vector <VI>
#define VL vector <LL>
#define VLL vector <VL>
#define VD vector <double>
#define VDD vector <VD>
#define PII pair <int, int>
#define PDD pair <double, double>
#define PLL pair <LL, LL>
#define VPII vector <PII>
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define EB emplace_back
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;

/* NOT AC */


/**
* Binary_Indexed_Tree(BIT)
* Fenwick Tree
* 1-Based!!!
*/
template<typename T>
class BIT{
private:
    vector<T> bit;
    int N;
public:
    BIT(){}
    BIT(int num){
        this->N=num;
        bit=vector<T>(N+1,0);
    }
    //bit[point]にnum追加
    void add(int point,T num){
        while(point<=N){
            bit[point]+=num;
            point+=point&-point;
        }
    }
    //pointまでの値の和を返す
    T sum(int point){
        T res=0;
        while(point>0){
            res+=bit[point];
            point-=point&-point;
        }
        return res;
    }
};


int main(void) {
    int N; cin >> N;
    BIT <LL> bit(N);
    VI a(N);
    REP(i, N) {
        cin >> a[i];
        bit.add(i + 1, a[i]);
    }
    VI num(N);
    REP(i, N) {
        cin >> num[i];
    }
    list <int> nn;
    REP(i, N) {
        bit.add(num[i], -a[num[i] - 1]);
        LL res = 0;
        if (i == 0) {
            res =bit.sum(num[i]);
            if (num[i] == N) res = 0;
            LL buf = bit.sum(N) - res;
            res = max(res, buf);
            cout << res << endl;
            nn.EB(num[i]);
            continue;
        }
        LL sum = 0;
        bool f = false;
        auto itr = nn.begin();
        if (num[i] < *itr) {
            nn.emplace_front(num[i]);
            f = true;
        }
        itr = nn.begin();
        sum = bit.sum(*itr);
        res = sum;
        LL before = res;
        for (itr++; itr != nn.end(); itr++) {
            if (!f && num[i] < *itr) {
                itr = nn.insert(itr, num[i]);
                itr--;f = true;continue;
            }
            LL buf = bit.sum(*itr);
            LL nums = buf - sum;
            sum = buf;
            res = max(res, nums);
        }
        if (!f) {
            nn.EB(num[i]);
            LL buf = bit.sum(num[i]);
            LL nums = buf - sum;
            sum = buf;
            res = max(res, nums);
        }
        LL buf = bit.sum(N);
        res = max(res, buf - sum);
        cout << res << endl;
    }
}
