#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int A, B, K;
    cin >> A >> B >> K;
    int cnt = 0;
    for (int i = min(A, B); ; i--) {
        cnt += (A % i == 0 && B % i == 0);
        if (cnt == K) {
            cout << i << endl;
            return 0;
        }
    }
}
