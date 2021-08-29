#include <bits/stdc++.h>

using namespace std;
set<int> data;
const int N = 1e5 + 50;
int n, a[N], l[N], r[N], res;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        data.insert(a[i]);
        l[i] = distance(data.find(a[i]), data.end())-1;
    }
    data.clear();
    for (int i = n; i >= 1; i--)
    {
        data.insert(a[i]);
        r[i] = distance(data.find(a[i]), data.end())-1;
    }
    for (int i = 1; i <= n; i++)
    res += (max(l[i], r[i]) > (min(l[i], r[i]) << 1));
    cout << res;
    return 0;
}
/**/
