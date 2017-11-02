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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N, K;
long double U;
long double P[55];

void solve(int testNum) {
    cin >> N >> K;
    cin >> U;
    REP(i, N) {
        cin >> P[i];
    }

    long double ans = 1;
    if (N >= 2) {
        priority_queue<long double, VT<long double>, greater<long double>> pq;
        REP(i, N) {
            pq.push(P[i]);
        }
        while (U != 0.0) {
            auto e1 = pq.top(); pq.pop();
            auto e2 = pq.top(); pq.pop();
            if (e1 == 1.0) {
                pq.push(e1);
                pq.push(e2);
                break;
            }
            //DEBUG(e1) DEBUG(e2)
            if (U < e2 - e1 + 1e-4) {
                e1 += U;
                U = 0.0;
                pq.push(e1);
                pq.push(e2);
                break;
            } else {
                auto dif = e2 - e1 + 1e-4;
                U -= dif;
                e1 += dif;
            }
            pq.push(e1);
            pq.push(e2);
        }
        DEBUG(pq.size())
        while (!pq.empty()) {
            ans *= pq.top();
            pq.pop();
        }
    } else {
        ans = min<long double >(P[0] + U, 1.0);
    }

    cout << "Case #" << testNum << ": " << fixed << setprecision(10) << ans << endl;
}

int main(void) {
    if (freopen("out.txt", "w", stdout) == NULL) {
        cerr << "file open failed" << endl;
        exit(1);
    }
	int problemnum;
    scanf("%d", &problemnum);
    DEBUG(problemnum)
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
