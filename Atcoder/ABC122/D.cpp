#include <bits/stdc++.h>

using namespace std;

const int MAX = 111;
const int MOD = 1e9 + 7;
int N;
long long dp[MAX][4/*cur*/][4/*prev*/][4/*prev prev*/][4/*prev prev prev*/];
const string key = "AGCT";

// ACG
// AGC, GAC

bool check(string str) {
    if (str.find("AGC") != string::npos) return false;
    for (int i = 0; i < str.size() - 1; i++) {
        swap(str[i], str[i + 1]);
        if (str.find("AGC") != string::npos) return false;
        swap(str[i], str[i + 1]);
    }
    return true;
}

int main() {
    cin >> N;

    if (N == 3) {
        cout << 61 << endl;
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    string s = string(1,key[i]) + string(1,key[j]) + string(1,key[k]) + string(1,key[l]);
                    reverse(begin(s), end(s));
                    if (check(s)) {
                        dp[3][i][j][k][l] = 1;
                    }
                }
            }
        }
    }

    for (int i = 4; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 4; m++) {
                        for (int n = 0; n < 4; n++) {
                            string s = string(1, key[j])
                                     + string(1, key[k])
                                     + string(1, key[l])
                                     + string(1, key[m])
                                     + string(1, key[n]);
                            reverse(begin(s), end(s));
                            if (check(s)) {
                                (dp[i][j][k][l][m] += dp[i - 1][k][l][m][n]) %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    (ans += dp[N - 1][i][j][k][l]) %= MOD;
                }
            }
        }
    }
    cout << ans << endl;
}
