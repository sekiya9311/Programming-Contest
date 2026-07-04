#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 333;
const int MAX_E = MAX_V * MAX_V;
const int MAX_Q = 2e5 + 10;
const int INF = 1e9;
const long long LLINF = 1e18;
long long dist[MAX_V][MAX_V];
tuple<int, int, long long> edge[MAX_E];
pair<int, int> query[MAX_Q];

int main() {
    for (int i = 0; i < MAX_V; i++) {
        for (int j = 0; j < MAX_V; j++) {
            dist[i][j] = (i == j ? 0 : LLINF);
        }
    }

    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = make_tuple(a - 1, b - 1, c);
    }

    unordered_set<int> closed;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            query[i] = make_pair(x - 1, INF);
            closed.emplace(x - 1);
        } else {
            int x, y;
            cin >> x >> y;
            query[i] = make_pair(x - 1, y - 1);
        }
    }

    for (int i = 0; i < M; i++) {
        if (closed.contains(i)) {
            continue;
        }
        const auto [a, b, c] = edge[i];
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<long long> ans;
    for (int q = Q - 1; q >= 0; q--) {
        if (query[q].second == INF) {
            const auto [a, b, c] = edge[query[q].first];
            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][a] + dist[a][b] + dist[b][j]);
                    dist[i][j] = min(dist[i][j], dist[i][b] + dist[b][a] + dist[a][j]);
                }
            }
        } else {
            const auto [x, y] = query[q];
            ans.emplace_back(dist[x][y]);
        }
    }

    ranges::reverse(ans);
    for (auto cur : ans) {
        cout << (cur == LLINF ? -1 : cur) << endl;
    }
}
