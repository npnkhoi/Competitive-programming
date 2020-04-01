#include <bits/stdc++.h>
using namespace std;

int a[2][(int)1e6];
int main() {
    freopen("test.txt", "w", stdout);
    int n = 1000;
    int cur = 0, pre = 1;
    a[cur][1] = 1;

    for (int i = 2; i <= n; i++) {
        swap(pre, cur);
        a[cur][1] = a[pre][2];
        for (int j = 2; j <= n; j++) a[cur][j] = a[pre][j - 1] ^ a[pre][j + 1];
        for (int j = 1; j <= n; j++) if (a[cur][j]) cout << "X "; else cout << ". " ;
        cout << "\n";
    }
}
