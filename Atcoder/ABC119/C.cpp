#include <bits/stdc++.h>

using namespace std;

int cost[1 << 8][3];

int main(void) {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }
    for (int i = 1; i < (1 << N); i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) sum += l[j];
        }
        cost[i][0] = (__builtin_popcount(i) - 1) * 10 + abs(sum - A);
        cost[i][1] = (__builtin_popcount(i) - 1) * 10 + abs(sum - B);
        cost[i][2] = (__builtin_popcount(i) - 1) * 10 + abs(sum - C);
    }
    int ans = (int)1e9;
    for (int i = 1; i < (1 << N); i++) {
        for (int j = 1; j < (1 << N); j++) {
            for (int k = 1; k < (1 << N); k++) {
                if ((i & j) != 0 || (j & k) != 0 || (k & i) != 0) continue;
                ans = min(ans, cost[i][0] + cost[j][1] + cost[k][2]);
            }
        }
    }
    cout << ans << endl;
}
