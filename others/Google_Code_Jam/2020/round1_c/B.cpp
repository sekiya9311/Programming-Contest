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
#include <functional>

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
#define EB emplace_back
#define GREATER(T) T, VT<T> greater<T>
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

char strbuf[111];
string get_str() {
    scanf("%s", strbuf);
    return strbuf;
}

int diff(const PII &p) {
    return p.second - p.first;
}

const int MAX = 1e4;
int U;
pair<LL, string> in[MAX];

void solve(stringstream &out) {
    map<char, int> cands;
    set<char> all;
    scanf("%d", &U);
    REP(i, MAX) {
        scanf("%lld", &in[i].first);

        in[i].second = get_str();
        cands[in[i].second[0]]++;
        FORE(c, in[i].second) {
            all.emplace(c);
        }
    }

    char zero;
    {
        FORE(e, all) {
            if (cands.count(e) == 0) {
                zero = e;
                break;
            }
        }
    }

    VT<pair<char, int>> vec(ALL(cands));
    sort(ALL(vec), [](const auto &l, const auto &r) {
        return l.second < r.second;
    });
    REVERSE(vec);

    string ans = "";
    ans += zero;
    FORE(e, vec) {
        ans += e.first;
    }
    out << ans << endl;
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }

    int problem_count;
    scanf("%d", &problem_count);
    //string s;getline(cin, s);
    for (int test_no = 1; test_no <= problem_count; test_no++) {
        stringstream out;
        solve(out);
        printf("Case #%d: %s", test_no, out.str().c_str());
        // cerr << "Case #" << test_no << ": solved" << endl;
    }
}
