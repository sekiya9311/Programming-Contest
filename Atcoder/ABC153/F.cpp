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

// 区間加算，区間参照
template<typename T = int>
class range_add_query {
private:
     std::vector<T> data, lazy;
     int sz;
     void push(int k, int l, int r) {
          if (this->lazy[k]) {
               this->data[k] += this->lazy[k] * (r - l);
               if (k * 2 + 2 < sz * 2 - 1) {
                    this->lazy[2 * k + 1] += this->lazy[k];
                    this->lazy[2 * k + 2] += this->lazy[k];
               }
               this->lazy[k] = 0;
          }
     }
     void add(int l, int r, int L, int R, int k, T val) {
           this->push(k, l, r);
          if (L <= l && r <= R) {
               this->lazy[k] += val;
                  this->push(k, l, r);
          } else if (R <= l || r <= L) {
               return;
          } else if (r - l > 1) {
               const int mid = (l + r) / 2;
               this->add(l, mid, L, R, k * 2 + 1, val);
               this->add(mid, r, L, R, k * 2 + 2, val);
                  data[k] = data[k * 2 + 1] + data[k * 2 + 2];
          }
     }
     T query(int l, int r, int L, int R, int k) {
          this->push(k, l, r);
          if (L <= l && r <= R) {
               return data[k];
          } else if (R <= l || r <= L) {
               return 0;
          } else {
               const int mid = (l + r) / 2;
               const T left = this->query(l, mid, L, R, k * 2 + 1);
               const T right = this->query(mid, r, L, R, k * 2 + 2);
               return left + right;
          }
     }
public:
     range_add_query(const int n) {
          this->sz = 1;
          while (this->sz < n) {
              this->sz <<= 1;
          }
          this->data.resize(this->sz * 2 - 1);
          this->lazy.resize(this->sz * 2 - 1);
     }
     void add(int l, int r, T val) {
          this->add(0, this->sz, l, r, 0, val);
     }
     T query(int l, int r) {
          return this->query(0, this->sz, l, r, 0);
     }
};

const int MAX = 2e5 + 10;
int N;
LL D, A;
PLL m[MAX]; // <X, H>
LL X[MAX], H[MAX];
range_add_query<LL> tree(MAX);

int main(void) {
    cin >> N >> D >> A;
    REP(i, N) {
        cin >> m[i].first >> m[i].second;
    }
    sort(m, m + N);

    LL ans = 0;
    REP(i, N) {
        m[i].second -= tree.query(i, i + 1);
        if (m[i].second <= 0) continue;
        int ok = i, ng = N;
        while (ng - ok > 1) {
            const int mid = (ok + ng) / 2;
            if (m[mid].first - m[i].first <= D * 2) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        const auto cnt = (m[i].second + A - 1) / A;
        tree.add(i, ok + 1, cnt * A);
        ans += cnt;
    }

    cout << ans << endl;
}
