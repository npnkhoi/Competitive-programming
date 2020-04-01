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
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 25e4 + 10;
ll seed, mul, add;
int n, k;
ll a[N];
set<li> data;

int main() {
    //freopen("","r",stdin);
    freopen("out.txt","w",stdout);
    int TC;
    scanf("%d", &TC);
    FOR(tc, 1, TC) {
        data.clear();

        scanf("%lld %lld %lld %d %d", &seed, &mul, &add, &n, &k);
        int pos = (k+1) / 2;
        a[1] = seed;
        data.insert(li(seed, 1));

        FOR(i, 2, k) {
            a[i] = (a[i-1]*mul + add)%65536LL;
            data.insert(li(a[i], i));
        }

        FOR(i, 1, pos-1) data.erase(data.begin());
        long long res = data.begin() -> first;
        printf("%lld %lld", res, a[k]);

        FOR(i, k+1, n) {
            a[i] = (a[i-1]*mul + add)%65536LL;
            //printf("%lld\n", a[i]);

            data.insert(mp(a[i], i));

            if (data.find(li(a[i-k], i-k)) != data.end())
                data.erase(li(a[i-k], i-k));
            else data.erase(data.begin());

            res += data.begin() -> first;
            printf("%lld %lld\n", data.begin() -> first, a[i]);
        }
        //printf("Case #%d: %lld\n", tc, res);
    }
    return 0;
}
/**/
