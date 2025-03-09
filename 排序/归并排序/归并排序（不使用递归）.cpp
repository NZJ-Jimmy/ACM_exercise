#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tmp(n);
    for (int seg = 1; seg < n; seg *= 2) {
        for (auto l = 0; l < n - seg; l += seg * 2) {
            int m = l + seg, r = m + seg;
            auto a0 = a.begin(), tmp0 = tmp.begin();
            merge(a0 + l, a0 + m, a0 + m, min(a0 + r, a.end()), tmp0 + l);
            copy(tmp0 + l, tmp0 + r, a0 + l);
        }
    }

    for (auto &&i : a) {
        cout << i << ' ';
    }

    return 0;
}