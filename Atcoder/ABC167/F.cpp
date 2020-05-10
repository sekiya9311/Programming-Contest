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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

pair<int, int> calc(const string &s) {
    stack<char> st;
    FORE(c, s) {
        if (st.empty()) {
            st.emplace(c);
        } else if ((c == ')') && (st.top() == '(')) {
            st.pop();
        } else {
            st.emplace(c);
        }
    }

    pair<int, int> res = {0, 0};
    while (!st.empty()) {
        if (st.top() == '(') res.second++;
        else res.first++;
        st.pop();
    }
    return res;
}

int main(void) {
    int N;
    cin >> N;

    VPII dame;
    REP(i, N) {
        string s;
        cin >> s;
        const auto tmp = calc(s);
        if (tmp.first == 0 && tmp.second == 0) continue;
        
        dame.EB(tmp);
    }

    if (dame.empty()) {
        cout << "Yes" << endl;
        return 0;
    }
    int left_cand = -1, right_cand = -1;
    {
        REP(i, dame.size()) {
            if (dame[i].first == 0) {
                if (left_cand == -1 || dame[left_cand].second < dame[i].second)
                    left_cand = i;
            }
            if (dame[i].second == 0) {
                if (right_cand == -1 || dame[right_cand].first < dame[i].first)
                    right_cand = i;
            }
        }
        if (left_cand == -1 || right_cand == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    int cnt = 0;
    REP(i, dame.size()) {
        if (i == left_cand || i == right_cand)
            continue;
        cnt += dame[i].first - dame[i].second;
    }
DEBUG(cnt)
    if (cnt > 0) {
        // ) のが多い
        if (dame[left_cand].second < cnt) {
            cout << "No" << endl;
            return 0;
        }
    } else if (cnt < 0) {
        // ( のが多い
        if (dame[right_cand].first < -cnt) {
            cout << "No" << endl;
            return 0;
        }
    }

    VL left, right;
    FORE(p, dame) {
        left.EB(p.second);
        right.EB(p.first);
    }
    if (accumulate(ALL(left), 0LL) == accumulate(ALL(right), 0LL)) {

        if (dame.size() > 3) {
            int left_mi = -1, right_mi = -1;
            REP(i, dame.size()) if (i != left_cand && i != right_cand) {
                if (left_mi == -1 || dame[left_mi].second > dame[i].second)
                    left_mi = i;
                if (right_mi == -1 || dame[right_mi].first > dame[i].first)
                    right_mi = i;
            }
            if (left_mi == right_mi) {
                if (dame[left_cand].second > dame[right_cand].first) {
                    right_mi = -1;
                    REP(i, dame.size()) if (i != left_cand && i != right_cand && i != left_mi) {
                        if (right_mi == -1 || dame[right_mi].first > dame[i].first)
                            right_mi = i;
                    }
                } else {
                    left_mi = -1;
                    REP(i, dame.size()) if (i != left_cand && i != right_cand && i != right_mi) {
                        if (left_mi == -1 || dame[left_mi].second > dame[i].second)
                            left_mi = i;
                    }
                }
            }
            if (dame[left_cand].second < dame[right_mi].first) {
                cout << "No" << endl;
                return 0;
            }
            if (dame[right_cand].first < dame[left_mi].second) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            REP(i, 3) if (i != left_cand && i != right_cand) {
                if (dame[left_cand].second < dame[i].first) {
                    cout << "No" << endl;
                    return 0;
                }
                if (dame[right_cand].first < dame[i].second) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }

        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
