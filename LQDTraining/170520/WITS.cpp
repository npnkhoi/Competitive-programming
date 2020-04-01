#include <bits/stdc++.h>
using namespace std;
long long s;
int gt[10];
int a[10];
int nt[4]={2,3,5,7};
int x;
int main()
{
    freopen("WITS.inp","r",stdin);
    //freopen("","w",stdout);
    gt[0]=1;
    for (int i=1;i<=9;i++) gt[i]=gt[i-1]*i;
    //================================
    scanf("%lld",&s);
    scanf("%lld",&s);
    memset(a,0,sizeof(a));
    while (s)
    {
        x=gt[s%10]; //cout<<x<<" ";
        s/=10;
        for (int i=3;i>=0;i--)
        while (x%gt[nt[i]]==0) {
            a[nt[i]]++; x/=gt[nt[i]];
        }
    }
    for (int i=7;i>=2;i--)
        for (int j=1;j<=a[i];j++) printf("%d",i);
}
