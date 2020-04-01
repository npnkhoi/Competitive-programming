#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define mp make_pair

const ll md = 1e9 + 7;
const ll base1 = 256;
const ll base2 = 377;
const int N = 5e4 + 5;
int n;
char x[N], y[N];
pll hx[N], hy[N], EXP[N];

void hashInit() {
    EXP[0] = mp(1, 1);
    for (int i = 1; i <= N-2; i++) {
        EXP[i].fi = EXP[i-1].fi * base1 % md;
        EXP[i].se = EXP[i-1].se * base2 % md;
    }
}
void hashBuild(char s[], pll h[], int n) {
    h[0] = mp(0, 0);
    for (int i = 1; i <= n; i++) {
        h[i].fi = (h[i-1].fi * base1 + s[i]) % md;
        h[i].se = (h[i-1].se * base2 + s[i]) % md;
    }
}
pll hashID(pll h[], int l, int r) {
    pll res;
    res.fi = (h[r].fi - h[l-1].fi * EXP[r-l+1].fi + md*md) % md;
    res.se = (h[r].se - h[l-1].se * EXP[r-l+1].se + md*md) % md;
    return res;
}
bool okOdd(int i, int d) {
    int l1 = i-d, r1 = i+d;
    i = n-i+1;
    int l2 = i-d, r2 = i+d;
    return hashID(hx, l1, r1) == hashID(hy, l2, r2);
}
bool okEven(int i, int d) {
    int l1 = i-d, r1 = i+d+1;
    i = n-i;
    int l2 = i-d, r2 = i+d+1;
    return hashID(hx, l1, r1) == hashID(hy, l2, r2);
}
int main() {
    hashInit();
    scanf("%d%s", &n, x+1);
    //cout << x+1 << endl;
    strcpy(y+1, x+1);
    reverse(y+1, y+n+1);
    //cout << y+1 << endl;
    hashBuild(x, hx, n);
    hashBuild(y, hy, n);

    int res = 1;

    /// odd case
    for (int i = 1; i <= n; i++) {
        int l = 0, r = min(i-1, n-i);
        while (l < r) {
            int mid = (l+r+1) / 2;
            if (okOdd(i, mid)) l = mid;
            else r = mid  - 1;
        }
        res = max(res, 2*l+1);
    }

    /// even case
    for (int i = 1; i < n; i++) if (x[i] == x[i+1]) {
        int l = 0, r = min(i-1, n-i-1);
        while (l < r) {
            int mid = (l+r+1)/2;
            if (okEven(i, mid)) l = mid;
            else r = mid - 1;
        }
        res = max(res, 2*l+2);
    }
    printf("%d\n", res);
    //cout << "-------\n";
    //cout << okOdd(2, 1);
}
