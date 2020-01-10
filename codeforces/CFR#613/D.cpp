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

// 二進Trie
class binary_trie {
    const static int NEXT_SIZE = 2;
    class node {
    public:
        int cnt = 0;
        node *nxt[NEXT_SIZE];
        node() {
            nxt[0] = nxt[1] = nullptr;
        }
    };
    node root;
    public:
    binary_trie() {
        root = node();
    }
    void add(int val, int deg = 30, node* now = nullptr) {
        if (now == nullptr) now = &root;
        if (deg == -1) {
            now->cnt++;
            return;
        }
        const int nxt = !!(val & (1 << deg));
        if (now->nxt[nxt] == nullptr) {
            now->nxt[nxt] = new node();
        }
        add(val, deg - 1, now->nxt[nxt]);
    }
    bool remove(int val, int deg = 30, node* now = nullptr) {
        if (now == nullptr) {
            now = &root;
        }
        if (deg == -1) {
            now->cnt--;
            return now->cnt == 0;
        }
        const int nxt = !!(val & (1 << deg));
        if (remove(val, deg - 1, now->nxt[nxt])) {
            now->nxt[nxt] = nullptr;
            if (now->nxt[nxt ^ 1] == nullptr) {
                return true;
            }
        }
        return false;
    }
    int get(int val, int deg = 30, node* now = nullptr) {
        // TODO
        return 0;
    }

    int calc(int cur = 0, int deg = 30, node* now = nullptr) {
        if (now == nullptr) now = &root;
        if (now->nxt[0] == nullptr && now->nxt[1] == nullptr) return cur;

        if (now->nxt[0] == nullptr) return calc(cur, deg - 1, now->nxt[1]);
        if (now->nxt[1] == nullptr) return calc(cur, deg - 1, now->nxt[0]);

        int res = INT_MAX;
        REP(i, 2) {
            chmin(res, calc(cur | (1 << deg), deg - 1, now->nxt[i]));
        }
        return res;
    }
};

const int MAX = 1e5 + 10;
int N;
int a[MAX];
binary_trie trie;



int main(void) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", a + i);

    REP(i, N) {
        trie.add(a[i]);
    }

    cout << trie.calc() << endl;
}
