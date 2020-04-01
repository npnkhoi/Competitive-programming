#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n;
    scanf("%d",&n);
    int s=0;
    for (int i=1;i<n;i++)
    {
        s+=!(n%i)*i;
        //printf("%d %d\n",i,s);
    }

    if (s==n)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
