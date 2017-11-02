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

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 1e5 + 10;
int N;
LL a[MAX], adif[MAX];
LL aodd[MAX], aeven[MAX];

int main(void) {
    memset(aodd, 0, sizeof(aodd));
    memset(aeven, 0, sizeof(aeven));
    scanf("%d", &N);
    REP(i, N) {
        scanf("%lld", a + i);
    }
    REP(i, N - 1) {
        adif[i] = llabs(a[i] - a[i + 1]);
        if (i) aodd[i + 1] = (i % 2 ? adif[i] : -adif[i]);
        aeven[i + 1] = (i % 2 ? -adif[i] : adif[i]);
    }
    
    LL oddmaidx = -1, oddma = -LLINF;
    LL evenmaidx = -1, evenma = -LLINF;
    REP(i, N) {
        aodd[i + 1] += aodd[i];
        aeven[i + 1] += aeven[i];
        if (chmax(oddma, aodd[i + 1])) {
            oddmaidx = i + 1;
        }
        if (chmax(evenma, aeven[i + 1])) {
            evenmaidx = i + 1;
        }
    }
    LL ans = 0;
//    REP(i,N+2)cout<<aodd[i]<<" "<<aeven[i]<<endl;
    for (int i = 0; i < evenmaidx; i += 2) {
        if (chmax(ans, evenma - aeven[i])) {
//            cout<<"even"<<endl;
//            cout<<evenmaidx<<" "<<i<<endl;
        }
    }
    for (int i = 1; i < oddmaidx; i += 2) {
        if (chmax(ans, oddma - aodd[i])){
//            cout<<"odd"<<endl;
//            cout<<oddmaidx<<" "<<i<<endl;
        }
    }
    cout << ans << endl;
}
