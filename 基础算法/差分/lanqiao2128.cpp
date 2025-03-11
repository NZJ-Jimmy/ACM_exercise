// https://www.lanqiao.cn/problems/2128/learning/
// 重新排序

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int m;
    cin >> m;
    int l, r;
    int diff[n + 2] = {};
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        diff[l]++, diff[r + 1]--;
    }

    int w[n + 1] = {};
    for (int i = 1; i <= n; i++) {
        w[i] = w[i - 1] + diff[i];
    }
    
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (long long) w[i] * a[i];
    }

    sort(a + 1, a + n + 1, greater<int>());
    sort(w + 1, w + n + 1, greater<int>());

    long long new_sum = 0;
    for (int i = 1; i <= n; i++) {
        if (w[i] == 0) break;
        new_sum += (long long) w[i] * a[i];
    }

    cout << new_sum - sum;
    return 0;
}