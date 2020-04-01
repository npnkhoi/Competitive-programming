#include <bits/stdc++.h>

using namespace std;
int m,b;
long long res;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &m, &b);
    for (int x = 0; x <= b*m; x += m)
    {
        int y = -x/m + b;
        res = max (res, 1LL * (x+y) * (x+1) * (y+1) / 2);
    }
    cout << res;
    return 0;
}
/**/
