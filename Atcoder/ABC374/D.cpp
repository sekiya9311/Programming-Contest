#include <bits/stdc++.h>

using namespace std;

struct points {
    long double A, B, C, D;
};

int N;
long double S, T;
long double dp[11][2];

long double calc(long double a, long double b, long double c, long double d, bool shosya) {
    const auto base = shosya ? T : S;
    const auto dist = sqrtl((a - c) * (a - c) + (b - d) * (b - d));
    return dist / base;
}

int main() {
    cin >> N >> S >> T;
    vector<points> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].A >> v[i].B >> v[i].C >> v[i].D;
    }

    vector<int> iota_vec(N);
    for (int i = 0; i < N; i++) {
        iota_vec[i] = i;
    }

    long double ans = 1e18;

    do {

        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = 1e18;
            }
        }

        // 0: (A, B) -> (C, D)
        // 1: (C, D) -> (A, B)
        dp[0][0] = calc(0, 0, v[iota_vec[0]].A, v[iota_vec[0]].B, false) + calc(v[iota_vec[0]].A, v[iota_vec[0]].B, v[iota_vec[0]].C, v[iota_vec[0]].D, true);
        dp[0][1] = calc(0, 0, v[iota_vec[0]].C, v[iota_vec[0]].D, false) + calc(v[iota_vec[0]].C, v[iota_vec[0]].D, v[iota_vec[0]].A, v[iota_vec[0]].B, true);;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < 2; j++) {
                if (dp[i][j] >= 1e18) {
                    continue;
                }
                const auto preX = j ? v[iota_vec[i]].A : v[iota_vec[i]].C;
                const auto preY = j ? v[iota_vec[i]].B : v[iota_vec[i]].D;
                for (int k = 0; k < 2; k++) {
                    const auto curSX = k ? v[iota_vec[i + 1]].C : v[iota_vec[i + 1]].A;
                    const auto curSY = k ? v[iota_vec[i + 1]].D : v[iota_vec[i + 1]].B;
                    const auto curGX = k ? v[iota_vec[i + 1]].A : v[iota_vec[i + 1]].C;
                    const auto curGY = k ? v[iota_vec[i + 1]].B : v[iota_vec[i + 1]].D;
                    const auto cur = dp[i][j] + calc(preX, preY, curSX, curSY, false) + calc(curSX, curSY, curGX, curGY, true);
                    dp[i + 1][k] = min(dp[i + 1][k], cur);
                }
            }
        }

        ans = min(ans, min(dp[N - 1][0], dp[N - 1][1]));

    } while (next_permutation(begin(iota_vec), end(iota_vec)));

    cout << setprecision(16) << ans << "\n";
}
