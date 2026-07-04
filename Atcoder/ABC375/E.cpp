#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 111;
int N;
pair<int, int> P[MAX_V];
int dp[2][511][511];

int main() {
    cin >> N;
    int sum_s = 0;
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
        P[i].first--;
        sum_s += P[i].second;
    }

    if (sum_s % 3) {
        cout << -1 << endl;
        return 0;
    }
    const auto strong = sum_s / 3;

    const int INF = 1e9;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 511; j++) {
            for (int k = 0; k < 511; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 511; j++) {
            for (int k = 0; k < 511; k++) {
                dp[(i + 1) % 2][j][k] = INF;
            }
        }
        for (int j = 0; j < 511; j++) {
            for (int k = 0; k < 511; k++) {
                if (dp[i % 2][j][k] == INF) continue;
                if (j + P[i].second < 511) dp[(i + 1) % 2][j + P[i].second][k] = min(dp[(i + 1) % 2][j + P[i].second][k], dp[i % 2][j][k] + (P[i].first != 0));
                if (k + P[i].second < 511) dp[(i + 1) % 2][j][k + P[i].second] = min(dp[(i + 1) % 2][j][k + P[i].second], dp[i % 2][j][k] + (P[i].first != 1));
                dp[(i + 1) % 2][j][k] = min(dp[(i + 1) % 2][j][k], dp[i % 2][j][k] + (P[i].first != 2));
            }
        }
    }

    cout << (dp[N % 2][strong][strong] == INF ? -1 : dp[N % 2][strong][strong]) << endl;
}
