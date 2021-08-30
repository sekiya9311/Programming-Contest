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

int calc1(string s) {
    map<char, int> target;
    int other = 0;
    for (auto c : s) {
        if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            target[c]++;
        } else {
            other++;
        }
    }

    int ma = 0;
    for (auto [k, v] : target) {
        chmax(ma, v);
    }

    const int tmp = s.length() - other - ma;
    return tmp * 2 + other;
}
int calc2(string s) {
    map<char, int> target;
    int other = 0;
    for (auto c : s) {
        if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            other++;
        } else {
            target[c]++;
        }
    }

    int ma = 0;
    for (auto [k, v] : target) {
        chmax(ma, v);
    }

    const int tmp = s.length() - other - ma;
    return tmp * 2 + other;
}

void solve(stringstream &out) {
    string s;
    cin >> s;

    out << min(calc1(s), calc2(s)) << "\n";
}

int main(void) {
    if (freopen("out.txt", "w", stdout) == NULL) {
        cerr << "file open failed" << endl;
        exit(1);
    }

    int problem_count;
    scanf("%d", &problem_count);
    //string s;getline(cin, s);
    for (int test_no = 1; test_no <= problem_count; test_no++) {
        stringstream out;
        solve(out);
        printf("Case #%d: %s", test_no, out.str().c_str());
        cerr << "Case #" << test_no << ": solved" << endl;
    }
}
