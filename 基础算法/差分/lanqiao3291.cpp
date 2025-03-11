#include <bits/stdc++.h>
using namespace std;
void solve(int &n, int &m) {
    int diff[n + 2] = {};
    int a, a0 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        diff[i] = a - a0, a0 = a;
    }

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        diff[x] += z, diff[y+1] -= z;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cout << (sum += diff[i]) << ' ';
    }
    cout << '\n';
}
int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
    return 0;
}