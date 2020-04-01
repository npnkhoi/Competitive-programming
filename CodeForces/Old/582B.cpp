using namespace std;
#include  <bits/stdc++.h>
const int N = 110;
const int oo = 1e9+ 7;
int n, t;
int a[N];
typedef int mat[N][N];
mat f, s;
void copy(const mat x, mat y) {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) y[i][j] = x[i][j];
}

void matMul(const mat x, const mat y, mat z) {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        z[i][j] = -oo;
        for (int k = 0; k < n; k++)
            z[i][j] = max(z[i][j], x[i][k] + y[k][j]);
    }
}

void matPow(const mat a, int b, mat c) {
    mat t, r;
    copy(a, t);
    memset(c, 0, sizeof c);

    while (b) {
        if (b & 1) {
            matMul(c, t, r);
            copy(r, c);
        }
        matMul(t, t, r);
        copy(r, t);
        b >>= 1;
    }
}
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    if (a[i] > a[j]) f[i][j] = -oo;
    else {
        f[i][j] = 1;
        for (int k = 0; k < j; k++)
        if (a[k] <= a[j]) f[i][j] = max(f[i][j], f[i][k] + 1);
    }

    matPow(f, t, s);
    //printf("ok\n");
    int res = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) res = max(res, s[i][j]);
    printf("%d\n", res);
}
