#include <bits/stdc++.h>
using namespace std;
const int oo=2000000000;
int n,K,res,tmp;
int a[310],b[310],c[310];
int cost(int a, int b)
{
    if (a>b) return b-a+K+1;
    else return b-a;
}
int main()
{
    freopen("KHOAK.INP","r",stdin);
    freopen("KHOAK.OUT","w",stdout);
    scanf("%d%d",&n,&K);
    res=oo;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int j=0;j<n;j++) scanf("%d",&b[j]);
    for (int k=0;k<n;k++)
    {
        int kq=oo;
        for (int i=0;i<n;i++)
        {
            c[i]=cost(a[(i-k+n)%n],b[i]);
            //cout<<c[i]<<"\t";
        }
        //cout<<endl;
        for (int i=0;i<n;i++)
        {
            tmp=c[i];
            for (int j=0;j<n;j++) tmp+=cost(c[i],c[j]);
            kq=min(kq,tmp);
        }

        res=min(res,k+kq);
    }
    printf("%d",res);
}
