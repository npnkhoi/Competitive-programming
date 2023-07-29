#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 1000;
int factorial[10], f[1000];


void computeFactorial() {
    factorial[0] = 1;
    for(int i = 1; i <= 10; i++)
        factorial[i] = factorial[i - 1] * i;
}

signed main() {
    freopen("Test.txt", "r", stdin);
    int y; cin >> y;
    if(y == 1) {
        cout << 0;
        return 0;
    }

    computeFactorial();
    vector<int> digitCount(10);

    for(int num = 9; num >= 0; num--) {
        int cnt = y / factorial[num];
        if(cnt != 0)
            y = y % factorial[num];
        digitCount[num] = cnt;
    }

    string res = "";
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j < digitCount[i]; j++) {
            res += to_string(i);
        }
    }

    cout << res;
    return 0;
}
