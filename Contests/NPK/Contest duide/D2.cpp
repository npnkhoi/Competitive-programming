
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct rc
{
    int x,y;
};
int n;
rc a[1010];
int tmp,res;
bool Free[1010];
long long l,r,mid;


bool inrange(int u, int v)
{
    return
    (1LL*((a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y)) <= mid);
}
void flood(int u)
{
    //cout << u << endl;
    Free[u]=0;
    tmp++;
    for (int i=1;i<=n;i++)
        if (Free[i]&&inrange(i,u))
        {
            //printf("%d -> %d\n",u,i);
            flood(i);
        }
}
bool ok()
{
    for (int j=1;j<=n;j++) Free[j]=1;
    tmp=0;
    flood(1);
    return (tmp==n);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    l=0; r=1e10;
    while (l<r)
    {
        mid=(l+r)/2;
        if (ok()) r=mid; else l=mid+1;
    }
    cout << l;
    //for (int i=0;i<=n;i++) cout << groupof[i] << " ";
}
