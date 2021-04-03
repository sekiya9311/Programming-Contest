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
#define GREATER(T) T, VT<T>, greater<T>
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

string next() {
    static char buf[(int)2e5 + 10];
    scanf("%s", buf);
    return buf;
}

int check(const string &S) {
    int cnt = 0;
    FORE(c, S) {
        if (c == '(') cnt++;
        else if (c == ')') cnt--;
    }
    return cnt;
}
bool check2(const string &S) {
    int cnt = 0;
    FORE(c, S) {
        if (c == '(') cnt++;
        else if (c == ')') cnt--;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

void solve2() {
    int N;
    scanf("%d", &N);
    const auto S = next();
    if (S.front() != '1' || S.back() != '1') {
        puts("NO");
        return;
    }
    const auto z_cnt = count_if(ALL(S), [](auto c) { return c == '0'; });
    if (z_cnt % 2) {
        puts("NO");
        return;
    }

    string A = "", B = "";
    int cnt = 0;
    {
        int c = 0;
        REP(i, N) {
            if (S[i] != '0') {
                A += '?';
                B += '?';
                continue;
            }
            A += (c % 2 ? '(' : ')');
            B += (c % 2 ? ')' : '(');
            c++;
        }
        cnt = c / 2;
    }



    REP(i, N) {
        if (A[i] == '?') {
            if (cnt < N / 2) {
                A[i] = '(';
                B[i] = '(';
            } else {
                A[i] = ')';
                B[i] = ')';
            }
            cnt++;
        }
    }


    if (!check2(A) || !check2(B)) {
        puts("NO");
        cerr << A << endl;
        cerr << B << endl;
        return;
    }

    puts("YES");
    puts(A.c_str());
    puts(B.c_str());
}

// 1001101101
// ()()()()()
// (())((()))

void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {

        solve2();

    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    const auto in_stream = freopen("../in.txt", "r", stdin);
    if (in_stream == nullptr) {
        cerr << "ERROR!" << endl;
        return 1;
    }
#endif

    solve();

#ifndef ONLINE_JUDGE
    fclose(in_stream);
#endif
}
