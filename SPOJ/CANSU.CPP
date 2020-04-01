#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int slot(int &x, int &y)
{
    int s=0;
    for (int i=0;i<=3;i++) s+=a[x+dx[i]][y+dy[i]];
    return s;
}
int update(int &x,int &y)
{
    for (int i=0;i<=3;i++)
    {
        a[x+dx[i]][y+dy[i]]--;
    }
}
int gogo()
{
    // READ --------------
    scanf("%d%d",n,m);
    for (int i=1;i<=n;i++)
        for (j=1;j<=m;j++) scanf("%d",a[i][j]);
    // BUILD -------------
    for (i=0;i<=n;i++)
    {
        mark[i][0]=0;
        mark[i][m+1]=0;
    }
    for (int j=0;j<=m;j++)
    {
        mark[0][j]=0;
        mark[n+1][j]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) mark[i][j]=1
    // MAIN ------------------
    bool stop=0;
    while (!stop)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
        {
            if (a[i][j]=0)
                for (int k=0;k<=3;k++)
                {
                    a[i+dx[k]][j+dy[k]]=0;
                    cnt-=a[i+dx[k]][j+dy[k]]==1;
                }
            if (a[i][j]=slot(i,j))
                for (i=0;i<=3;i++)
                if (mark[x+dx[i]][y+dy[i]]==1) update(x+dx[i],y+dy[i]);
            if (a[i][j]<0)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
}
int main()
{
    freopen("CANSU.INP","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&t);
    for (int i=1;i<=t;i++) gogo;
}
