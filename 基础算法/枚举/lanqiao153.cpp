#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = n;
    for (int i = 1; i <= n; i++){
        string s = to_string(i);
        ans -= find(s.begin(), s.end(), '2') != s.end();
    }
    cout << ans;
    return 0;
}