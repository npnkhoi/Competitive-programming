#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int N = 1e6 + 5;
long long res;
char s[N];
int m, n, l[N], r[N];
int main() {
    freopen("lcs.inp", "r", stdin);
    //freopen("lcs.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    cerr << s + 1 << "\n";
    l[1] = 0;
    for (int i = 2; i <= n; i++)
        if (s[i] == s[i-1]) l[i] = l[i-1] + 1;
        else l[i] = 0;
    r[n] = 0;
    for (int i = n-1; i >= 1; i--)
        if (s[i] == s[i+1]) r[i] = r[i+1] + 1;
        else r[i] = 0;
    for (int i = 1; i <= n; i++) cerr << l[i] << " "; cerr << "\n";
    for (int i = 1; i <= n; i++) cerr << r[i] << " "; cerr << "\n";
    for (int i = 1; i <= n; i++) if (i == 1 || s[i] != s[i-1]) {
        res += (m-1) + ((i-1)*m - l[i]) + ((n-i)*m - r[i]);
        cerr << res << "\n";
    }

    printf("%lld", res);
}
