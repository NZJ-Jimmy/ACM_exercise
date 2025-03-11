#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> mat[i][j];

    int ans[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int sum = 0, cnt = 0;
            for (auto &&dx : {-1, 0, 1}) {
                if (i + dx < 0 || i + dx >= n) continue;
                for (auto &&dy : {-1, 0, 1}) {
                    if (j + dy < 0 || j + dy >= m) continue;
                    cnt++, sum += mat[i + dx][j + dy];
                }
            }
            ans[i][j] = sum / cnt;
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}