#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    double ans = 0;
    for (int i = 0; i < N; i++) {
        double x;
        string u;
        cin >> x >> u;
        if (u == "JPY") ans += x;
        else ans += 380000 * x;
    }
    cout << fixed << setprecision(10) << ans << endl;
}
