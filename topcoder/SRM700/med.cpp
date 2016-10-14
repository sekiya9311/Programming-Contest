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
#include <random>

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a)-1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a)-1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cerr << C << endl;
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
#define FORE(a, b) for (auto &&a : b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

class  XMarksTheSpot {
public:
    int countArea(vector <string> board) {
        int res = 0;
        vector<PII> nazo;
        int row = board[0].size();
        int col = board.size();
        int top, bot, left, right;
        top = left = INF;
        bot = right = 0;
        REP(i, col) REP(j, row) {
            if (board[i][j] == 'O') {
                top = min(top, i);
                left = min(left, j);
                bot = max(bot, i);
                right = max(right, j);
            }
            if (board[i][j] == '?') {
                nazo.EB(MP(i, j));
            }
        }
        REP(mask, (1 << nazo.size())) {
            int vt = top, vl = left, vb = bot, vr = right;
            REP(i, nazo.size()) if (mask & (1 << i)) {
                vt = min(vt, nazo[i].first);
                vl = min(vl, nazo[i].second);
                vb = max(vb, nazo[i].first);
                vr = max(vr, nazo[i].second);
            }
            res += (vr - vl + 1) * (vb - vt + 1);
        }
        return res;
    }
};
