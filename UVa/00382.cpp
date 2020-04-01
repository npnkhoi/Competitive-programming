#include <stdio.h>
#include <iostream>
using namespace std;
int n;
long long s;
int main()
{
    //freopen("00382.inp","r",stdin);
    //freopen("00382.out","w",stdout);
    printf("PERFECTION OUTPUT\n");
    while (1)
    {
    scanf("%d",&n); if (n==0) break;
    //========================================
    printf("%5d  ",n);
    long long s=0;
    for (int i=1;i<n;i++) if (n%i==0) s+=i;
    if (s==n) printf("PERFECT\n");
    else if(s<n) printf("DEFICIENT\n");
    else printf("ABUNDANT\n");
    //cout<<s<<endl;
    }
    printf("END OF OUTPUT\n");
}
