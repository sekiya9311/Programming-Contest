#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> K(N);
    for (int i = 0; i < N; i++) {
        cin >> K[i];
    }

    const long long sum = accumulate(K.begin(), K.end(), 0LL);

    long long ans = 1e18;
    for (int i = 0; i < (1 << N); i++) {
        long long curA = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                curA += K[j];
            }
        }
        ans = min(ans, max(curA, sum - curA));
    }

    cout << ans << "\n";
}
