using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
const int N = 1e5 + 50;
int n;
pair<long long, int> a[N];
int b[N];
long long m, s;
int main()
{
    freopen("share.inp","r",stdin);
    freopen("share.out","w",stdout);
    scanf("%d %lld", &n, &m);
    for (int i = 1; i<=n;i++)
    {
        scanf("%lld",&a[i].fi);
        s += a[i].fi;
        a[i].se = i;
    }
    if (s<m)
    {
        cout << -1;
        return 0;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i<=n;i++)
    {
        long long tmp = m / (n-i+1);
        if (tmp <= a[i].fi) b[a[i].se] = tmp;
        else b[a[i].se] = a[i].fi;
        m -= b[a[i].se];
    }
    for (int i = 1;i <= n; i++) cout << b[i] << " ";
}
