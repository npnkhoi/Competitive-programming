//#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long

using namespace std;

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int tc,n;
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d",&n);
        while (n>=3)
        {
            printf("abc");
            n-=3;
        }
        if (n==1) printf("a\n");
        else if (n==2) printf("ab\n");
        else printf("\n");
    }
}
