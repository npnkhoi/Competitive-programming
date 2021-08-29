#include <bits/stdc++.h>
using namespace std;
int maxN=100005;
int m[100005],M[100005];
int n,avr,sum,res;
int main()
{
    //freopen("10C.inp","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&m[i]);
    sort(m+1,m+n+1);
    sum=0;
    for (int i=1;i<=n;i++) sum+=m[i];
    avr=sum/n;
    for (int i=1;i<=n;i++) M[i]=avr;
    for (int i=1;i<=sum%n;i++) M[n-i+1]++;
    res=0;
    for (int i=1;i<=n;i++) res+=abs(m[i]-M[i]);
    res/=2;
    printf("%d",res);
}
