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
const ll base1 = 2;
const ll base2 = 3;
const int L = 2e5 + 5;
const int N = 95;
const int K = 30;
const ll md = 1e9 + 7;
int l;
pll EXP[L], h[K][L], hs[L];
ll f[N], dp[N];
char s[K][L], str[L];
void hashInit() {
    EXP[0] = mp(1, 1);
    for (int i = 1; i <= L-2; i++) {
        EXP[i].fi = EXP[i-1].fi * base1 % md;
        EXP[i].se = EXP[i-1].se * base2 % md;
    }
}
void hashBuild(char s[], pll h[], int n) {
    h[0] = mp(0, 0);
    for (int i = 1; i <= n; i++) {
        h[i].fi = (h[i-1].fi * base1 + s[i-1] - 'A') % md;
        h[i].se = (h[i-1].se * base2 + s[i-1] - 'A') % md;
    }
}
pll hashID(pll h[], int l, int r) {
    pll res;
    res.fi = (h[r].fi - h[l-1].fi * EXP[r-l+1].fi + md * md) % md;
    res.se = (h[r].se - h[l-1].se * EXP[r-l+1].se + md * md) % md;
    return res;
}
bool matchLeft(int x, int n) { /// if k first S MATCH k last f[n]
    if (x > f[n]) return 0;
    if (n%2) n = 27; else n = 26;
    return hashID(hs, 1, x) == hashID(h[n], f[n]-x+1, f[n]);
}
bool matchRight(int x, int n) { /// if k last S MATCH k first f[n]
    if (x > f[n]) return 0;
    if (n > 27) n = 27;
    return hashID(hs, l-x+1, l) == hashID(h[n], 1, x);
}
void init() {
    hashInit();
    f[1] = f[2] = 1;
    for (int i = 3; i <= 91; i++) {
        f[i] = f[i-1] + f[i-2];
        //cout << i << " " << f[i] << endl;
    }
    h[1][1] = mp(0, 0);
    h[2][1] = mp(1, 1);
    for (int i = 3; f[i] <= 2e5; i++) {
        for (int j = 1; j <= f[i-1]; j++) h[i][j] = h[i-1][j];
        for (int j = 1; j <= f[i-2]; j++) {
            h[i][f[i-1]+j].fi = (h[i][f[i-1]].fi * EXP[j].fi + h[i-2][j].fi) % md;
            h[i][f[i-1]+j].se = (h[i][f[i-1]].se * EXP[j].se + h[i-2][j].se) % md;
        }
    }
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    init();
    int n;
    while (scanf("%d ", &n) != EOF) {
        scanf("%s", str);
        l = strlen(str);

        bool halt = 0;
        for (int i = 0; i < l; i++) if (str[i] != 'A' && str[i] != 'B') {
            halt = 1;
            printf("0\n");
            break;
        }
        if (halt) continue;
        hashBuild(str, hs, l);
        if (l == 1) {
            dp[1] = (str[0] == 'A');
            dp[2] = (str[0] == 'B');
        } else {
            dp[1] = dp[2] = 0;
        }
        int i;
        for (i = 3; i <= n; i++) {
            if (f[i] < l) dp[i] = 0;
            else {
                dp[i] = dp[i-1] + dp[i-2];
                for (int k = 1; k < l; k++) {
                    dp[i] += matchLeft(k, i-1) & matchRight(l-k, i-2);
                }
            }
        }
        printf("%lld\n", dp[i-1]);
    }
    return 0;
}
/** Happy Coding ^^ */

