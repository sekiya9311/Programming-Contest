#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<pair<long long, int>> shops(N);
    for_each(begin(shops), end(shops), [](auto &shop) {
        cin >> shop.first >> shop.second;
    });
    sort(begin(shops), end(shops));

    long long ans = 0;
    int i = 0;
    while (M > 0) {
        if (shops[i].second < M) {
            ans += shops[i].first * shops[i].second;
            M -= shops[i].second;
        } else {
            ans += shops[i].first * M;
            M = 0;
        }
        i++;
    }
    cout << ans << endl;
}
