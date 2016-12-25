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

//NOT AC

int N;
VPII X;
VI ans;
VI nokori;
VI cnt;

int main(void) {
    scanf("%d", &N);
    X.resize(N);
    const int NN = N * N;
    ans.resize(NN);
    nokori.resize(N);
    cnt.resize(N, 0);
    REP(i, N) {
        scanf("%d", &X[i].first);
        X[i].first--;
        X[i].second = i + 1;
        nokori[i] = i + 1;
    }
    RSORT(X);
    int nowxid = N - 1, nowcntid = 0;
    REP(i, NN) {
        if (X.back().first == i) {
            if (nokori[X.back().second - 1] != 1) {
                cout << "No" << endl;
                return 0;
            }
            cnt[X.back().second - 1]++;
            ans[i] = X.back().second;
            nokori[X.back().second - 1]--;
            X.pop_back();
        } else {
            while (nokori[X[nowxid].second - 1] <= 1  && nowxid >= 0) nowxid--;
            if (nowxid != -1) {
                ans[i] = X[nowxid].second;
                nokori[X[nowxid].second - 1]--;
                cnt[X[nowxid].second - 1]++;
            } else {
                while (cnt[nowcntid] == N && nowcntid < N) nowcntid++;
                if (nowcntid == N) {
                    cout << "No" << endl;
                    return 0;
                }
                cnt[nowcntid]++;
                ans[i] = nowcntid + 1;
            }
        }
    }
    cout << "Yes" << endl;
    REP(i, NN) {
        printf("%d%c", ans[i], (i + 1 == NN ? '\n' : ' '));
    }
}
