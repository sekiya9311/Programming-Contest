#include <bits/stdc++.h>

using namespace std;

// UnionFind,素集合データ構造,DisjointSet

template<typename weight_type = int>
class union_find {
    static_assert(
        std::is_arithmetic<weight_type>::value,
        "Invalid weight type");
private:
    std::vector<int> uni;
    std::vector<int> edge_count_;
    std::vector<weight_type> weights;
    int size_;
    const void check(const int n) const {
        if (this->group_size() < 0) {
            assert(false);
        }
        if (!(0 <= n && n < this->all_size())) {
            assert(false);
        }
    }
public:
    union_find() : uni(0), edge_count_(0), weights(0), size_(-1) {}
    union_find(const int n)
        : uni(n, -1), edge_count_(n), weights(n), size_(n) {
        this->check(n - 1);
    }
    union_find(const std::vector<weight_type> &_weights)
        : uni(_weights.size(), -1), edge_count_(_weights.size()),
        weights(_weights), size_(_weights.size()) {
        this->check((int)_weights.size() - 1);
    }
    bool same(const int a, const int b) {
        this->check(a);
        this->check(b);
        return this->find(a) == this->find(b);
    }
    int find(const int a) {
        this->check(a);
        return this->uni[a] < 0 ?
                a :
            this->uni[a] = this->find(this->uni[a]);
    }
    bool unite(int a, int b) {
        a = this->find(a);
        b = this->find(b);
        this->edge_count_[a]++;
        if (a == b) {
            return false;
        }
        this->size_--;
        if (this->uni[a] > this->uni[b]) {
            std::swap(a, b);
        }
        this->uni[a] += this->uni[b];
        this->weights[a] += this->weights[b];
        this->edge_count_[a] += this->edge_count_[b];
        this->uni[b] = a;
        return true;
    }
    const int group_size() const {
        return this->size_;
    }
    const int all_size() const {
        return this->uni.size();
    }
    const int size(const int a) {
        this->check(a);
        return -this->uni[this->find(a)];
    }
    const int edge_count(const int a) {
        this->check(a);
        return this->edge_count_[this->find(a)];
    }
    const weight_type weight(const int a) {
        this->check(a);
        return this->weights[this->find(a)];
    }
};

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    union_find<> uf(N);
    vector<long long> ans(M);
    ans[M - 1] = 1ll * N * (N - 1) / 2;
    for (int i = M - 1; i >= 0; i--) {
        if (i > 0) {
            int a_root = uf.find(A[i]);
            int b_root = uf.find(B[i]);
            if (a_root == b_root) {
                ans[i - 1] = ans[i];
            } else {
                ans[i - 1] = ans[i] - 1ll * uf.size(a_root) * uf.size(b_root);
            }
        }
        uf.unite(A[i], B[i]);
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
}
