#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, r, c;
    cin >> m >> n >> r >> c;

    bool mat[m + 2][n + 2] = {};

    // build a wall
    for (int i = 0; i <= m + 1; i++) mat[i][0] = true, mat[i][n + 1] = true;
    for (int i = 0; i <= n + 1; i++) mat[0][i] = true, mat[m + 1][i] = true;

    int cnt = 0, dir = 0;
    pair<int, int> cur = {1, 0}, des = {r, c};
    vector<pair<int, int>> diff = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto add = [&](const pair<int, int> &a,
                   const pair<int, int> &b) -> pair<int, int> {
        return {a.first + b.first, a.second + b.second};
    };

    while (cur != des) {
        auto next = add(cur, diff[dir]);
        if (mat[next.first][next.second]) dir = (dir + 1) % 4, next = add(cur, diff[dir]);
        cur = next;
        mat[cur.first][cur.second] = true;
        cnt++;
    }

    cout << cnt;
    return 0;
}