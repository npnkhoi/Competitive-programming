using namespace std;
#include <iostream>
#include <stdio.h>
#include <math.h>
int l,r;
int main()
{
    scanf("%d%d",&l,&r);
    if (l==r && l%2)
    {
        for (int i=3;i<=sqrt(l)+1;i++) if (l%i==0)
        {
            printf("%d",i);
            return 0;
        }
        cout << l;
        return 0;

    }
    else cout << 2;
}
