using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 5e4 + 5;
int tc;
ll num, k, a[N], b[N];
int n, m;

ll gcd(int a, int b) {
    if (a == 0) return b;
    else return gcd(b % a, a);
}
ll lcm(ll a, ll b) {
    a = a / gcd(a, b);
    if (int(floor((log10(a) + log10(b))) + 1) >= 14) return -1;
    else return a * b;
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        scanf("%lld", &k);
        num = k;
        /// factorize -------------------------
        m = 0;
        for (ll i = 2; i*i <= k; i++)
        if (k % i == 0) {
            ll tmp = 1;
            while (k % i == 0) k /= i, tmp *= i;
            b[++m] = tmp;
        }
        if (m == 0 || k > 1) b[++m] = k;
        /// construct K --------------------------
        bool res = 1;
        for (int i = 1; i <= m; i++) {
            ll tmp = 0;
            for (int j = 0; j < n; j++)
            if (a[j] % b[i] == 0)
                tmp = gcd(tmp, a[j]);
            if (tmp == 0 || num % tmp != 0) {
                res = 0;
                break;
            }
        }
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/** Happy Coding ^^ */

