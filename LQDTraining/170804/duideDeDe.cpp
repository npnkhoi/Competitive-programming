using namespace std;
#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
ll gcd(ll a, ll b) {
    //cout << a << " " << b << endl;
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
        //printf("%lld %lld %lld\n", a, b, c);
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
        ll x = it -> second;
        s += x * (n-x);
    }

    s /= 2;
    //cout << s << endl;

    for (it = data.begin(); it != data.end(); it++) {
        ll x = it -> second;
        res += x * (s - x*(n-x));
    }

    printf("%lld", res / (1LL * data.size()));
}
