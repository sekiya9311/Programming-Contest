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

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for (int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for (int (i) = (a) - 1; (i) >= (b); (i)--)
#define PI acos(-1.0)
#define DEBUG(C) cout<< C <<endl;
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
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, n) (s.find(n) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;

void func2(PII ta, LL &t, LL &a) {
    LL mint = t, mina = a;
    LL tt, aa, ttt, aaa;
    tie(ttt, aaa) = ta;
    while (mint > tt || mina > aa) {
        tt += ttt; aa += aaa;
    }
    t = tt; a = aa;
}

void func3(PII ta, LL &t, LL &a) {
    LL mint = t, mina = a;
    LL tt, aa, ttt, aaa;
    tie(ttt, aaa) = ta;
    LL kake = max(mina / aaa, mint / ttt);
    bool f = (mina % aaa) || (mint % ttt);
    tt = ttt * (kake);
    aa = aaa * (kake);
    if (tt < mint || aa < mina) {
        tt += ttt;
        aa += aaa;
    }
    t = tt; a = aa;
}

int main(void) {
    LL N; cin >> N;
    VPII ta(N);
    REP(i, N) {
        int t, a;
        scanf("%d%d", &t, &a);
        ta[i] = MP(t, a);
    }
    LL t, a;
    tie(t, a) = ta[0];
    FOR(i, 1, N) {
        //cerr << t << " " << a << endl;
        if (ta[i].first >= t && ta[i].second >= a) {
            tie(t, a) = ta[i];
        } else if (ta[i] == MP(1, 1)) {
            t = max(t, a);
            a = t;
        } else {
            func3(ta[i], t, a);
        }
    }
    cout << t + a << endl;
}
