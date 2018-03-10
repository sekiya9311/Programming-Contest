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
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX = 300010;
int N;
int A[MAX], P[MAX];

class BinaryTrie {
    const static int NEXT_SIZE = 2;
    class Node {
    public:
        int cnt = 0;
        Node *nxt[NEXT_SIZE];
        Node() {
            nxt[0] = nxt[1] = nullptr;
        }
    };
    Node root;
    public:
    BinaryTrie() {
        root = Node();
    }
    void add(int val, int deg = 29, Node* now = nullptr) {
        if (now == nullptr) now = &root;
        if (deg == -1) {
            now->cnt++;
            return;
        }
        int nxt = !!(val & (1 << deg));
        if (now->nxt[nxt] == nullptr) now->nxt[nxt] = new Node();
        add(val, deg - 1, now->nxt[nxt]);
    }
    bool remove(int val, int deg = 29, Node* now = nullptr) {
        if (now == nullptr) now = &root;
        if (deg == -1) {
            now->cnt--;
            return now->cnt == 0;
        }
        int nxt = !!(val & (1 << deg));
        if (remove(val, deg - 1, now->nxt[nxt])) {
            now->nxt[nxt] = nullptr;
            if (now->nxt[nxt ^ 1] == nullptr) {
                return true;
            }
        }
        return false;
    }
    int get(int val, int deg = 29, Node* now = nullptr) {
        if (now == nullptr) now = &root;
        if (deg == -1) return 0;
        int nxt = !!(val & (1 << deg));
        if (now->nxt[nxt] == nullptr) nxt ^= 1;
        return get(val, deg - 1, now->nxt[nxt]) | (nxt << deg);
    }
};

BinaryTrie trie;

int main(void) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", A + i);
    REP(i, N) scanf("%d", P + i);
    REP(i, N) trie.add(P[i]);
    REP(i, N) {
        int val = trie.get(A[i]);
        printf("%d%c", (val ^ A[i]), (i + 1 == N ? '\n' : ' '));
        trie.remove(val);
    }
}
