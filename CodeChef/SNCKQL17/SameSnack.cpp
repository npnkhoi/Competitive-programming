#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("samesnack.inp","r",stdin);
    //freopen("","w",stdout);
    int T,a,b,c,d,x,y,z,t;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d%d%d%d",&x,&y,&z,&t);
        if (((a==x)&&(b==y))||((a==z)&&(b==t))||((c==x)&&(d==y))||((c==z)&&(d==t)))
        {   printf("yes\n"); continue;}
        if ((b==d)&&(y==t)&&(b==y))
        {
            if (((x-a)*(x-c)<=0)||((z-a)*(z-c)<=0)||((a-x)*(a-z)<=0)||((c-x)*(c-z)<=0))
            {
                printf("yes\n");
                continue;
            }
        }
        if ((a==c)&&(x==z)&&(a==x))
        {
            if (((y-b)*(y-d)<=0)||((t-b)*(t-d)<=0)||((b-y)*(b-t)<=0)||((d-y)*(d-t)<=0))
            {
                printf("yes\n");
                continue;
            }
        }
        printf("no\n");
    }
}
