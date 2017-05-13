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
#include <chrono>

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
const double EPS = 1e-9;

const int MAX = 3 * 1e5 + 10;
char strbuf[MAX];
string next() {
scanf("%s", strbuf);
return strbuf;
}
string S, T;
string ans = "";

int main() {
    S = next();
    T = next();
    int N = S.size();
    map<char, int> Scnt, Tcnt;
    FORE(e, S) Scnt[e]++;
    FORE(e, T) Tcnt[e]++;
    int Ssz = N / 2, Tsz = N / 2;
    if (N % 2) ++Ssz;
    auto itr1 = Scnt.rbegin();
    int sum = 0;
    while (Ssz != N - sum) {
        if (itr1->second == 0) {
            itr1++;
        }
        itr1->second--;
        sum++;
    }
    sum = 0;
    auto itr2 = Tcnt.begin();
    while (Tsz != N - sum) {
        if (itr2->second == 0) {
            itr2++;
        }
        itr2->second--;
        sum++;
    }
    REP(i, 26) {
        if (Scnt.count('a' + i) && Scnt['a' + i] == 0) Scnt.erase('a' + i);
        if (Tcnt.count('a' + i) && Tcnt['a' + i] == 0) Tcnt.erase('a' + i);
    }
    ans = string(N, ' ');
    int now = 0, backNow = N - 1;
    REP(i, N) {
        if (i % 2 == 0) {
            //最小
            auto itr = Scnt.begin();
            auto itr2 = Scnt.rbegin();
            if (Tcnt.empty() || itr->first < Tcnt.rbegin()->first) {
                while (ans[now] != ' ') ++now;
                ans[now++] = itr->first;
                itr->second--;
                if (itr->second == 0) Scnt.erase(itr->first);
            } else {
                //相手が持ってるのが全部自分のより小さい
                if (i + 1 == N) {
                    auto itr3 = itr;
                    while (ans[backNow] != ' ') --backNow;
                    ans[backNow--] = itr3->first;
                    itr3->second--;
                    if (itr3->second == 0) Scnt.erase(itr3->first);
                } else {
                    while (ans[backNow] != ' ') --backNow;
                    ans[backNow--] = itr2->first;
                    itr2->second--;
                    if (itr2->second == 0) Scnt.erase(itr2->first);
                }
            }
        } else {
            //最大
            auto itr = Tcnt.rbegin();
            auto itr2 = Tcnt.begin();
            if (Scnt.empty() || itr->first > Scnt.begin()->first || i + 1 == N) {
                while (ans[now] != ' ') ++now;
                ans[now++] = itr->first;
                itr->second--;
                if (itr->second == 0) Tcnt.erase(itr->first);
            } else {
                //相手が持ってるのが全部自分のより大きい
                if (i + 2 == N) {
                    auto itr3 = itr;
                    while (ans[backNow] != ' ') --backNow;
                    ans[backNow--] = itr3->first;
                    itr3->second--;
                    if (itr3->second == 0) Tcnt.erase(itr3->first);
                } else {
                    while (ans[backNow] != ' ') --backNow;
                    ans[backNow--] = itr2->first;
                    itr2->second--;
                    if (itr2->second == 0) Tcnt.erase(itr2->first);
                }
            }
        }
    }
    printf("%s\n", ans.c_str());
}
