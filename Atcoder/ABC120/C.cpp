#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string S;
    cin >> S;
    int del = 0;
    stack<char> stk;
    for (int i = 0; i < S.size(); i++) {
        if (!stk.empty() && stk.top() != S[i]) {
            stk.pop();
            del++;
        } else {
            stk.emplace(S[i]);
        }
    }
    cout << del * 2 << endl;
}
