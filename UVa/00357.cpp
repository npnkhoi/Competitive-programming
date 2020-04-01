//#include <bits/stdc++.h>
#include <stdio.h>
//#include <>
#define ll long long

using namespace std;
const int N=3e4+1;
ll dp[7][30010];
int n,m;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int a[6]={0,1,5,10,25,50};
    for (int j=1;j<=N;j++) dp[0][j]=0;
    for (int i=0;i<=5;i++) dp[i][0]=1;

    //----------------
    for (int i=1;i<=5;i++)
        for (int j=1;j<=N;j++)
    {
        dp[i][j]=dp[i-1][j];
        if (a[i]<=j) dp[i][j]+=dp[i][j-a[i]];
    }
    //for (int i=0;i<=5;i++)
        //for (int j=1;j<=)
    //--------------------------------
    while (scanf("%d",&n)!=EOF)
    {
        if (dp[5][n]==1)
        printf("There is only 1 way to produce %d cents change.\n",n);
        else
    printf("There are %lld ways to produce %d cents change.\n",dp[5][n],n);
    }
}
