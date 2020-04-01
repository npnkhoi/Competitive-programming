
#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
int n,a[1010],b[1010];
int cnt;
bool Free[1010];
int x,y;
int main()
{
    scanf("%d",&n);
    cnt=0;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) Free[i]=1;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        if (a[i]==b[i])
        {
            Free[a[i]]=0;
        }
        else
        {
            cnt++;
            if (cnt==1) x=i; else y=i;
        }
    }
    if (cnt==1)
    {
        for (int i=1;i<=n;i++) if (Free[i]) a[x]=i;
    }
    else
    {
        if (Free[b[x]]&&Free[a[y]]) a[x]=b[x];
        else a[y]=b[y];
    }
    for (int i=0;i<n;i++) printf("%d ",a[i]);
}
