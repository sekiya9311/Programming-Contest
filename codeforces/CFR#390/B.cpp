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

VT<string> S(4);

bool func(int h, int w) {
    int tate = 1;
    int yoko = 1;
    int naname1 = 1, naname2 = 1;
    if (h - 1 >= 0) if (S[h - 1][w] == 'x') {
        if (h - 2 >= 0 && S[h - 2][w] == 'x') tate += 2;
        else tate ++;
    }
    if (h + 1 < 4) if (S[h + 1][w] == 'x') {
        if (h + 2 < 4 && S[h + 2][w] == 'x') tate += 2;
        else tate ++;
    }
    if (w - 1 >= 0) if (S[h][w - 1] == 'x') {
        if (w - 2 >= 0 && S[h][w - 2] == 'x') yoko += 2;
        else yoko ++;
    }
    if (w + 1 < 4) if (S[h][w+1] == 'x') {
        if (w + 2 < 4 && S[h][w+2] == 'x') yoko += 2;
        else yoko ++;
    }
    if (w+1 < 4&&h+1<4) if (S[h+1][w+1] == 'x') {
        if (w+2<4&&h+2<4 &&S[h+2][w+2] == 'x') naname1+=2;
        else naname1++;
    }
    if (w-1>=0 && h-1>=0) if (S[h-1][w-1] == 'x') {
        if (w-2>=0 && h-2>=0 && S[h-2][w-2] == 'x') naname1+=2;
        else naname1++;
    }
    if (w+1 < 4&&h-1>=0) if (S[h-1][w+1] == 'x') {
        if (w+2<4&&h-2>=0 &&S[h-2][w+2] == 'x') naname2+=2;
        else naname2++;
    }
    if (w-1>=0 && h+1<4) if (S[h+1][w-1] == 'x') {
        if (w-2>=0 && h+2<4 && S[h+2][w-2] == 'x') naname2+=2;
        else naname2++;
    }
    if (tate >= 3 || yoko >= 3 || naname1 >= 3 || naname2 >= 3) return true;
    return false;
}

int main(void) {
    REP(i, 4) cin >> S[i];
    REP(i, 4) REP(j, 4) {
        if (S[i][j] == 'o') continue;
        if (func(i, j)) {
            //cout<<i<<" "<<j<<endl;
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
