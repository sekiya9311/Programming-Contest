#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    long double ans = 0;
    long long cx = 0, cy = 0;
    for (int i = 1; i <= N; i++) {
        long long x, y;
        cin >> x >> y;
        ans += sqrtl(powl(cx - x, 2) + powl(cy - y, 2));
        cx = x;
        cy = y;
    }
    ans += sqrtl(powl(cx, 2) + powl(cy, 2));

    cout << setprecision(16) << ans << endl;
}
