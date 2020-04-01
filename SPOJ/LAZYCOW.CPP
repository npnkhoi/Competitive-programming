#include <bits/stdc++.h>
/*#include <iostream>
#include <stdio.h>
#include <algorithm>*/
#define oo 30000005
using namespace std;
int main()
{
    freopen("LAZYCOW.INP","r",stdin);
    printf("Hello WorLD");
    int n,k,B;
    scanf("%d%d%d",&n,&k,&B);
    printf("%d%d%d",n,k,B);

    int mark[n+5];
    int x,y;
    for (int i=1;i<=B;i++) mark[i]=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        mark[y]+=x;
    }
    // BUILD --------------------------
    int p[n+5],a[n+5],b[n+5];
    int m=0;
    for (int i=1;i<=B;i++)
    if (mark[i]>0)
    {
    m++;
    p[m]=i;
    a[m]=(mark[i]==1||mark[i]==3);
    b[m]=(mark[i]==2||mark[i]==3);
    }
    //BASIC -----------------
    int f[n+5][k+5][5];
    for (int x=0;x<=3;x++)
    {
        for (int j=0;j<=k;j++) f[0][j][x]=0;
        for (int i=1;i<=m;i++) f[i][0][x]=oo;
    }
    // DP ---------------------
    for (int i=1;i<=m;i++)
    for (int j=1;i<=k;j++)
    {
        int pre11=oo;
        for (int x=0;i<=3;x++) pre11=min(pre11,f[i-1][j-1][x]);
        int pre12=oo;
        int last=p[i]-p[i-1];
        if (j>=2) for (int x=0;x<=3;x++) pre12=min(pre12,f[1-1][j-2][x]);
        f[i][j][0]=min(pre11+2,f[i-1][j][0]);
        f[i][j][3]=min(min(pre12+2,f[i-1][j-1][1]+last+1),min(f[i-1][j-1][2]+last+1,f[i-1][j][3]+2*last));
        if (a[i]==0) f[i][j][1]=oo;
            else f[i][j][1]=min(pre11+1,min(f[i-1][j][1]+last,f[i-1][j][3]+last));
        if (b[i]=0) f[i][j][2]=oo;
            else f[i][j][2]=min(pre11+1,min(f[i-1][j][2]+last,f[i-1][j][3]+last));
    }
    // RESULT ------------
    int res=oo;
    for (int x=0;x<=3;x++) res=min(res,f[m][k][x]);
    // FINISH --------------------
    printf("%d",res);
}
