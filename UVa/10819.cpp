//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define ll long long
using namespace std;
const int N=1e2+50;
const int M=1e4+300;
int p[N],f[N],m,n,dp[N][M],res;

int main()
{
    //freopen("10819.inp","r",stdin);
    //freopen("10819.out","w",stdout);
    int cnt=0;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        cnt++;
        for (int i=1;i<=n;i++) scanf("%d%d",&p[i],&f[i]);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m+200;j++) dp[i][j]=-1;
        for (int i=0;i<=n;i++) dp[i][0]=0;
        //-----------------------------------------------------------
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m+200;j++)
                if ((p[i]<=j)&&(dp[i-1][j-p[i]]!=-1)) dp[i][j]=max(dp[i-1][j],f[i]+dp[i-1][j-p[i]]);
                else dp[i][j]=dp[i-1][j];
        res=0;
        for (int j=1;j<=m;j++) res=max(res,dp[n][j]);
        for (int j=2001;j<=m+200;j++) res=max(res,dp[n][j]);
        printf("%d\n",res);
    }

}
