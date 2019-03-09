#include <bits/stdc++.h>

using namespace std;

long long naive_xor_sum(long long v) {
    long long ret = 0;
    for (int i = 0; i < 40; i++) {
        auto div = v / (1LL << i);
        auto mod = v % (1LL << i);
        long long cnt = div / 2 * (1LL << i);
        if (div % 2) {
            cnt += mod;
        }
        if (cnt % 2) {
            ret |= (1LL << i);
        }
    }
    return ret;
}

int main(void) {
    long long A, B;
    cin >> A >> B;
    cout << (naive_xor_sum(B + 1) ^ naive_xor_sum(A)) << endl;
}

// 00000
// 00001
// 00010
// 00011
// 00100
// 00101
// 00110
// 00111
// 01000
// 01001
// 01010
// 01011
// 01100
// 01101
// 01110
// 01111
// 10000
