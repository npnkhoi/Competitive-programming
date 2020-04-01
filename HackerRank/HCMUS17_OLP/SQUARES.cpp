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
const ll md = 1e9 + 7;
ll n, l, res;
ll Exp(ll a, ll x) {
    if (x == 1) return a;
    else {
        ll tmp = Exp(a, x / 2);
        if (x % 2) return tmp * tmp % md * a % md;
        else return tmp * tmp % md;
    }
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%lld %lld", &n, &l);
    res = (Exp(4, n+1) + md - 1) % md;
    while (res % 3) res += md;
    res /= 3;

    res = res * l % md;
    res = res * l % md;
    printf("%lld\n", res);

    return 0;
}
/** Happy Coding ^^ */

