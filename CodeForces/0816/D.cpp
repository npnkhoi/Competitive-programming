using namespace std;
#include <bits/stdc++.h>
const int N = 50;
int a[N][N];
int n,m,k,cmd;
int main()
{
    while (1)
    {
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++) a[i][i] = 1;
    cmd = -1;
    for (int k=n-1;k>=1;k--)
    {
        for (int i=1;i<=k;i++)
        {
            cmd = -cmd;
            for (int j=1;j<=n;j++) a[i][j] = a[i][j] + cmd*a[i+1][j];
        }
        /*for (int i=1;i<=k;i++)
        {
            for (int j=1;j<=n;j++) printf("%6d",a[i][j]);
            cout << endl;
        }
        cout << endl;*/
    }
    for (int i=1;i<=n;i++) printf("%6d",a[1][i]);
    cout << endl;
    }
}
