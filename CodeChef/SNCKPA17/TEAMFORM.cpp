//#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long

using namespace std;

int main()
{
    //freopen("teamform.inp","r",stdin);
    //freopen("","w",stdout);
    int tc,n,m,u,v;
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++) scanf("%d%d",&u,&v);
        if ((n-2*m)%2) printf("no\n");
        else printf("yes\n");
    }
}
