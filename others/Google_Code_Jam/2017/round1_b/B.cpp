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
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const string S = "ROYGBV";
const string S2 = "OGV";
const string S3 = "BRY";
bool chk(char now, char next) {
    switch (now) {
    case 'R':
        return next == 'Y' || next == 'G' || next == 'B';
    case 'B':
        return next == 'R' || next == 'Y' || next == 'O';
    case 'Y':
        return next == 'B' || next == 'R' || next == 'V';
    case 'O':
        return next == 'B';
    case 'G':
        return next == 'R';
    case 'V':
        return next == 'Y';
    default:
        assert(false);
    }
}

bool check(const string &ans) {
    REP(i, ans.size() * 2) {
        if (!chk(ans[i % ans.size()], ans[(i + 1) % ans.size()])) {
            return false;
        }
    }
    return true;
}
// S3 + S2 + S3
void solve(int testNum) {
    map<string, int> mp, mp2;
    int N;
    scanf("%d", &N);
    FORE(e, S) {
        int buf; scanf("%d", &buf);
        mp[string(1, e)] = buf;
    }

    string ans;

    REP(i, 3) {
        if (mp[string(1, S2[i])] && mp[string(1, S2[i])] > mp[string(1, S3[i])]) {
            ans = "IMPOSSIBLE";
        } else {
            mp[string(1, S3[i])] -= mp[string(1, S2[i])];
            mp2[string(1, S2[i])] = mp[string(1, S2[i])];
            mp.erase(string(1, S2[i]));
        }
    }
    if (ans != "IMPOSSIBLE") {
        priority_queue<pair<int, string>> pq;
        int len = 0;
        FORE(e, mp) {
            pq.push(MP(e.second, e.first));
            len += e.second;
        }
        ans = string(len, ' ');
        int now = 0;
        auto p = pq.top(); pq.pop();
        if (p.first * 2 <= len) {
            REP(i, p.first) {
                ans[now] = p.second[0];
                now += 2;
            }
            if (!pq.empty()) {
                p = pq.top(); pq.pop();
                REP(i, p.first) {
                    if (now >= len) now = 1;
                    ans[now] = p.second[0];
                    now += 2;
                }
            }
            if (!pq.empty()) {
                p = pq.top(); pq.pop();
                REP(i, p.first) {
                    if (now >= len) now = 1;
                    ans[now] = p.second[0];
                    now += 2;
                }
            }
            REP(i, 3) if (mp2.count(string(1, S2[i]))) {
                int num = mp2[string(1, S2[i])];
                string buf = string(1, S3[i]);
                while (num) {
                    if (buf.back() == S2[i]) buf += S3[i];
                    else {
                        buf += S2[i];
                        --num;
                    }
                }
                if (mp2[string(1, S2[i])]) {
                    bool f = false;
                    REP(j, ans.size()) {
                        if (ans[j] == S3[i]) {
                            ans = ans.substr(0, j) + buf + ans.substr(j);
                            f = true;
                            break;
                        }
                    }
                    if (!f) {
                        if (ans.size() == 0) {
                            ans += buf;
                        } else {
                            if (chk(ans.back(), buf.front())) {
                                ans += buf;
                            } else {
                                ans = buf + ans;
                            }
                        }
                    }
                }
            }
        } else {
            ans = "IMPOSSIBLE";
        }
    }
    if (ans != "IMPOSSIBLE") {
        if (!check(ans)) {
            ans = "IMPOSSIBLE";
        }
    }
    cout << "Case #" << testNum << ": " << ans << endl;
}

int main(void) {
    if (freopen("out.txt", "w", stdout) == NULL) {
        cerr << "file open failed" << endl;
        exit(1);
    }
	int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        cerr << "Case #" << testNum << ": solved" << endl;
    }
}
