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

char C[] = {'I', 'O', 'T', 'J', 'L', 'S', 'Z'};

LL func1(map<char, LL> mp) {
    LL ans = mp['O'];


    LL buf = mp['I'] / 2;
    ans += (buf) * 2;
    buf = mp['L'] / 2;
    ans += (buf) * 2;
    buf = mp['J'] / 2;
    ans += (buf) * 2;
    mp['I'] %= 2;
    mp['L'] %= 2;
    mp['J'] %= 2;



    return ans;
}
LL func2(map<char, LL> mp) {
    LL ans = mp['O'];

    if (mp['I'] > 0 && mp['L'] > 0 && mp['J'] > 0) {
        mp['I'] --;
        mp['J'] --;
        mp['L'] --;
        ans += 3;
    }
    LL buf = mp['I'] / 2;
    ans += (buf) * 2;
    buf = mp['L'] / 2;
    ans += (buf) * 2;
    buf = mp['J'] / 2;
    ans += (buf) * 2;
    mp['I'] %= 2;
    mp['L'] %= 2;
    mp['J'] %= 2;



    return ans;
}

int main(void) {
    map<char, LL> mp;
    REP(i, 7) {
        LL buf;
        scanf("%lld", &buf);
        mp[C[i]] = buf;
    }

    cout << max(func1(mp), func2(mp))<< endl;
}
