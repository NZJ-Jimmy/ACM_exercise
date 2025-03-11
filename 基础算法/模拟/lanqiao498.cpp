#include <bits/stdc++.h>
using namespace std;
class Ymd {
   private:
    const int m_has_day_ny[13] = {0,  31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};
    const int m_has_day_ly[13] = {0,  31, 29, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};
    bool is_leap() { return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0); };

   public:
    int y, m, d;
    Ymd(int y, int m, int d) : y(y), m(m), d(d) {};
    void next_day() {
        auto m_has_day = (is_leap() ? m_has_day_ly : m_has_day_ny);
        if (++d > m_has_day[m]) {
            d = 1;
            if (++m > 12) ++y, m = 1, d = 1;
        }
    }
    string format() {
        char buffer[9];
        sprintf(buffer, "%04d%02d%02d", y, m, d);
        return string(buffer);
    }
};

int main() {
    int n;
    cin >> n;
    int y = n / 10000, m = n / 100 % 100, d = n % 100;

    Ymd ymd(y, m, d);
    bool not_found = true;
    while (true) {
        ymd.next_day();
        string str = ymd.format();
        string str_r;
        str_r.resize(8);
        move(str.rbegin(), str.rend(), str_r.begin());
        // for (auto i = str.rbegin(); i != str.rend(); i++)
        //     str_r += *i;
        
        if (not_found && str == str_r) {
            cout << str << '\n';
            not_found = false;
        }
        if (str[0] == str[7] && str[2] == str[5] && str[0] == str[2] &&
            str[1] == str[6] && str[3] == str[4] && str[1] == str[3]) {
            cout << str;
            return 0;
        }
    }

    return 0;
}