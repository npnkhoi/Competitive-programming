#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int m,n,res;
int x,y,u,v;
char boss,ch,a[110][110];
int main()
{
    scanf("%d%d %c",&m,&n,&boss);
    x=m+1; y=n+1; u=0; v=0;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
    {
        scanf(" %c",&a[i][j]);
        if (a[i][j]==boss)
        {
            x=min(x,i);
            y=min(y,j);
            u=max(u,i);
            v=max(v,j);
        }
    }
    res=0;
        if (x>1)
    {
        res+=(a[x-1][y]!='.');
            for (int j=y+1;j<=v;j++)
            res+=((a[x-1][j]!='.')&&(a[x-1][j]!=a[x-1][j-1]));
    }
        if (u<m)
    {
        res+=(a[u+1][y]!='.');
            for (int j=y+1;j<=v;j++)
            res+=((a[u+1][j]!='.')&&(a[u+1][j]!=a[u+1][j-1]));
    }
        if (y>1)
    {
        res+=(a[x][y-1]!='.');
            for (int i=x+1;i<=u;i++)
            res+=((a[i][y-1]!='.')&&(a[i][y-1]!=a[i-1][y-1]));
    }
        if (v<n)
    {
        res+=(a[x][v+1]!='.');
            for (int i=x+1;i<=u;i++)
            res+=((a[i][v+1]!='.')&&(a[i][v+1]!=a[i-1][v+1]));
    }
    cout << res;


}
