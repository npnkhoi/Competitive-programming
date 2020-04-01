// Thinnk carefully ... Are you ready?

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define ll long long
using namespace std;

//==================<< END OF TEMPLATE >>========================
int tc,u,v,f[20];



//---------------------------------------------------------------
int main()
{
    freopen("","r",stdin);
    freopen("","w",stdout);
    f[0]=1; f[1]=1;
            for (int i=2;i<=19;i++) f[i]=(f[i-1]+f[i-2])%7;
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d%d",&u,&v);
        int s=v-u+1;
        if (s>=32)
            printf("%d\n",s-s%16);
        else
        {
            bool ok=0;
            for (int i=u;i<v;i++) if (f[i%16]==f[(i+1)%16]) ok=1;
            if (ok) printf("2\n");
            else printf("-1\n");
        }
    }



    return 0;
}

// Accepted in one hit, or be a silly dog :))
