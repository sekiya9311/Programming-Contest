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
#define RREP(i, a) for(int (i) = (a)-1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a)-1; (i) >= (b); (i)--)
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
#define ALL(a) ((a).begin(), (a).end())
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define MP make_pair
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, e) (s.find(e) != s.end())

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF+7;
const LL LLINF = 1e18;

int main(void) {
    string s;
    cin >> s;
    if (s.size() < 26) {
        cout << -1 << endl;
        return 0;
    }
    map <char, int> mp_buf;
    REP(i, 26) mp_buf['A' + i] = 0;
    REP(i, s.size() - 25) {
        auto mp = mp_buf;
        int qcnt = 0;
        string sbuf = "";
        FOR(j, i, i + 26) {
            if (s[j] == '?') {
                qcnt++;
            } else {
                mp[s[j]]++;
            }
        }
        int zcnt = 0;
        bool f = true;
        FORE(el, mp) {
            if (el.second == 0) {
                zcnt++; sbuf += el.first;
            }
            if (el.second >=2) {
                f = false; break;
            }
        }
        if (!f) continue;
        if (zcnt == qcnt) {
            REP(j, s.size()) {
                if (s[j] == '?') {
                    if (i <= j && j <= i + 25) {
                        s[j] = sbuf.back();
                        sbuf.pop_back();
                    } else {
                        s[j] = 'A';
                    }
                }
            }
            cout << s << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
