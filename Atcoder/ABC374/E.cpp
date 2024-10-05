#include <bits/stdc++.h>

using namespace std;

const int MAX = 111;
int N;
long long A[MAX], B[MAX], P[MAX], Q[MAX];

long long calc_min(int i, long long w) {
    const auto l_cnt = A[i];
    const auto l_cost = P[i];
    const auto r_cnt = B[i];
    const auto r_cost = Q[i];

    assert(l_cost <= r_cost);

    if (l_cnt > r_cnt) {
        return l_cost * ((w + l_cnt - 1) / l_cnt);
    }

    const auto calc = [&](long long min_use_cnt) {
        const auto remain = w - min_use_cnt * l_cnt;
        const auto cur_r_cnt = max(0LL, (remain + r_cnt - 1) / r_cnt);
        return min_use_cnt * l_cost + cur_r_cnt * r_cost;
    };

    auto l = 0LL;
    auto r = (w + l_cnt - 1) / l_cnt;
    while (abs(l - r) > 1000) {
        const auto mid1 = (l + l + r) / 3;
        const auto mid2 = (l + r + r) / 3;
        const auto res1 = calc(mid1);
        const auto res2 = calc(mid2);
        if (res1 > res2) {
            l = mid1;
        } else {
            r = mid2;
        }
    }

    long long min_cost = 1e18;
    for (long long x = max(0LL, l - 500); x <= r + 500; x++) {
        min_cost = min(min_cost, calc(x));
    }
    return min_cost;
}

bool can(long long X, long long w) {
    for (int i = 0; i < N; i++) {
        X -= calc_min(i, w);
        if (X < 0) {
            return false;
        }
    }
    return X >= 0;
}

int main() {
    long long X;
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
        if (P[i] == Q[i]) {
            if (A[i] > B[i]) {
                swap(A[i], B[i]);
                swap(P[i], Q[i]);
            }
        } else if (P[i] > Q[i]) {
            swap(A[i], B[i]);
            swap(P[i], Q[i]);
        }
    }

    long long ok = 0, ng = 1e9 + 10;
    while (ng - ok > 1) {
        const auto mid = (ng + ok) / 2;
        if (can(X, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << "\n";
}
