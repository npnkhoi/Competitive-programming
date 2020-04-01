#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
    int T,a[4];
    scanf("%d",&T);
    for (int i=1;i<=T;i++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        //printf("%d %d %d\n",a[0],a[1],a[2]);
        sort(a,a+3);
        //printf("%d %d %d\n",a[0],a[1],a[2]);
        printf("Case %d: %d\n",i,a[1]);
    }
}
