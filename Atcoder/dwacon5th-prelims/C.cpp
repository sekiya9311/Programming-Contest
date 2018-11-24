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
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

int N;
string S;
VL m_sum;// Mの累積和
VL c_sum;//Cより前のMの数の累積和
VL d_sum;//Dより前のMの数の累積和
VL c_cnt;//Cの数の累積和

LL calc(int K) {
    // cerr << "d_sum: ";REP(i, N + 1) cerr << d_sum[i] << " ";cerr<<endl;
    // cerr << "m_sum: ";REP(i, N + 1) cerr << m_sum[i] << " ";cerr<<endl;
    // cerr << "c_sum: ";REP(i, N + 1) cerr << c_sum[i] << " ";cerr<<endl;
    // cerr << "c_cnt: ";REP(i, N + 1) cerr << c_cnt[i] << " ";cerr<<endl;
    LL ans = 0;
    REP(i, N) {
        if (S[i] == 'D') {
            LL add = c_sum[min(i + K, (int)c_sum.size() - 1)] - c_sum[i + 1] - m_sum[i + 1] * (c_cnt[min(i + K, (int)c_cnt.size() - 1)] - c_cnt[i + 1]);
            ans += add;
            //DEBUG(ans)
        }
    }
    return ans;
}

int main(void) {
    cin >> N;
    cin >> S;
    m_sum.resize(N + 1);
    c_sum.resize(N + 1);
    d_sum.resize(N + 1);
    c_cnt.resize(N + 1);
    {
        REP(i, N) {
            m_sum[i + 1] = m_sum[i] + (S[i] == 'M');
        }
        REP(i, N) {
            if (S[i] == 'C') {
                c_sum[i + 1] = m_sum[i + 1];
                c_cnt[i + 1] = 1;
            }
            c_sum[i + 1] += c_sum[i];
            c_cnt[i + 1] += c_cnt[i];
            if (S[i] == 'D') {
                d_sum[i + 1] = m_sum[i + 1];
            }
            d_sum[i + 1] += d_sum[i];
        }
    }
    int Q;
    cin >> Q;
    REP(i, Q) {
        int K;
        cin >> K;
        cout << calc(K) << endl;
    }
}
