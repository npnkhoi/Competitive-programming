//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define ll long long

const int M=550;
const int N=50;
const int oo=1e9;
int f[N][M+5][M+5],n,ma,mb,A[N],B[N],C[N],res;
using namespace std;
int main()
{
    //freopen("C.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d",&n,&ma,&mb);
    for (int i=1;i<=n;i++) scanf("%d%d%d",&A[i],&B[i],&C[i]);
    //--------------------------------
    for (int i=0;i<=n;i++)
        for (int j=0;j<=M;j++)
            for (int k=0;k<=M;k++) f[i][j][k]=oo;
    for (int i=0;i<=n;i++) f[i][0][0]=0;
    //---------------------------------
    for (int i=1;i<=n;i++)
        for (int j=1;j<=M;j++)
            for (int k=1;k<=M;k++)
    {
        f[i][j][k]=f[i-1][j][k];
        if ((A[i]<=j)&&(B[i]<=k))
        f[i][j][k]=min(f[i][j][k],C[i]+f[i-1][j-A[i]][k-B[i]]);
    }
    res=oo;
    for (int i=1;i<=M/max(ma,mb);i++)
        res=min(res,f[n][ma*i][mb*i]);
    if (res==oo) cout<<-1;
    else cout<<res;
}
