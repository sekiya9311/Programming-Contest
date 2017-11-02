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
#include <chrono>

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
template<typename T>inline bool chmax(T &a, T b){return (a < b ? a = b, true : false);}
template<typename T>inline bool chmin(T &a, T b){return (a > b ? a = b, true : false);}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
const long double EPS = 1e-9;

const int MAX = 50;
int N;
string S[MAX], sub[MAX];
map<char, int> mp, chk;
map<string, int, greater<string>> cnt;

int main() {
	cin >> N;
	REP(i, N) {
		cin >> S[i];
		if (i == 0) FORE(e, S[i]) mp[e]++;
		else {
			FORE(e, S[i]) chk[e]++;
			if (mp != chk) {
				cout << -1 << endl;
				return 0;
			}
			chk.clear();
		}
	}
	int ans = INF;
	REP(i, N) {
		REP(j, N) sub[j] = S[j];
		int buf = 0;
		string key = S[i];
		bool dame = false;
		REP(j, N) {
			if (key == sub[j]) continue;
			do {
				++buf;
				sub[j] = sub[j].substr(1) + sub[j][0];
				if (sub[j] == S[j]) {
					dame = true;
					break;
				}
			} while (key != sub[j]);
		}
		if (!dame) chmin(ans, buf);
	}
	cout << (ans == INF ? -1 : ans) << endl;
}
