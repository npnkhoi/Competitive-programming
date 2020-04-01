#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n,k,mark,sum;
    scanf("%d%d",&n,&k);
    sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&mark);
        sum+=mark;
    }
    if (round(1.0*sum/n)==k)
    printf("0"); else printf("%d",(k+k-1)*n-sum-sum);
}

