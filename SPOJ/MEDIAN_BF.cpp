using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int N = 25e4 + 10;
ll seed, mul, add, a[N];
int n, k;

int main() {
    freopen("median.inp","r",stdin);
    freopen("MEDIAN.ans", "w", stdout);
    scanf("%d", &n);

    scanf("%lld %lld %lld %d %d", &seed, &mul, &add, &n, &k);
    cout << n << " " << k << endl;
    a[1] = seed;
    FOR(i, 2, n) a[i] = (a[i-1]*mul + add) % 65536;
    ll res = 0;
    FOR(i, k, n) {
        vector<ll> v;
        FOR(j, i-k+1, i) v.push_back(a[j]);
        sort(v.begin(), v.end());
        res += v[(k+1)/2-1];
        printf("%lld\n", res);
    }
    printf("%lld\n", res);
    return 0;
}
/**/
