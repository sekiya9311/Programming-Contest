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

using state = tuple<LL, LL, LL>; //(mi, ma, cnt)
const int MAX = 1e6 + 10;
bool used[MAX];

void solve(int num) {
    memset(used, false, sizeof(used));
    LL N, K;
    cin >> N >> K;
    LL MI = -1, MA = -1;
    map<LL, map<LL, LL>> mp;
    mp[N / 2 - (N % 2 == 0)][N / 2] = 1;
    while (K) {
        auto it1 = mp.rbegin();
        assert(!mp.empty() && !(*it1).second.empty());
        auto it2 = (*it1).second.rbegin();
        LL mi = (*it1).first, ma = (*it2).first, cnt = (*it2).second;
        (*it1).second.erase(--(*it1).second.end());
        if ((*it1).second.empty()) mp.erase(--mp.end());
        assert(cnt);
        //DEBUG(cnt)
        if (K > cnt) {
            K -= cnt;
            mp[mi / 2 - (mi % 2 == 0)][mi / 2] += cnt;
            mp[ma / 2 - (ma % 2 == 0)][ma / 2] += cnt;
        } else {
            K = 0;
            MI = mi, MA = ma;
            break;
        }
    }
    cout << "Case #" << num << ": " << MA << " " << MI << endl;
}

int main(void) {
    if (freopen("out.txt", "w", stdout) == NULL) {
        cerr << "file open failed" << endl;
        return 0;
    }
	int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int i = 0; i < problemnum; i++) {
        solve(i + 1);
        cerr << "Case #" << i + 1 << ": solved" << endl;
    }
}
