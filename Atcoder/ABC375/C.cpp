#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 3333;
char S[MAX_V][MAX_V];
char cp_S[MAX_V][MAX_V];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }
    memcpy(cp_S, S, sizeof(cp_S));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            const int cnt = (min(min(i, N - i - 1), min(j, N - j - 1)) + 1) % 4;
            int x = i, y = j;
            for (int k = 0; k < cnt; k++) {
                int ny = x;
                int nx = N - 1 - y;
                x = nx;
                y = ny;
            }
            S[i][j] = cp_S[x][y];
        }
    }

    // for (int i = 0; i < N / 2; i++) {
    //     cerr << "count: " << i + 1 << endl;
    //     memcpy(cp_S, S, sizeof(cp_S));
    //     for (int x = i; x < N - i; x++) {
    //         for (int y = i; y < N - i; y++) {
    //             cerr << "(" << y << ", " << N - x - 1 << ") <- (" << x << ", " << y << ")" << endl;
    //             S[y][N - x - 1] = cp_S[x][y];
    //         }
    //     }
    // }

    for (int i = 0; i < N; i++) {
        printf("%s\n", S[i]);
    }
}
