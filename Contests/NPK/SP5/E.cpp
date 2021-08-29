using namespace std;
#include <bits/stdc++.h>
const int N = 1e3 + 5;
int a[N], b[N], f[N][N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    f[i][j] = max(max(f[i-1][j], f[i][j-1]), f[i-1][j-1] + (abs(a[i]-b[j]) <= 4));

    cout << f[n][n];
}
