#include <bits/stdc++.h>

using namespace std;
int a[55][55], n;
bool ok;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j = 1; j <= n; j++) scanf("%d",&a[i][j]);
    for(int x = 1; x <= n ;x++)
        for (int y =1; y<= n;y++)
            if (a[x][y] != 1)
    {
        ok = 0;
        for (int s = 1 ; s<=n && (!ok);s++)
            for (int t=1;t<=n && (!ok);t++)
        if (a[x][s] + a[t][y] == a[x][y]) ok = 1;
        if (!ok)
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}
/**/
