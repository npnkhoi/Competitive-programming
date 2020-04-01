using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
ll l, q, k, d;
void trans(ll &q, ll d) {
    ll s;
    if (min(k, q) < d) {
        q = -1;
        return;
    }
    s = min(k, q) - d;
    q -= min(k, q);
    if (k > 2*d) s += q / k * (k - 2*d);
    q %= k;
    if (q > 2*d) s += q - 2*d;
    q = s;
}
void sub1() {
    ll s;
    REP(z, l/d) {
        trans(q, d);
        if (q == -1) break;
    }
    if (l % d) trans(q, l % d);
    printf("%lld", q);
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%lld %lld %lld %lld", &l ,&q, &k, &d);
    sub1();
    return 0;
}
/** Happy Coding ^^ */
