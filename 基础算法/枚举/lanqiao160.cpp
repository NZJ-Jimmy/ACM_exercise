#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    int y = 0, f = 0;
    string ys = "aeiou";
    for (auto &&i : str)
        if (ys.find(i) != string::npos)
            y++;
        else
            f++;

    cout << y << '\n' << f;
    return 0;
}