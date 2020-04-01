using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
const int N =1e5 +10 ;
int n,a[N],f[N];
int res;
bool _greater(int a, int b)
{
    return (a>=b);
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        for (int i=0;i<(1<<n);i++)
        for (int j=0;j<n;j++) f[i]+=a[i^(1<<j)];
        res=0;
        for (int i=0;i<(2<<n);i++)
        for (int j=0;j<n;j++)
            res=max(res,f[i]+f[i^(1<<j)]);
        printf("%d\n",res);
    }

}
