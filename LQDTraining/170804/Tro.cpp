using namespace std;
#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair

const ll md = 1e9 + 7;
ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a%b);
}

map<pll, ll> data;
map<pll, ll> :: iterator it;
ll n, res, s = 0;

int main() {
    freopen("Tro.inp", "r", stdin);
    freopen("Tro.out", "w", stdout);

    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a < 0) {
            a = -a, b = -b;
            ll x = gcd(a, abs(b));
            a /= x; b /= x;
        }
        else if (a == 0) b = 1;

        if (data.find(mp(a, b)) == data.end()) data[mp(a, b)] = 1;
        else data[mp(a, b)] ++;
    }

    for (it = data.begin(); it != data.end(); it++) {
        //cout << it -> second << endl;
        ll x = it -> second;
        s += x*(n-x);
    }

    s /= 2;
    s %= md;
    //cout << s << endl;

    ll remain = 0;

    for (it = data.begin(); it != data.end(); it++) {
        ll x = it -> second;

        /*ll tmp = x * (s + md - x*(n-x));
        remain += tmp%3;
        res = (res + tmp/3 + remain / 3) % md;]
        remain %= 3;
        //cout << res << endl;*/

        res = (res + (x * ((s + md - x*(n-x)%md) % md)) % md) % md;
    }

    while (res % 3) res += md;

    res /= 3;
    printf("%lld\n", res);
    //cout << res << " " << data.size() << endl;
}
