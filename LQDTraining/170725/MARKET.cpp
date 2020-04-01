using namespace std;
#include <stdio.h>
#include <algorithm>

const int N = 5010;
const int M = 1e5 + 10;
const long long oo = 1e12;
int n, m, a[N], c[M], IT[4*M];
long long f[N];
int _min[N*N];

int left(int p) {return (p<<1);}
int right(int p) {return (p<<1)+1;}

void build(int p, int l, int r) {
    if (l > r) return;
    if (l == r) IT[p] = l;
    else {
        int mid = (l + r) / 2;
        build(left(p), l, mid);
        build(right(p), mid+1, r);

        int p1 = IT[left(p)];
        int p2 = IT[right(p)];

        IT[p] = (c[p1] < c[p2]) ? p1 : p2;
    }
}

int RMQ(int p, int l, int r, int L, int R) {
    if (r < L || R < l || r < l) return -1;

    if (L <= l && r <= R) return IT[p];

    int mid = (l + r) >> 1;

    int p1 = RMQ(left(p), l, mid, L, R);
    int p2 = RMQ(right(p), mid+1, r, L, R);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (c[p1] < c[p2]) ? p1 : p2;
}
void sub1() {
    build(1, 1, m);


    f[0] = 0;
    //for (int i = 0; i <= n; i++) k[i] = 1234567;


    for (int i = 1; i <= n; i++) {
        long long t = oo;
        for (int j = 0; j < i ; j++) t = min(t, f[j] + c[RMQ(1, 1, m, a[i] - a[j+1] + 1, a[i])]);
        f[i] = t;
    }
}

void sub2() {
    f[0] = 0;
    _min[m] = c[m];
    for (int i = m-1; i >= 1; i--) _min[i] = min(_min[i+1], c[i]);
    for (int i = 1; i <= n; i++) {
        long long t = oo;
        for (int j = 0; j < i ; j++) t = min(t, f[j] +
            _min[a[i] - a[j+1] + 1]);
        f[i] = t;
    }
}
int main() {
    freopen("MARKET.inp", "r", stdin);
    freopen("MARKET.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &c[i]);

    sort(a+1, a+n+1);

    if (n <= 2e3) sub1();
    else sub2();

    printf("%lld", f[n]);

}
