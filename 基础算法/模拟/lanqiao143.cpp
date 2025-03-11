#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long sum = n;
    while (n >= 3) sum += n / 3, n = n / 3 + n % 3;

    cout << sum;
    return 0;
}