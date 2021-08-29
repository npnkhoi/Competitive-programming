//#include <bits/stdc++.h>

#define ll long long
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int N=1050;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n,m,b[N][N],s[N*N],k;
char a[N][N];
bool cal[N*N];
bool ok(int x, int y)
{
    return ((x>=1)&&(x<=n)&&(y>=1)&&(y<=m));
}
void dfs(int i, int j, int k)
{
    if ((!ok(i,j))||(a[i][j]=='*')||(b[i][j]!=0)) return;
    //cout<<i<<" "<<j<<endl;
    b[i][j]=k; s[k]++;
    for (int l=0;l<4;l++) dfs(i+dx[l],j+dy[l],k);
}
int sum(int i, int j)
{
    vector<int> d;
    for (int l=0;l<4;l++)
    {
        int u=i+dx[l],v=j+dy[l];
        if (ok(u,v)&&(a[u][v]=='.')&&(!cal[b[u][v]]))
        {
            d.push_back(b[u][v]);
            cal[b[u][v]]=1;
        }
    }
    int res=0;
    for (int i=0;i<d.size();i++) {res+=s[d[i]]; cal[d[i]]=0;}
    return (res+1)%10;
}
int main()
{
    //freopen("E.inp","r",stdin);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) scanf(" %c",&a[i][j]);
    }
    k=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if ((b[i][j]==0)&&(a[i][j]=='.'))
            {
                k++;
                dfs(i,j,k);
            }
    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) cout<<b[i][j]<<"\t";
        cout<<endl;
    }*/
    memset(cal,0,sizeof(cal));
    //---------------------------------
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if (a[i][j]=='.') printf(".");
        else printf("%d",sum(i,j));
        printf("\n");
    }
}
