#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x = 33;
    int cap = (int)1e12;
    cout << "? " << cap << endl;
    int receive;
    //cin >> receive;
    receive = cap % x;
    int kx = cap - receive, cur_kx = kx, k = 0;
    int cur = kx;
    for (int i = 0; i < 40; ++i) {
        cout << "? " << cur + cur_kx / 2 << endl;
        //cin >> receive;
        receive = (cur + cur_kx / 2);
        if (receive != 0) {
            cout << "! " << receive * 2 + (cur_kx % 2 != 0) << endl;
        }
        cur += kx;
        cur_kx /= 2;
    }

    return 0;
}
