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

string join(const vector<string> &vec, const string &delimiter) {
    string res = "";
    for (int i = 0; i < vec.size(); ++i) {
        res += vec[i] + (i + 1 == vec.size() ? "" : delimiter);
    }
    return res;
}

void solve(int testNum) {
    int N, K;
    LL V;
    cin >> N >> K >> V;
    VT<pair<int, pair<int, string>>> S(N);
    REP(i, N) {
        S[i].first = 0;
        S[i].second.first = i;
        cin >> S[i].second.second;
    }
    REP(cnt, V) {
        SORT(S);
        REP(i, K) S[i].first++;
        bool same = true;
        REP(i, N) {
            if (S[0].first != S[i].first) {
                same = false;
                break;
            }
        }
        if (same && (cnt + 1 < V)) {
            V %= (cnt + 1);
            cnt = -1;
            REP(i, N) {
                S[i].first = 0;
            }
        }
    }
    VT<string> ans;
    {
        VT<pair<int, string>> foo;
        REP(i, K) foo.EB(S[i].second);
        SORT(foo);
        FORE(e, foo) ans.EB(e.second);
    }

    cout << "Case #" << testNum << ": " << join(ans, " ") << endl;
}

int main(void) {
    if (freopen("out.txt", "w", stdout) == NULL) {
        cerr << "file open failed" << endl;
        exit(1);
    }
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
