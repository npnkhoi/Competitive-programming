
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct rc
{
    int x,y,p;
};
int n;
rc a[210];
int tmp,res;
bool Free[210];


bool inrange(int u, int v)
{
    return
    (((a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y)) <= (a[v].p*a[v].p));
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

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].p);
    res=1;
    for (int i=1;i<=n;i++)
    {
        //cout << "from " << i << endl;
        for (int j=1;j<=n;j++) Free[j]=1;
        tmp=0; Free[i]=0;
        flood(i);
        res=max(res,tmp);
    }
    cout << res<< endl;
    //for (int i=0;i<=n;i++) cout << groupof[i] << " ";
}
