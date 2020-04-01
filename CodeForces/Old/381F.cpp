using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define For(i, a, b) for (int i = a; i <= b; i++)
#define F0r(i, b, a) for (int i = b; i >= a; i--)

typedef pair<int, int> ii;
typedef vector<int> vi;

using namespace std;

int n;
long long k, lo, hi, mi, a[110];

int ok(long long d) {
    long long s = 0;
    for (long long i = 1; i <= n; i++) {
        s += (a[i] + d - 1) / d * d - a[i];
    }
    //printf("%d ",d);
    return s <= k;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> n >> k;
    int x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x); a[i] = 1LL * x;
    }
    sort(a + 1, a + n + 1);

    lo = 1; hi = k;
    while (lo < hi) {
        //cout << lo << " " << hi << endl;
        mi = (lo + hi + 1) / 2;
        if (ok(mi)) lo = mi;
        else hi = mi - 1;
    }
    long long res;
    for (long long i = lo + 1; i <= lo + 1e6; i++) if (ok(i))
    cout << lo;
    return 0;
}
/**/
