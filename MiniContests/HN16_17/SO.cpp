#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int maxN = 32;
long long c[maxN+2][maxN+2], f[maxN+2][maxN+2];
int n, k;
int getbit(int &i, int &n) {return (1<<i)&n > 0;}

long long g(int i, int j) {
    if (i <= j) return 0;
    else return c[i-1][j];
}
int main() {
    for (int i = 0; i <= maxN; i++) {
        c[0][i] = c[i][i] = 1;
        for (int j = 1; j < i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    FOR(i, 1, maxN) FOR(j, 0, maxN) c[i][j] += c[i-1][j];
    FOR(i, 0, 5) {
        FOR(j, 0, 5) printf("%5lld", g(i, j));
        cout << endl;
    }

    while (scanf("%d %d", &n, &k) != EOF) {
        f[0][0] = n%2; f[0][1] = 1 - f[0][0];
        int i;
        for (i = 1; (1LL << i) <= n; i++)
        FOR(j, 0, k) if (getbit(i, n)) f[i][j] = f[i-1][j] + g(i-1, j);
        else if (j == 0) f[i][j] = 0;
        else f[i][j] = g(i-1, j-1);
        printf("%lld\n", f[i-1][k]);
    }
}
