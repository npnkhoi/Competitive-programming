#include <bits/stdc++.h>
using namespace std;
int m,n,a[10050];
int main()
{
    scanf("%d%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    bool Dec=1;
    for (int i=1;i<n;i++)
    {
        if (a[i]>=a[i-1]) Dec=0;

    }
    if (Dec) printf("-1");
    else{
        next_permutation(a,a+n);
        for (int i=0;i<n;i++) printf("%d ",a[i]);
    }

}
