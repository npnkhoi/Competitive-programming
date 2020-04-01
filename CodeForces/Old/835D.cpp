using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define llll pair<ll, ll>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

const int N = 5e3 + 10;
const ll md = 1e9 + 7;
const ll base = 26;
const ll base2 = 37;
int f[N][N], res[N];
llll E[N], h[N];
char str[N];
void init() {
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
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%s", str+1);
    int n = strlen(str + 1);

    init();
    hash_build(str, n, h);

    for (int k = 1; k <= n; k++)
    for (int j = k; j <= n; j++) {
        int i = j-k+1;

        if (i == j) {
            f[i][j] = 1, res[1] ++;
            continue;
        }

        if (str[i] == str[j])
        if (j-i==1 || f[i+1][j-1]%2) f[i][j] = 1;


        int l = k/2;
        int u = i + l - 1;
        int v = u+1 + ((j+i)%2 == 0);
        //printf("%d %d - %d %d\n", i, u, v, j);

        //printf("%lld %lld - %lld %lld\n", hash_id(h, i, u).fi, hash_id(h, v, j).fi,
            //hash_id(h, i, u).se, hash_id(h, v, j).se);
        if (hash_id(h, i, u).fi == hash_id(h, v, j).fi &&
            hash_id(h, i, u).se == hash_id(h, v, j).se)
        f[i][j] |= (f[i][u] & f[v][j]) << 1;

        int t = f[i][j];
        //printf("%d %d: %d\n", i, j, t);

        while (t > 0) {
            int x = __builtin_ctz(t);
            t -= t&(-t);
            res[x+1]++;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", res[i]);

    return 0;
}
/**/
