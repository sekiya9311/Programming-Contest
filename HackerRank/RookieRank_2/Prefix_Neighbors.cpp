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
const long double EPS = 1e-9;

template<typename T, char Key>
class Trie {
public:
    struct Node {
        Node *nxt[26];
        T w = 0;
        Node() {
            for (int i = 0; i < 26; i++) {
                nxt[i] = nullptr;
            }
        }
    };
    Trie() {
        root = Node();
    }
    Node* getRoot() {return this->root;}
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
    void insert(const std::vector<std::pair<T, std::string>>& v) {
        for (std::pair<T, std::string> &&p : v) {
            insert(p.second, p.first);
        }
    }
    T search(const std::string& str) {
        Node *now;
        now = &this->root;
        for (const char c : str) {
            if (now->nxt[c - Key] == nullptr) return 0;
            now = now->nxt[c - Key];
        }
        return now->w;
    }
    void nowNodeReset() {
        nowNode = &this->root;
    }
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

LL calcScore(string s) {
    LL res = 0;
    FORE(e, s) res += e;
    return res;
}

bool comp(const string &l, const string &r) {
    return calcScore(l) > calcScore(r);
}

const int MAX = 4 * 1e5 + 10;
int n;
Trie<LL, 'A'> trie;
char strbuf[20];
string S[MAX];

int main(void) {
    cin >> n;
    REP(i, n) {
        scanf("%s", strbuf);
        S[i] = strbuf;
    }
    sort(S, S + n, comp);
    LL ans = 0;
    REP(i, n) {
        trie.nowNodeReset();
        bool ok = false;
        FORE(e, S[i]) {
            LL buf = trie.nowNodeSearch(e);
            if (buf == -1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans += calcScore(S[i]);
            trie.insert(S[i], 1);
        }
    }
    cout << ans << endl;
}
