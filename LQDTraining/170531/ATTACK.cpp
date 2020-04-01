//#include <bits/stdc++.h>

#define ll long long
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
struct rc {
    int u;
    int v;
    int e;
};
int n,m,a[100050],pre[100050],cnt;
rc edge[100050];
ll res,s;


void start()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &edge[i].u, &edge[i].v);
        edge[i].e = a[edge[i].u] + a[edge[i].v];
        res+=edge[i].e;
    }
    //cout<<0;
}
bool compare(rc a,rc b)
{
    return a.e>=b.e;
}
void _union(int i)
{
    int x=edge[i].u, y=edge[i].v;
    while (pre[x]>0) x=pre[x];
    while (pre[y]>0) y=pre[y];
    if (x==y) return;
    cnt++; s+=edge[i].e;
    if (pre[x]<pre[y])
    {
        pre[x]+=pre[y];
        pre[y]=x;
    }
    else
    {
        pre[y]+=pre[x];
        pre[x]=y;
    }
}
void sol()
{
    sort(edge+1,edge+m+1,compare);
    memset(pre,-1,sizeof(pre));
    cnt=0;
    for (int i=1;i<=m;i++)
    {
        _union(i);
        if (cnt==n-1) break;
    }
    res-=s;
    printf("%d",res);
}
int main()
{
    freopen("ATTaCK.inp","r",stdin);
    freopen("ATTACK.out","w",stdout);
    start();
    sol();
}
