using namespace std;
#include  <bits/stdc++.h>

const int N = 110;
const int oo = 1e9+ 7;
typedef int mat[N][N];

int n, t;
int a[N*N], cnt[310], st[N], en[N];
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

void sub1() {
    //cout << "sub1\n";
    vector<int> v;
    //cout << "ok\n";
    for (int i = 0; i < n*t; ++i) {
        int num = a[i%n];
        if (v.empty() || num > v.back()) v.push_back(num);
        else {
            //cout << i << endl;
            int pos = upper_bound(v.begin(), v.end(), num) - v.begin();
            //printf("%d %d\n", num, pos);
            v[pos] = num;
        }
    }
    printf("%d", v.size());
}

void sub2() {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    if (a[i] > a[j]) f[i][j] = -oo;
    else {
        f[i][j] = 1;
        for (int k = 0; k < j; k++)
        if (a[k] <= a[j]) f[i][j] = max(f[i][j], f[i][k] + 1);
    }

    matPow(f, n, s);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cout << f[i][j] << " \n"[j==n-1];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cout << s[i][j] << " \n"[j==n-1];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        st[i] = max(st[i], s[i][j]);
        en[j] = max(en[j], s[i][j]);
    }
    //printf("ok\n");
    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, en[i] + (t-2*n)*cnt[a[i]] + st[i]);
    printf("%d\n", res);
}
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]] ++;
    }
    //cout << "ok\n";
    if (t <= 2*n) sub1();
    else sub2();

}
