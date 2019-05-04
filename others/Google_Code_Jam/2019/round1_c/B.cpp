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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

char ask(int ptr) {
    cout << ptr + 1 << endl;
    string str;
    cin >> str;
    return str.front();
}

void answer(string ans) {
    cout << ans << endl;
    string str;
    cin >> str;
}

void solve(int testNum, int F) {
    const int MAX = 600;
    const int N = 5;

    string ans = "";
    // 1
    set<int> need_idx;
    REP(i, MAX - 5) {
        need_idx.emplace(i);
    }

    {
        map<char, set<int>> char_to_idx;
        FORE(e, need_idx) if (e % N == 0) {
            // 119 loops
            auto res = ask(e);
            char_to_idx[res].emplace(e);
        }
        FORE(e, char_to_idx) {
            if (e.second.size() == 23) {
                REP(i, 119) {
                    if (e.second.count(i * N) == 0) {
                        REP(j, N) {
                            need_idx.erase(i * N + j);
                        }
                    }
                }

                ans += e.first;
                break;
            }
        }
    }

    {
        map<char, set<int>> char_to_idx;
        FORE(e, need_idx) if (e % N == 1) {
            // 23 loops
            auto res = ask(e);
            char_to_idx[res].emplace(e);
        }
        FORE(e, char_to_idx) {
            if (e.second.size() == 5) {
                REP(i, 119) {
                    if (e.second.count(i * N + 1) == 0) {
                        REP(j, N) {
                            need_idx.erase(i * N + j);
                        }
                    }
                }

                ans += e.first;
                break;
            }
        }
    }
    
    {
        map<char, set<int>> char_to_idx;
        FORE(e, need_idx) if (e % N == 2) {
            // 5 loops
            auto res = ask(e);
            char_to_idx[res].emplace(e);
        }
        FORE(e, char_to_idx) {
            if (e.second.size() == 1) {
                REP(i, 119) {
                    if (e.second.count(i * N + 2) == 0) {
                        REP(j, N) {
                            need_idx.erase(i * N + j);
                        }
                    }
                }

                ans += e.first;
                break;
            }
        }
    }

    {
        map<char, set<int>> char_to_idx;
        FORE(e, need_idx) if (e % N == 3) {
            // 1 loop
            auto res = ask(e);
            for (char c = 'A'; c <= 'E'; c++) {
                if (res != c && ans.find(c) == string::npos) {
                    ans += c;
                    ans += res;
                    break;
                }
            }
        }
    }

    answer(ans);
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }
    int problemnum, F;
    scanf("%d%d", &problemnum, &F);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum, F);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
