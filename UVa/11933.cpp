using namespace std;
#include <stdio.h>
int n,a,b;
bool cnt;
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0) break;
        a = b = 0;
        cnt = 0;
        while (n)
        {
            cnt^=1;
            //printf("%d %d\n",cnt,n&(-n));
            if (cnt) a+=n&(-n); else b+=n&(-n);
            n-= n&(-n);
        }
        printf("%d %d\n",a,b);
    }
}
