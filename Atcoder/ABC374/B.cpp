#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    string T;
    cin >> S >> T;
    const int L = min(S.length(), T.length());
    for (int i = 0; i < L; i++) {
        if (S[i] != T[i]) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    if (S.length() == T.length()) {
        cout << 0 << "\n";
        return 0;
    }

    cout << L + 1 << "\n";
}
