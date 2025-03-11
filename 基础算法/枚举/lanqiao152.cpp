#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    // 暴力
    // int cnt = 0;
    // for (int i = 1; i <= n; i++) cnt += (i % a) && (i % b) && (i % c);
    // cout << cnt;

    // O(log n)

    int ans = n;
    ans -= n / a + n / b + n / c;
    ans += n / lcm(a, b) + n / lcm(c, b) + n / lcm(a, c);
    ans -= n / lcm(lcm(a, b), c);

    cout << ans;
    return 0;
}