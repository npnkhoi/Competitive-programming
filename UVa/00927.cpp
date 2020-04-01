#include <stdio.h>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int C,c[25];
string line;
int main()
{
    //freopen("00927.inp","r",stdin);
    //freopen("00927.out","w",stdout);
    scanf("%d",&C);
    while (C--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<=n;i++)
        {
            scanf("%d",&c[i]);
            //cout<<i<<" "<<c[i]<<endl;
        }

        //------------------- BSEARCH
        int k,d;
        scanf("%d%d",&d,&k);
        //printf("d=%d k=%d\n",d,k);
        int value=2*k;
        long long l,r,mid;
        l=0; r=1e3;
        while (l<r)
        {
            mid = (l+r)/2;
            long long x=d*mid*(mid+1);
            if (d*mid*(mid+1)>=value)
                r=mid;
            else l=mid+1;
            //printf("l=%lld r=%lld\n",l,r);
        }
        //cout<<l<<endl;
        //-------------------RESULT
        long long Exp=1;
        long long a=c[0];
        for (int i=1;i<=n;i++)
        {
            Exp*=l;
            a+=c[i]*Exp;
            //cout<<Exp<<" "<<a<<endl;
        }
        printf("%lld\n",a);
        //if (C) printf("\n");
    }
}
