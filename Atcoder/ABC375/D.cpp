#include <bits/stdc++.h>

using namespace std;

long long cnt1[26];
long long cnt2[26];

int main() {
    string S;
    cin >> S;
    for (char c : S) {
        cnt1[c - 'A']++;
    }

    long long ans = 0;
    for (char c : S) {
        cnt1[c - 'A']--;
        for (int i = 0; i < 26; i++) {
            ans += cnt1[i] * cnt2[i];
        }
        cnt2[c - 'A']++;
    }

    cout << ans << endl;
}
