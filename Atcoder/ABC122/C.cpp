#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;
int N, Q;
string S;
int l[MAX], r[MAX];

int cnt[MAX];

int calc(int ll, int rr) {
    int ans = cnt[rr] - cnt[ll - 1];
    if (ll - 2 >= 0 && S[ll - 2] == 'A' && S[ll - 1] == 'C') {
        ans--;
    }
    return ans;
}

int main() {
    cin >> N >> Q;
    cin >> S;
    for (int i = 0; i < Q; i++) {
        cin >> l[i] >> r[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'A' && S[i + 1] == 'C') {
            cnt[i + 2] = 1;
        }
    }
    for (int i = 0; i < MAX - 1; i++) {
        cnt[i + 1] += cnt[i];
    }

    // cout << S << endl;
    // for (int i = 0; i < S.size() + 1; i++) {
    //     cout << (i) << ": " << cnt[i] << endl;
    // }

    for (int i = 0; i < Q; i++) {
        cout << calc(l[i], r[i]) << endl;
    }
}
