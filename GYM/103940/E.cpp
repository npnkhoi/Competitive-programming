#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("Test.txt", "r", stdin);
    int n, m; cin >> n >> m;
    if(n % m == 0) cout << n / m;
    else cout << n / m + 1;

    return 0;
}
