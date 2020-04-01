#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7;
const int ooo=-(1e9);
int a[N],f[N],num;
int n,res,l,r,mid;
void show(int i, int vt)
{
    while (a[vt]<f[i]) vt--;
    if (i>1) show(i-1,vt-1);
    printf("%d\n",a[vt]);

}
int main()
{
    freopen("00481.inp","r",stdin);
    //freopen("","w",stdout);
    n=0;
    while (scanf("%d",&num)!=EOF)
    {
        n++;
        a[n]=num;
    }
    //==================================
    f[1]=a[1]; res=1; f[0]=ooo;
    for (int i=2;i<=n;i++)
    {
        l=0; r=res;
        while (l<r)
        {
            mid=(l+r+1)/2;
            if (f[mid]<a[i]) l=mid;
            else r=mid-1;
        }
        //============================
        if ((f[l]<a[i])&&((a[i]<f[l+1])||(l==res)))
        {
            //cout<<f[l]<<" "<<a[i]<<"\t";
            f[l+1]=a[i];
            if (l==res) res++;
        }
        //for (int i=1;i<=res;i++) printf("%d ",f[i]); cout<<endl;
    }
    printf("%d\n-\n",res);
    for (int i=1;i<=res;i++) printf("%d\n",f[i]); cout<<endl;

    //show(res,n);
}
