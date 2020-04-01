// Thinnk carefully ... Are you ready?

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define ll long long
using namespace std;
//==================<< END OF TEMPLATE >>========================
double a,k,b;

//--------------<<ENF OF VARIABLES DECLARATION >>-----------------
int main()
{
    freopen("","r",stdin);
    freopen("","w",stdout);
    scanf("%lf %lf %lf",&a,&k,&b);
    a=abs(a);
    if (k==1)
    {
        if (a!=0) printf("0");
        else printf("1");
        return 0;
    }
    if (a==0) printf("-1");

    int res=ceil((k-1)*log(b)/log(a));
    int res_=ceil((k)*log(b)/log(a));
    //cout<< res << " " << res_ << endl;
    if (res!=res_)
        printf("%d",res);
    else printf("-1");
    return 0;
}

// Accepted in one hit, or be a silly dog :))
/*
scanf("%d %d %d",&a,&k,&b);
    s=1;
    for (int i=1;i<=k-1;i++) s*=b;
    x=1; res=0;
    while (x<s)
    {
        x*=a;
        res++;
    }
    cout<<res;
*/
