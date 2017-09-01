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
using PDD = pair<long double, long double>;
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

const int MAX = 1111;
int n;
LL y[MAX];
PDD memo[MAX][MAX];
bool v[MAX][MAX];
const PDD ini = MP(LLINF, LLINF);

PDD calc(PLL a, PLL b) {
    PDD res;
    res.first = (b.second - a.second) / (b.first - a.first);
    res.second = a.second - res.first * a.first;
    return res;
}

// int main(void) {
//     cin >> n;
//     REP(i, n) {
//         cin >> y[i];
//     }
//     REP(i, n) {
//         FOR(j, i + 1, n) {
//             memo[i][j] = memo[j][i] = calc(MP(i, y[i]), MP(j, y[j]));
//         }
//     }
//     map<PDD, unordered_set<int>> mp;
//     FOR(i, 1, n) {
//         mp[memo[0][i]].emplace(i);
//         v[0][i] = true;
//     }
//     if (mp.size() == 1) {
//         cout << "No" << endl;
//         return 0;
//     }
//     REP(i, n) {
//         PDD p = ini;
//         int idx = -1;
//         bool ok = true;
//         REP(j, n) if (i != j) {
//             if (idx == -1) idx = j;
//             else {
//                 PDD buf = calc(MP(idx, y[idx]), MP(j, y[j]));
//                 if (p == ini) p = buf;
//                 else if (p != buf) {
//                     ok = false;
//                     break;
//                 }
//             }
//         }
//         if (ok) {
//             cout << "Yes" << endl;
//             return 0;
//         }
//     }
//     FORE(e, mp) {
//         const PDD p1 = e.first;
//         const unordered_set<int> se = e.second;
//         PDD p2 = ini;
//         int idx = -1;
//         bool ok = true;
//         FOR(i, 1, n) {
//             if (se.count(i) == 0) {
//                 if (idx == -1) {
//                     idx = i;
//                 } else {
//                     PDD buf = calc(MP(idx, y[idx]), MP(i, y[i]));
//                     if (p2 == ini) p2 = buf;
//                     else if (p2 != buf) {
//                         ok = false;
//                         break;
//                     }
//                 }
//             }
//         }
//         if (ok && p1.first == p2.first) {
//             cout << "Yes" << endl;
//             return 0;
//         }
//     }
//     cout << "No" << endl;
// }

long double katamuki(int a, int b) {
    return 1. * (y[b] - y[a]) / (b - a);
}

int main() {
    cin >> n;
    REP(i, n) {
        cin >> y[i];
    }
    map<long double, unordered_set<int>> mp;
    REP(i, n) {
        int idx = -1;
        REP(j, n) if (i != j) {
            if (idx == -1) idx = j;
            else {
                mp[katamuki(idx, j)].insert(i);
            }
        }
        if (mp.size() == 2) {
            FORE(e, mp) {
                if (e.second.size() == n - 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        mp.clear();
    }
    FOR(i, 1, n) {
        mp[katamuki(0, i)].insert(i);
    }
    if (mp.size() == 1) {
        cout << "No" << endl;
        return 0;
    }
    FORE(e, mp) {
        auto se = e.second;
        auto num = e.first;
        int idx = -1;
        bool ok = true;
        FOR(i, 1, n) if (se.count(i) == 0) {
            if (idx == -1) {
                idx = i;
            } else {
                if (katamuki(idx, i) != num) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << "Yes"  << endl;
            return 0;
        }
    }
    set<long double> se2;
    FOR(i, 2, n) {
        se2.insert(katamuki(1, i));
    }
    if (se2.size() == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
