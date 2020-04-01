using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e6 + 5;
const ll base1 = 257;
const ll base2 = 511;
const ll md = 1e9 + 7;
pll ha[N], hb[N], EXP[N];
string a, b;
int k, cnt[N];
void hashInit() {
    EXP[0] = mp(1, 1);
    for (int i = 1; i <= 1e6 + 2; i++) {
        EXP[i].fi = EXP[i-1].fi * base1 % md;
        EXP[i].se = EXP[i-1].se * base2 % md;
    }
}
void hashBuild(pll h[], string &s, int n) {
    h[0] = mp(s[0], s[0]);
    for (int i = 1; i < n; i++) {
        h[i].fi = (h[i-1].fi * base1 + s[i]) % md;
        h[i].se = (h[i-1].se * base2 + s[i]) % md;
    }
}
pll hashID(pll h[], int l, int r) {
    if (l == 0)
        return mp(h[r].fi, h[r].se);
    else {
        pll res;
        res.fi = (h[r].fi - h[l-1].fi * EXP[r-l+1].fi + md * md) % md;
        res.se = (h[r].se - h[l-1].se * EXP[r-l+1].se + md * md) % md;
        return res;
    }
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    getline(cin, a); getline(cin, b);
    int m = a.size(), n = b.size();
    scanf("%d", &k);
    if (k < n) {
        printf("0");
        return 0;
    }
    hashInit();
    hashBuild(ha, a, m);
    hashBuild(hb, b, n);
    for (int i = n-1; i < m; i++) {
        if (hashID(ha, i-n+1, i) == hashID(hb, 0, n-1)) {
            cnt[max(i, k-1)] ++;
            cnt[min(m-1, i + k - n) + 1] -- ;
        }
    }
    int tmp = 0, res = 0;
    for (int i = k-1; i < m; i++) {
        tmp += cnt[i];
        res += (tmp > 0);
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding ^^ */

