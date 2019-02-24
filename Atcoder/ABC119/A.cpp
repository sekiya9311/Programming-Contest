#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    if (s[5] == '0') {
        if (s[6] <= '4') cout << "Heisei" << endl;
        else cout << "TBD" << endl;
    } else {
        cout << "TBD" << endl;
    }
}
