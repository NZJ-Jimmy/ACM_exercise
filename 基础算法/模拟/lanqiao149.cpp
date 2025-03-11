// 每个点的草最终会长成斜正方形

int n, m;

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin >> n >> m;
    // bool field[n][m];
    vector<vector<bool>> field(n);
    char x;
    for (int i = 0; i < n; i++) {
        field[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> x;
            field[i][j] = (x == 'g');
        }
    }
    int k;
    cin >> k;

    auto new_field = field;

    auto grow = [&](int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m) new_field[x][y] = true;
        cout << x << y<<'\n';
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (field[i][j]) {
                // upper triangle
                for (int p = i - k, t = 0; p <= i; p++, t++)
                    for (int q = j - t; q <= j + t; q++) grow(p, q);
                // lower triangle
                for (int p = i + k, t = 0; p > i; p--, t++)
                    for (int q = j - t; q <= j + t; q++) grow(p, q);
            }
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (new_field[i][j] ? 'g' : '.');
        }
        cout << '\n';
    }
    return 0;
}