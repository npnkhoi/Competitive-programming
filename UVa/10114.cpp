#include <stdio.h>
#include <iostream>
using namespace std;
int n,t,B,month;
float a,b,dep;

int main()
{
    freopen("10114.inp","r",stdin);
    while (scanf("%d%f%f%d",&n,&a,&b,&t)!=EOF)
        if ((n>=0)&&(a>=0)&&(b>=0)&&(t>=0))
    {
        float d[n+5];
        pair<int,float> D[t+5];
        for (int i=0;i<t;i++) scanf("%d%f",&D[i].first,&D[i].second);
        D[t].first=n+1;
        for (int i=0;i<t;i++)
            for (int j=D[i].first;j<D[i+1].first;j++)
                d[j]=D[i].second;
        for (int i=0;i<=n;i++) cout<<d[i]<<"\t";
        cout<<endl;
        float B=b+=a;
        for (int i=0;i<=n;i++)
        {
            B-=a;
            b*=(1-d[i]);
            cout<<B<<" "<<b<<"\t";
            if (B<b)
            {
                if (i==1) printf("%d month\n",i);
                    else printf("%d months\n",i);
                break;
            }
        }
    }
}
