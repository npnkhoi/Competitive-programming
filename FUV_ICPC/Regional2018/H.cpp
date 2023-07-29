#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int head, tail;
    while (cin >> head >> tail) {
        if (head == 0 && tail == 0) continue;
        int res = 0;
        if (tail % 2 == 1) {
            tail++;
            res++;
        }
        if ((head + tail / 2) % 2 != 0) {
            res += 2;
            tail += 2;
        }
        res += tail / 2;
        head += tail / 2;
        res += head / 2;
        cout << res << endl;
    }
}