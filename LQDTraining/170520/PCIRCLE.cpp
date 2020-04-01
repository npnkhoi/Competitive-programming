#include <bits/stdc++.h>
using namespace std;
bool nt[40]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
bool Free[20]={1},show;
int n;
long long res;
int a[20];
void check_and_show()
{
    if (nt[a[2*n]+1])
    {
        res++;
        if (show&&(res<=10000)){
            for (int i=1;i<=2*n;i++) printf("%d ",a[i]);
            printf("\n");
        }

    }
}
void Try(int i)
{
    //cout<<i<<endl;
    for (int j=2;j<=2*n;j++) if (nt[a[i-1]+j]&&Free[j])
    {
        //cout<<j<<endl;
        a[i]=j; Free[j]=0;
        //cout<<"reach"<<endl;
        if (i==2*n) check_and_show();
        else Try(i+1);
        Free[j]=1;
    }
}
int main()
{
    //freopen("PCIRCLE.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    memset(Free,1,sizeof(Free));
    a[1]=1; Free[1]=0;
    //==========================
    show=0; res=0;
    Try(2);
    printf("%lld\n",res);
    res=0; show=1;
    Try(2);
}
