#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for_each(begin(B), end(B), [](auto &e) {
        cin >> e;
    });
    vector<vector<int>> A(N, vector<int>(M));
    for_each(begin(A), end(A), [](auto &a) {
        for_each(begin(a), end(a), [](auto &e) {
            cin >> e;
        });
    });

    int ans = 0;
    for (auto a : A) {
        int sum = C;
        for (int i = 0; i < M; i++) {
            sum += a[i] * B[i];
        }
        if (sum > 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
