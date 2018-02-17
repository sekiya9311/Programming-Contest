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

template<typename T = int>
class BIT {
private:
    std::vector<T> bit;
    const int N;
public:
    BIT() : N(-1) {}
    BIT(int n) : N(n), bit(n + 1, 0) {}
    //bit[point]にnum追加
    void add(int point, T num) {
        assert(N != -1 && 0 <= point && point <= N);
        point++;
        while (point <= N) {
            bit[point] += num;
            point += point & -point;
        }
    }
    //pointまでの値の和を返す
    T sum(int point) {
        assert(N != -1 && 0 <= point && point <= N);
        point++;
        T res = 0;
        while (point > 0) {
            res += bit[point];
            point -= point & -point;
        }
        return res;
    }
    //left から right の区間和
    T sum(int left, int right) {
        return this->sum(right) - this->sum(left - 1);
    }
};

const int MAX = 5e5 + 10;
int Q;
LL s[MAX];
map<LL, int> se;
unordered_map<LL, int> cnt;
unordered_map<LL, int> mp;
unordered_map<int, LL> revmp;
BIT<LL> bit(MAX);
BIT<int> bitCnt(MAX);

int main(void) {
    scanf("%d", &Q);
    REP(i, Q) {
        int x;
        scanf("%d", &x);
        if (x == 2) s[i] = -1;
        else {
            scanf("%lld", s + i);
            se[s[i]]++;
        }
    }
    {
        int ptr = 0;
        FORE(e, se) {
            mp[e.first] = ptr;
            revmp[mp[e.first]] = e.first;
            ptr += e.second;
        }
    }
    LL ma = 0;
    int maIdx = 0;
    int insCnt = 0;
    REP(i, Q) {
        if (s[i] != -1) {
            int idx = mp[s[i]] + cnt[s[i]];
            cnt[s[i]]++;
            bit.add(idx, s[i]);
            bitCnt.add(idx, 1);
            chmax(maIdx, idx);
            chmax(ma, s[i]);
            insCnt++;
        } else {
            int low = 0, high = maIdx - 1;
            while (high - low > 10) {
                const int mid1 = (high + low + low) / 3;
                const int mid2 = (high + low + high) / 3;
                if (1. * (bit.sum(mid1) + ma) / (bitCnt.sum(mid1) + 1) <= 1. * (bit.sum(mid2) + ma) / (bitCnt.sum(mid2) + 1)) {
                    high = mid2;
                } else {
                    low = mid1;
                }
            }
            double put = 0;
            FOR(i, low, high + 1) {
                chmax(put, ma - 1. * (bit.sum(i) + ma) / (bitCnt.sum(i) + 1));
            }
            printf("%.10lf\n", put);
        }
    }
}
