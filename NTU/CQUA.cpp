#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    //freopen("cqua.inp","r",stdin);
    //freopen("","w",stdout);
    int n;
    scanf("%d",&n);
    int a[105];
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int s=0;
    bool le=0;
    for (int i=1;i<=n;i++)
    {
        s+=a[i]/100;
        le=le||(a[i]==100);
        //printf("%d ",le);
    }
    //printf("%d %d\n",s,le);
    if ((s%4==0)||((s%2==0)&&le)) {printf("YES");}
    else printf("NO");
    return 0;
}
