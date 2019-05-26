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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

// 区間変更，区間最小値
template<typename T = int,
typename ctype = std::less<T>,
T LIM = (std::is_same<ctype, std::less<T>>::value ?
std::numeric_limits<T>::max() : std::numeric_limits<T>::min())>
class range_update_query_minmax {
private:
     std::vector<T> data, lazy;
     std::vector<bool> valid, lazyFlag;
     ctype comp;
     const T initVal;
     int sz;
     void push(int k) {
          if (this->lazyFlag[k]) {
               this->valid[k] = true;
               this->data[k] = this->lazy[k];
               if ((k << 1) + 2 < (sz << 1) - 1) {
                    this->lazy[(k << 1) + 1] = this->lazy[(k << 1) + 2] = this->lazy[k];
                    this->lazyFlag[(k << 1) + 1] = this->lazyFlag[(k << 1) + 2] = true;
               }
               this->lazyFlag[k] = false;
          }
     }
     void update(int l, int r, int L, int R, int k, T val) {
          this->push(k);
          if (L <= l && r <= R) {
               this->lazy[k] = val;
               this->lazyFlag[k] = true;
               this->push(k);
          } else if (r < L || R < l) {
               return;
          } else if (r - l > 1) {
               const int mid = (l + r) >> 1;
               this->update(l, mid, L, R, (k << 1) + 1, val);
               this->update(mid, r, L, R, (k << 1) + 2, val);
               data[k] = std::min(data[(k << 1) + 1], data[(k << 1) + 2], comp);
          }
     }
     T query(int l, int r, int L, int R, int k) {
          this->push(k);
          if (L <= l && r <= R) {
               return this->data[k];
          } else if (r <= L || R <= l) {
               return this->initVal;
          } else {
               const int mid = (l + r) >> 1;
               T left = this->query(l, mid, L, R, (k << 1) + 1);
               T right = this->query(mid, r, L, R, (k << 1) + 2);
               return std::min(left, right, comp);
          }
     }
public:
     range_update_query_minmax(const int n, T initval = LIM) : initVal(initval) {
          this->sz = 1;
          while (this->sz < n) {
              this->sz <<= 1;
          }
          this->data.resize((this->sz << 1) - 1, this->initVal);
          this->lazy.resize((this->sz << 1) - 1);
          this->valid.resize((this->sz << 1) - 1, false);
          this->lazyFlag.resize((this->sz << 1) - 1, false);
     }
     void update(int l, int r, T val) {
          this->update(0, sz, l, r, 0, val);
     }
     T query(int l, int r) {
          return this->query(0, sz, l, r, 0);
     }
};

struct st {
    LL S, T, X;
    bool operator<(const st &other) const {
        return X < other.X;
    }

    PLL calc_range() const {
        const auto left = S - X;
        const auto right = T - X;
        return {left, right};
    }
};

const int MAX = 2e5 + 10;
int N, Q;
st in[MAX]; // S[i] <= foo && foo < T[i]
LL D[MAX];
LL rev[MAX * 3];

map<LL, int> mp;
range_update_query_minmax<LL> seg(MAX * 3);

int main(void) {
    scanf("%d%d", &N, &Q);
    REP(i, N) {
        scanf("%lld%lld%lld", &in[i].S, &in[i].T, &in[i].X);
    }
    sort(in, in + N);
    reverse(in, in + N);
    // REP(i, N) {
    //     DEBUG(in[i].X)
    //     DEBUG(in[i].calc_range().first)
    //     DEBUG(in[i].calc_range().second)
    // }
    REP(i, Q) {
        scanf("%lld", D + i);
    }


    {
        set<LL> se;
        REP(i, N) {
            se.emplace(in[i].calc_range().first);
            se.emplace(in[i].calc_range().second);
        }
        REP(i, Q) {
            se.emplace(D[i]);
        }
        int idx = 0;
        FORE(e, se) {
            mp[e] = idx;
            rev[idx] = e;
            idx++;
        }
    }

    //FORE(e, mp) cerr << e.first << " " << e.second << endl;cerr<<endl;

    REP(i, N) {
        const auto range = in[i].calc_range();
        const int l = mp[range.first];
        const int r = mp[range.second];
        //cerr << l << " " << r << " " << in[i].X << endl;
        seg.update(l, r, in[i].X);
    }

    //int idx = 0;
    REP(i, Q) {
        const auto tmp = mp[D[i]];
        LL ans = seg.query(tmp, tmp + 1);
        //DEBUG(ans)
        if (ans >= INF) ans = -1;
        printf("%lld\n", ans);
    }
}
