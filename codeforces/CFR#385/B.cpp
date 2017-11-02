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

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N, M;
VT<string> S;
int miN=INF, miM=INF, maN=0, maM=0;

int main(void) {
    scanf("%d%d", &N, &M);
    S.resize(N);
    REP(i, N) cin >> S[i];
    REP(i, N) REP(j, M) {
        if (S[i][j] == 'X') {
            miN = min(miN, i);
            miM = min(miM, j);
            maN = max(maN, i);
            maM = max(maM, j);
        }
    }
    //cout << miM << " " << maM << " " << miN << " " << maN << endl;
    FOR(i, miN, maN + 1) FOR(j, miM, maM + 1) {
        if (S[i][j] != 'X') {
            cout << "NO" << endl;
            return 0;
        }
    }
    REP(i, N) REP(j, M) {
        if (S[i][j] == 'X') {
            if (!(miN <= i && i <= maN && miM <= j && j <= maM)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}
