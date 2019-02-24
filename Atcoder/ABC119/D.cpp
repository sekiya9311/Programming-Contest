#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<long long> s(A), t(B), x(Q);
    for (int i = 0; i < A; i++) {
        cin >> s[i];
    }
    sort(begin(s), end(s));
    for (int i = 0; i < B; i++) {
        cin >> t[i];
    }
    sort(begin(t), end(t));
    for (int i = 0; i < Q; i++) {
        cin >> x[i];
    }

    for (auto start: x) {
        auto s_l = lower_bound(begin(s), end(s), start);
        auto s_r = upper_bound(begin(s), end(s), start);
        auto t_l = lower_bound(begin(t), end(t), start);
        auto t_r = upper_bound(begin(t), end(t), start);

        if (s_l != begin(s)) s_l--;
        if (t_l != begin(t)) t_l--;
        if(s_l == end(s)) s_l--;
        if(t_l == end(t)) t_l--;
        if (t_r == end(t)) t_r--;
        if (s_r == end(s)) s_r--;

        // cerr<<*s_l<<endl;
        // cerr<<*s_r<<endl;
        // cerr<<*t_l<<endl;
        // cerr<<*t_r<<endl;

        long long ans = (long long)1e18;
        for (auto cur_s: {*s_l, *s_r}) {
            for (auto cur_t: {*t_l, *t_r}) {
                auto foo1 = upper_bound(begin(t), end(t), cur_s);
                auto foo2 = upper_bound(begin(s), end(s), cur_t);
                auto foo3 = lower_bound(begin(t), end(t), cur_s);
                auto foo4 = upper_bound(begin(s), end(s), cur_t);
                if (foo3 != begin(t)) foo3--;
                if (foo4 != begin(s)) foo4--;
                if (foo1 == end(t)) foo1--;
                if (foo2 == end(s)) foo2--;
                if (foo3 == end(t)) foo3--;
                if (foo4 == end(s)) foo4--;
                ans = min(
                    ans,
                    min(
                        abs(start - cur_s) + min({abs(cur_s - *lower_bound(begin(t), end(t), cur_s)), abs(cur_s - *foo1), abs(cur_s - *t_l), abs(cur_s - *t_r)}),
                        abs(start - cur_t) + min({abs(cur_t - *lower_bound(begin(s), end(s), cur_t)), abs(cur_t - *foo2), abs(cur_t - *s_l), abs(cur_t - *s_r)})
                    )
                );
            }
        }
        cout << ans << endl;
    }
}
