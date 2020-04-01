#include <stdio.h>
using namespace std;
int main()
{
    int T;
    long long a,b;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld",&a,&b);
        if (a<b) printf("<\n");
        else
        {
            if (a>b) printf(">\n");
            else printf("=\n");
        }
    }
}//3
