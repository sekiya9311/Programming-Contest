#include <bits/stdc++.h>
 
#define DEBUG(C) cerr << #C << " = " << C << endl
 
using namespace std;
 
class FenwickTree {
private:
  vector<int> bit;
public:
  FenwickTree(int n) {
    bit.resize(n + 1);
  }
  void add(int idx, int val) {
    ++idx;
    while (idx < bit.size()) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }
  int sum(int idx) {
    ++idx;
    int res = 0;
    while (idx > 0) {
      res += bit[idx];
      idx -= idx & -idx;
    }
    return res;
  }
  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};
 
const int MAX = 1e5 + 10;
int R, C, N;
vector<pair<int, int>> v;
map<int, int> cmp;
 
inline int calc(int x, int y) {
  if (x == 0) return y;
  else if (y == C) return C + x;
  else if (x == R) return C + R + C - y;
  else if (y == 0) return C + R + C + R - x;
  else return -1;
}
 
int main() {
  scanf("%d%d%d", &R, &C, &N);
  set<int> se;
  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int buf1 = calc(x1, y1);
    int buf2 = calc(x2, y2);
    if (buf1 != -1 && buf2 != -1) {
      if (buf1 > buf2) {
        swap(buf1, buf2);
      }
      se.emplace(buf1);
      se.emplace(buf2);
      se.emplace(buf2 + 1);
      v.emplace_back(make_pair(buf1, buf2));
    }
  }
  int cnt = 0;
  for (auto &&e : se) {
    cmp[e] = cnt++;
  }
  FenwickTree bit(cnt);
  for (auto &&p : v) {
    bit.add(cmp[p.first], 1);
    bit.add(cmp[p.second + 1], -1);
  }
  for (auto &&p : v) {
    if (bit.sum(cmp[p.first]) != bit.sum(cmp[p.second])) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
