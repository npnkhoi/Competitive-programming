#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
const int A = 1e4;
const int M = 180 + 5;

int n, m, q;
int a[N], ft[M][A+5];
void update(int ft[], int p, int val) {
    for (; p <= A; p += p&-p) ft[p] += val;
}
int rmq(int ft[], int p) {
    int res = 0;
    for (; p; p -= p&-p) res += ft[p];
    return res;
}
int rmq(int ft[], int l, int r) {
    if (l > r) return 0;
    else return rmq(ft, r) - rmq(ft, l-1);
}
void query1() {
    int i, v;
    scanf("%d%d", &i, &v);
    update(ft[(i+m-1)/m], a[i], -1);
    update(ft[(i+m-1)/m], v, +1);
    a[i] = v;
}
void query2() {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    int res = 0;
    if (r-l+1 <= m)
        for (int i = l; i <= r; i++) res += a[i] > k;
    else {
        int i;
        for (i = l; i%m != 1; i++) res += a[i] > k;
        //cout << res << endl;
        int x = (i-1)/m+1;
        for (i = r; i%m != 0; i--) res += a[i] > k;
        //cout << res << endl;
        int y = i/m;
        for (i = x; i <= y; i++) res += rmq(ft[i], k+1, A);
    }
    printf("%d\n", res);
}
int main() {
    scanf("%d", &n);
    m = int(floor(sqrt(n)));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        update(ft[(i+m-1)/m], a[i], +1);
    }
    scanf("%d", &q);
    int cmd;
    while (q--) {
        scanf("%d", &cmd);
        if (cmd == 0) query1();
        else query2();
    }
}
