#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    string ans = "";
    string valid = "AGCT";
    for (int i = 0; i < S.size(); i++) {
        string pre = "";
        for (int j = i; j < S.size(); j++) {
            if (valid.find(S[j]) == string::npos) break;
            pre += S[j];
        }
        if (ans.size() < pre.size()) ans = pre;
    }
    cout << ans.size() << endl;
}
