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

template<typename T = int>
class CumulativeSum2D {
private:
    std::vector<std::vector<T>> vec;
    std::vector<std::vector<T>> sum;
    bool invalid;
    int H, W;
public:
    CumulativeSum2D() {invalid = true;}
    CumulativeSum2D(const std::vector<std::vector<T>> &v) {
        init(v);
    }
    void init() {
        vec.clear();
        sum.clear();
        H = W = -1;
        invalid = true;
    }
    void init(const std::vector<std::vector<T>> &v) {
        init();
        invalid = false;
        H = v.size();
        W = v.front().size();
        std::copy(v.begin(), v.end(), std::back_inserter(vec));
        sum.resize(H + 1, std::vector<T>(W + 1, 0));
    }
    bool calcSum() {
        if (invalid) return false;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                sum[i + 1][j + 1] = vec[i][j];
            }
        }
        for (int i = 0; i < H + 1; i++) {
            for (int j = 0; j < W; j++) {
                sum[i][j + 1] += sum[i][j];
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W + 1; j++) {
                sum[i + 1][j] += sum[i][j];
            }
        }
        return true;
    }
    // [p1, p2)
    T getSum(std::pair<int, int> p1, std::pair<int, int> p2) {
        if (invalid) return 0;
        int h1, w1, h2, w2;
        std::tie(h1, w1) = p1; std::tie(h2, w2) = p2;
        h2--; w2--;
        return sum[h2 + 1][w2 + 1] - sum[h2 + 1][w1] - sum[h1][w2 + 1] + sum[h1][w1];
    }
    T getSum(int x1, int y1, int x2, int y2) {
        return this->getSum(std::make_pair(x1, y1), std::make_pair(x2, y2));
    }
    std::vector<std::vector<T>> getSumVec() {return sum;}
};

int R, C, H, V;
string S[111];
CumulativeSum2D<int> csum;
void solve(int testNum) {
    bool ok = false;
    int sum = 0;
    cin >> R >> C >> H >> V;
    const int cut = (H + 1) * (V + 1);
    {
        VVI vec(R, VI(C));
        REP(i, R) {
            cin >> S[i];
            REP(j, C) if (S[i][j] == '@') {
                vec[i][j] = 1;
                sum++;
            }
        }
        csum = CumulativeSum2D<int>(vec);
        csum.calcSum();
    }
    if (sum % cut == 0) {
        const int tate = sum / (V + 1);
        const int yoko = sum / (H + 1);
        const int piece = sum / cut;
        VI tateCut;
        int pre = 0;
        REP(j, C) {
            // V cut
            const int get = csum.getSum(MP(0, pre), MP(R, j + 1));
            if (get == tate || get == 0) {
                tateCut.EB(j + 1);
                pre = j + 1;
            } else if (get > tate || (j + 1 == C && get)) {
                tateCut.clear();
                break;
            }
        }
        if (tateCut.size() >= V + 1) {
            VI yokoCut;
            pre = 0;
            int tateZero = 0;
            REP(i, R) {
                // H cut
                const int get = csum.getSum(MP(pre, 0), MP(i + 1, C));
                if (get == yoko || get == 0) {
                    yokoCut.EB(i + 1);
                    pre = i + 1;
                } else if (get > yoko || (i + 1 == R && get)) {
                    yokoCut.clear();
                    break;
                }
            }
            if (yokoCut.size() >= H + 1) {
                ok = true;
                tateCut.emplace(tateCut.begin(), 0);
                yokoCut.emplace(yokoCut.begin(), 0);
                //FORE(i, tateCut) cerr << i << " ";cerr << endl;
                //FORE(i, yokoCut) cerr << i << " ";cerr << endl;
                REP(i, (int)tateCut.size() - 1) {
                    REP(j, (int)yokoCut.size() - 1) {
                        const int get = csum.getSum(MP(yokoCut[j], tateCut[i]), MP(yokoCut[j + 1], tateCut[i + 1]));
                        if (get != piece && get) {
                            ok = false;
                        }
                    }
                }
            }
        }
    }
    //if (sum == 0) ok = true;
    cout << "Case #" << testNum << ": " << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}

int main(void) {
    // if (freopen("out.txt", "w", stdout) == NULL) {
    //     cerr << "file open failed" << endl;
    //     exit(1);
    // }
    int problemnum;
    scanf("%d", &problemnum);
    //string s;getline(cin, s);
    for (int testNum = 1; testNum <= problemnum; testNum++) {
        solve(testNum);
        //cerr << "Case #" << testNum << ": solved" << endl;
    }
}
