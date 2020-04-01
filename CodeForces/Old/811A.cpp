#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int i,a,b;
    scanf("%d%d",&a,&b);
    i=0;
    while (1)
    {
        i++; a-=i;
        if (a<0)
        {
            printf("Vladik");
            break;
        }
        i++; b-=i;
        if (b<0)
        {
            printf("Valera");
            break;
        }
    }

}
