#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    long long p,q,a,b,by,y,x;
    int tc;
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&p,&q);
        if (p==q)
        {
            if (a==b) printf("0\n");
                else printf("-1\n");
            continue;
        }
        y=(b*p-a*q+q-p-1)/(q-p);
        if (y<0) y=0;
        //cout<<"y="<<y<<endl;
        by=b+y;
        //cout<<"by="<<by<<endl;
        by=((by+q-1)/q)*q;
        y=by-b;
        printf("%lld\n",y);
    }
}
