#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 50;
int n, a[N], b[N], l[N], r[N], ft[N], res;
map<int, int> id;
int lsone(int x) {return x&(-x); }
void update(int x)
{
    for (; x <= n; x += lsone(x)) ft[x] ++;
    //for (int i = 1 ; i <= n; i++) cout << ft[i] << " ";
    //cout << endl;
}
int rsum(int x)
{
    int s = 0;
    for (; x; x -= lsone(x)) s += ft[x];
    return s;
}
int rsum(int l, int r)
{
    if (l>r) return 0;
    if (l==1) return rsum(r);
    return rsum(r) - rsum(l-1);
}
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    for (int i = 1; i<= n; i++) id[b[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = id[a[i]];
    //for (int i = 1; i <=n; i++) cout << a[i] << " ";
    //cout << "\n";
    for (int i = 1; i<= n; i++)
    {
        l[i] = rsum(a[i] + 1, n);
        //cout << l[i] << "\n";
        update(a[i]);
    }
    //cout << endl;
    memset(ft, 0, sizeof ft);

    for (int i = n; i >= 1; i--)
    {
        r[i] = rsum(a[i] + 1, n);
        //cout << r[i] << "\n";
        update(a[i]);
    }
    for (int i = 1; i <= n; i++)
    res += (max(l[i], r[i]) > (min(l[i], r[i]) << 1));
    cout << res;

    return 0;
}
/**/
