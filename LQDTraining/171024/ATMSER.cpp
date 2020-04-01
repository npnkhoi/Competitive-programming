#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define mp make_pair
#define fi first
#define se second

const int N = 53;
const int vMax = 1e7 + 5;
const ll md = 1e9 + 7;
const int oo = 1e8 + 7;
pll EXP[N], v[vMax];
int d[N][N], a[N][N];
int n, k, m;
bitset<N> sign;

pll id1(int mask) {
    sign.reset();
    for (int i = 0; i < n/2; i++) if (mask & 1<<i)
    for (int j = 1; j <= n; j++) if (a[i+1][j] == 1) sign[j] = 1;
    pll res = mp(0, 0);
    for (int j = 1; j <= n; j++) if (sign[j]) {
        res.fi = (res.fi + EXP[j-1].fi) % md;
        res.se = (res.se + EXP[j-1].se) % md;
    }
    return res;
}
pll id2(int mask) {
    sign.reset();
    for (int i = 0; i < n-n/2; i++) if (mask & 1<<i)
    for (int j = 1; j <= n; j++) if (a[n-i][j] == 1) sign[j] = 1;
    pll res = mp(0, 0);
    for (int j = 1; j <= n; j++) if (sign[j]) {
        res.fi = (res.fi + EXP[j-1].fi) % md;
        res.se = (res.se + EXP[j-1].se) % md;
    }
    return res;
}

bool avail(pll pack) {
    printf("avil %lld %lld\n", pack.fi, pack.se);
    pack.fi = (EXP[n].fi - pack.fi + md - 1) % md;
    pack.se = (EXP[n].se - pack.se + md - 1) % md;
    printf("%lld %lld\n --- ", pack.fi, pack.se);

    return *lower_bound(v+1, v+m+1, pack) == pack;
}

bool ok(int num) {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = d[i][j] <= num;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%10d", a[i][j]);
        cout << endl;
    }
    cout << endl;


    for (int z = 0; z <= k; z++) {
        m = 0;
        for (int mask = 0; mask < 1 << n/2; mask ++)
        if (__builtin_popcount(mask) == z) v[++m] = id1(mask);
        sort(v+1, v+m+1);
        for (int i = 1; i <= m; i++) cout << v[i].fi << " " << v[i].se << endl;
        cout << endl;

        if (avail(mp(0, 0))) return 0;

        for (int mask = 0; mask < 1<<(n-n/2); mask ++) {
            if (__builtin_popcount(mask) == k-z && avail(id2(mask)))
                return true;
            cout << id2(mask).fi << " " << id2(mask).se << endl;
        }
        cout << "----\n";
    }
    return false;
}
int main () {
    freopen("atmser.inp", "r", stdin);
    EXP[0] = mp(1, 1);
    for (int i = 1; i <= 50; i++) {
        EXP[i].fi = EXP[i-1].fi * 2 % md;
        EXP[i].se = EXP[i-1].se * 3 % md;
    }

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        scanf("%d", &d[i][j]);
        if (i != j && d[i][j] == 0) d[i][j] = oo;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                //printf("%10d", d[i][j]);
            }
            //cout << endl;
        }
        //cout << endl;
    }

    int l = 0, r = oo;
    /*while (l < r) {
        int mid = (l + r) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);*/
    cout << "------\n";
    cout << ok(2) << endl;
}
