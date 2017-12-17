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

template<typename T, char Key>
class Trie {
public:
    const static int nxt_size = 2;
    struct Node {
        Node *nxt[nxt_size];
        T w = 0;
        Node() {
            for (int i = 0; i < nxt_size; i++) {
                nxt[i] = nullptr;
            }
        }
    };
    Trie() {
        root = Node();
    }
    Node* getRoot() {return &this->root;}
    //文字列strを追加
    void insert(const std::string& str, T cost) {
        Node *now;
        now = &this->root;
        for (const char c : str) {
            if (now->nxt[c - Key] == nullptr) {
                now->nxt[c - Key] = new Node();
            }
            now = now->nxt[c - Key];
        }
        now->w = cost;
    }
    //(重み, 文字列)のペアを持った配列を追加
    void insert(const std::vector<std::pair<T, std::string>>& v) {
        for (std::pair<T, std::string> &&p : v) {
            insert(p.second, p.first);
        }
    }
    //文字列strの探索，存在していたら重みを返す
    T search(const std::string& str) {
        Node *now;
        now = &this->root;
        for (const char c : str) {
            if (now->nxt[c - Key] == nullptr) {
                return 0;
            }
            now = now->nxt[c - Key];
        }
        return now->w;
    }
    //nowNodeSearch関数で現在見てるノードをrootでリセット
    void nowNodeReset() {
        nowNode = &this->root;
    }
    //nowNodeからchar変数cの探索，あったらnowNode更新
    T nowNodeSearch(const char& c) {
        if (nowNode->nxt[c - Key] == nullptr) {
            return errorRetNum;
        }
        nowNode = nowNode->nxt[c - Key];
        return nowNode->w;
    }
private:
    Node root;
    Node *nowNode;
    const T errorRetNum = -1;
};

const int MAX = 1e5 + 10;
char strbuf[MAX];
string next() {
    scanf("%s", strbuf);
    return strbuf;
}
int N;
LL L;
string s[MAX];
Trie<int, '0'> trie;
VL nim;

// struct Node {
//     Node *nxt[nxt_size];
//     T w = 0;
//     Node() {
//         for (int i = 0; i < nxt_size; i++) {
//             nxt[i] = nullptr;
//         }
//     }
// };

LL dfs(Trie<int, '0'>::Node *now, int rank = 0) {
    REP(i, 2) {
        if (now->nxt[i] != nullptr) {
            dfs(now->nxt[i], rank + 1);
        } else {
            if (L - rank == 0) {
                continue;
            }
            for (int b = 0; ; b++) {
                if ((L - rank) & (1LL << b)) {
                    nim.EB(1LL << b);
                    break;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    scanf("%d%lld", &N, &L);
    int maxL = 0;
    REP(i, N) {
        s[i] = next();
        trie.insert(s[i], 1);
    }
    dfs(trie.getRoot());
    LL buf = 0;
    for_each(ALL(nim), [&](LL e) {buf ^= e;});
    cout << (buf ? "Alice" : "Bob") << endl;
}
