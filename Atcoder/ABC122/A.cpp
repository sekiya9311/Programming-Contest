#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    for (auto e : S) {
        if (e == 'A') cout << "T";
        if (e == 'T') cout << "A";
        if (e == 'C') cout << "G";
        if (e == 'G') cout << "C";
    }
}
