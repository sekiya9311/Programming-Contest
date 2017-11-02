#include <bits/stdc++.h>
 
#define DEBUG(C) cerr << #C << " = " << C << endl
 
using namespace std;
 
template<typename T>
class BIT {
private:
  vector<T> bit;
public:
  BIT(const int n) : bit(n + 10) {}
  void add(int idx, T val) {
    ++idx;
    while (idx <= bit.size()) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }
  T get(int l, int r) {
    return this->get(r) - this->get(l - 1);
  }
  T get(int r) {
    ++r;
    T res = 0;
    while (r > 0) {
      res += bit[r];
      r -= r & -r;
    }
    return res;
  }
};
 
const int MAX = 2 * 1e5 + 10;
int N;
long long K, a[MAX], asum[MAX], asum2[MAX];
BIT<long long> bit(MAX);
 
int main() {
  scanf("%d%lld", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%lld", a + i);
    a[i] -= K;
    asum[i + 1] = asum[i] + a[i];
  }
  
  memcpy(asum2, asum, sizeof(asum));
  sort(asum2, asum2 + N + 1);
  map<long long, int> mp;
  for (int i = 0; i <= N; i++) {
    mp[asum2[i]] = i;
  }
  long long ans = 0;
  for (int i = 0; i <= N; i++) {
    ans += bit.get(mp[asum[i]]);
    bit.add(mp[asum[i]], 1);
  }
  
  printf("%lld\n", ans);
  return 0;
}
