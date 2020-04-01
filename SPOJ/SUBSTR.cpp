using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long
#define llll pair<ll, ll>
#define fi first
#define se second

const ll md = 1e9 + 7;
const ll base = 26;
const ll base2 = 37;
const int N = 1e6 + 7;

char a[N], b[N];
llll ha[N], hb[N], E[N];

void hash_init() {
    E[0].fi = E[0].se = 1;

    for (int i = 1; i < N; i++)
        E[i].fi = E[i-1].fi*base % md,
        E[i].se = E[i-1].se*base2 % md;
}

void hash_build(char s[], int n, llll h[]) {
    for (int i = 1; i <= n; i++)
        h[i].fi = (h[i-1].fi*base + s[i]) % md,
        h[i].se = (h[i-1].se*base2 + s[i]) % md;
}

llll hash_id(llll h[], int l, int r) {
    llll tmp;
    tmp.fi = (h[r].fi - h[l-1].fi*E[r-l+1].fi + md*md) % md,
    tmp.se = (h[r].se - h[l-1].se*E[r-l+1].se + md*md) % md;
    return tmp;
}

int main() {
    //freopen("substr.inp", "r", stdin);
    //freopen("substr.out", "w", stdout);
    scanf("%s", a+1);
    scanf("%s", b+1);
    int m = strlen(a+1), n = strlen(b+1);
    //cout << a+1 << endl;
    //cout << b+1 << endl;
    //cout << m << endl;
    //cout << n << endl;

    hash_init();
    hash_build(a, m, ha);
    hash_build(b, n, hb);

    for (int i = 1; i <= m-n+1; i++)
    if (hb[n].fi == hash_id(ha, i, i+n-1).fi &&
        hb[n].se == hash_id(ha, i, i+n-1).se)
        printf("%d ", i);
}
