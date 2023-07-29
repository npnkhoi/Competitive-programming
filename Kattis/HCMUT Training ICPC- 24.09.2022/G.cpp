#include <bits/stdc++.h>

using namespace std;
#define int long long

int toNum(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
        num = num * 10 + s[i] - '0';
    }
    return num;
}

bool check(string a, string b, string c, string type) {
    if (type == "+")
        return toNum(a) + toNum(b) == toNum(c);
    else return toNum(a) * toNum(b) == toNum(c);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a, dummy, b, c, type;
    cin >> a >> type >> b >> dummy >> c;

    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = 0; j < b.size() - 1; ++j) {
            string newA = b.substr(0, j + 1) + a.substr(i + 1, a.size() - i - 1);
            string newB = a.substr(0, i + 1) + b.substr(j + 1, b.size() - j - 1);

            if (check(newA, newB, c, type)) {
                cout << newA << ' ' << type << ' ' << newB << " = " << c << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = 0; j < c.size() - 1; ++j) {
            string newA = c.substr(0, j + 1) + a.substr(i + 1, a.size() - i - 1);
            string newC = a.substr(0, i + 1) + c.substr(j + 1, c.size() - j - 1);

            if (check(newA, b, newC, type)) {
                cout << newA << ' ' << type << ' ' << b << " = " << newC << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < c.size() - 1; ++i) {
        for (int j = 0; j < b.size() - 1; ++j) {
            string newC = b.substr(0, j + 1) + c.substr(i + 1, c.size() - i - 1);
            string newB = c.substr(0, i + 1) + b.substr(j + 1, b.size() - j - 1);

            if (check(a, newB, newC, type)) {
                cout << a << ' ' << type << ' ' << newB << " = " << newC << endl;
                return 0;
            }
        }
    }

}
