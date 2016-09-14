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
#define EP emplace_back
#define FORE(a, b) for (auto &&a:b)
#define FIND(s, n) s.find(n) != s.end()

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MOD = INF + 7;

string make(LL num) {
    string res = "";
    REP(_, 18) {
        if ((num%10)%2) res += '1';
        else res += '0';
        num /= 10;
    }
    REVERSE(res);
    return res;
}
string degmake(string s) {
    while(s.size() != 18) {
        s = '0' + s;
    }
    return s;
}

int main(void) {
    int t;
    cin >> t;
    map <string, int> mp;
    REP(_, t) {
        char c, buf[20];
        scanf("%*c%c %s", &c, buf);
        //cout << c << " " << buf << endl;
        if (c == '+') {
            LL num = atoll(buf);
            mp[make(num)]++;
        }
        if (c == '-') {
            LL num = atoll(buf);
            mp[make(num)]--;
        }
        if (c == '?') {
            string sbuf = buf;
            cout << mp[degmake(sbuf)] << endl;
        }
    }
    return 0;
}
