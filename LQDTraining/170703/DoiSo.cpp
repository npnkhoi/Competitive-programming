using namespace std;
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
string num;
int s;
int main() {
    freopen("DOISO.inp","r",stdin);
    freopen("DOISO.out","w",stdout);
    cin >> num;
    s = 0;
    for (int i = 0; i < num.size(); i++)
        s = (s + num[i] - '0') % 3;
    if (s%3) {
        cout << -1;
        return 0;
    }
    sort(num.rbegin(), num.rend());
    if (*num.rbegin() != '0') {
        cout << -1;
        return 0;
    }
    cout << num;
}
