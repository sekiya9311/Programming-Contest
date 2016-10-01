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

bool comp(const string& left, const string& right) {
    return left.size() < right.size();
}

void out(const vector <string>& v) {
    FORE(el, v) cout << el << endl;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    vector <string> ps(n);
    REP(i, n) cin >> ps[i];
    string vps; cin >> vps;
    int mintime = 0, maxtime = 0;
    int time = 0;
    sort(ALL(ps), comp);
    int cnt = 0;
    bool f = false;
    REP(i, n) {
        if (ps[i].size() < vps.size()) {
            cnt++; time++;
            if (cnt == k) {
                time += 5; cnt = 0;
            }
        } else if (ps[i].size() == vps.size()) {
            time++; cnt++;
            if (!f) {
                mintime = time;
            }
            f = true;
            if (i == n - 1) {
                maxtime = time;break;
            }
            if (cnt == k) {
                time += 5; cnt = 0;
            }
        } else {
            if (cnt) maxtime = time;
            else maxtime = time - 5;
            break;
        }
    }
    cout << mintime << " " << maxtime << endl;
}
