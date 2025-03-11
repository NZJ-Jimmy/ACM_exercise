// https://www.lanqiao.cn/problems/19716/learning/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> diff(n + 2, 0);
    vector<pair<int, int>> seg;
    // 记录每次操作，并差分
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        seg.push_back({x, y});
        diff[x]++, diff[y + 1]--;
    }
    vector<int> num(n + 1, 0);

    // 记录前缀和 ( , ]
    vector<long long> pre_sum(n + 1);

    // 如果一个位置上只有一个商品，那一旦被撤走，那就会没商品了
    // 所以记录一下，哪里是只有 1 个商品的；换个角度，记录哪里有多于 1 个商品的

    int zeros = 0;
    for (int i = 1; i <= n; i++) {
        num[i] = num[i - 1] + diff[i];
        if (num[i] == 0) zeros++;
        pre_sum[i] =
            pre_sum[i - 1] + (num[i] > 1);  // 前缀和，记录多于一个商品的位置
    }

    // If only 1 goods at a location, the goods will disappear if no operation.
    // So, count how many 1 between the segments.

    for (auto &&i : seg) {
        int &x = i.first, &y = i.second;
        int over_1 = pre_sum[y] - pre_sum[x - 1];  // 求出区间多于一个商品的位置
        int ones = y - x + 1 - over_1;  // 这个区间内只有一个商品的位置
        cout << ones + zeros << '\n';   // 加回本来就没商品的位置
    }

    return 0;
}