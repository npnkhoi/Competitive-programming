#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int tc,a[15],n;
    //freopen("01225.inp","r",stdin);
    scanf("%d",&tc);
    while (tc--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x=i;
            while (x){a[x%10]++; x/=10;}
        }

        for (int i=0;i<9;i++) printf("%d ",a[i]);
        printf("%d\n",a[9]);
    }
}
