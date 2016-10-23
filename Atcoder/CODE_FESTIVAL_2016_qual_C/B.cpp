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
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back

const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e18;

VPII a;

int main(void) {
    int K, T;
    cin >> K >> T;
    a.resize(T);
    int mi = INF;
    REP(i, T) {
        cin >> a[i].first;
        a[i].second = i;
    }
    if (T == 1) {
        cout << a[0].first - 1 << endl;
        return 0;
    }
    RSORT(a);
    int mae = -1;
    REP(i, K) {
        if (a.size() <= 1) break;
        if (a.size()>i%2 && mae != a[i%2].second){
            a[i%2].first--; mae = a[i%2].second;
        }else if (mae != a[i%2].second) {
            a[0].first--;mae = a[0].second;
        } else if (a.size()>2){
            a[1].first--;mae=a[1].second;
        }else break;
        if (a.size()>1&&a[i%2].first==0) {
            a.erase(a.begin() + i%2);
            if (a.size()>0&&a[0].first==0) a.erase(a.begin());
            RSORT(a);
        }else if (a.size()!=0&&a[0].first==0){
             a.erase(a.begin());
            RSORT(a);
        }
    }
    if (a.size() == 0) {
        cout << 0 << endl;
    } else {
        int ans = 0;
        FORE(el, a) ans += el.first;
        cout << ans-1 << endl;
    }
}
