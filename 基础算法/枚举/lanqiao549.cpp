#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int x, boom_near[n + 2][m + 2] = {};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> x;
            if (x) {
                boom_near[i][j] = 9;
                for (int p = -1; p <= 1; p++)
                    for (int q = -1; q <= 1; q++)
                        if (!(p == q && p == 0)) boom_near[i + p][j + q]++;
            }
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << min(boom_near[i][j], 9) << ' ';
        }
        cout << '\n';
    }
    return 0;
}