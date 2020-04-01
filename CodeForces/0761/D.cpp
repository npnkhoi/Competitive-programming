using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
int n,l,r,prec;
const int N = 1e5 +50 ;
int t[N],a[N],b[N],ord[N];
int main()
{
    //freopen("761D.inp","r",stdin);
    scanf("%d%d%d",&n,&l,&r);
    for (int i=1;i<=n;i++) scanf("%d",&t[i]);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&ord[i]);
        a[ord[i]]=t[i];
    }
    //for (int i=1;i<=n;i++) cout << a[i] << " ";
    //cout << endl;
    b[n]=r;
    //cout << b[n] << " ";
    for (int i=n-1;i>=1;i--)
    {
        int c_now=b[i+1]-a[i+1]-1;
        //cout << c_now << " ";
        b[i]=min(c_now+a[i],r);
        //cout << b[i] << endl;
        if (b[i]<l)
        {
            cout << -1;
            return 0;
        }
    }
    for (int i=1;i<=n;i++) printf("%d ",b[ord[i]]);
    return 0;

}
