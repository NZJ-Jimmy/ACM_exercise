// https://www.lanqiao.cn/problems/128/learning/?page=1&first_category_id=1&problem_id=128


#include <bits/stdc++.h>
using namespace std;

long long maxn = 0;
// set<long long> calc_ed; // Memorized Search
// 不能使用记忆化，因为查找的时间比算出的时间还长，要想办法做其他优化
void f(long long n)
{
    while (n != 1) { // 因为
        // if (calc_ed.count(n)) return;
        // else
        //     calc_ed.insert(n);
        if (n & 1)
            n = n * 3 + 1;
        else
            n /= 2;
        maxn = max(n, maxn);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        f(i);
    }
    cout << maxn;
    return 0;
}