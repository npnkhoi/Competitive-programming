#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;
int pre[20005];
int root(int &x)
{
    //int X=x;
    while (pre[x]>0) x=pre[x];
    return x;
}
int uni(int u, int v)
{
    int ru=root(u),rv=root(v);
    if (ru!=rv)
        if (pre[ru]<pre[rv])
    {
        pre[ru]+=pre[rv];
        pre[rv]=ru;
    } else
    {
        pre[rv]+=pre[ru];
        pre[ru]=rv;
    }
}
int main()
{
    //freopen("COLOUR.INP","r",stdin);
    //freopen("","w",stdout);
    int n,x,i;
    vector<int> a[10005];
    scanf("%d",&n);
    for (i=1;i<=2*n;i++)
    {
        scanf("%d",&x);
        a[x].push_back(i);
    }
    //printf("a\n");
    //for (i=1;i<=n;i++) printf("%d %d\n",a[i][0],a[i][1]);

    for (i=1;i<=2*n;i++) pre[i]=-1;
    for (i=1;i<=n;i++) uni(i,i+n);
    for (i=1;i<=n;i++) uni(a[i][0],a[i][1]);
    long long res=1;
    printf("\n");
    for (i=1;i<=2*n;i++)
    {
        if (pre[i]<0) res*=2;
        //printf("%d %d\n",i,pre[i]);
    }
    printf("%d",res);
}
