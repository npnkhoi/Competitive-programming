#include <bits/stdc++.h>
using namespace std;
int n,a[15],gt[15];
bool ok()
{
    int maxx=a[1];
    for (int i=3;i<=n;i++)
    {
        maxx=max(maxx,a[i-2]);
        if (maxx>a[i]) return 0;
    }
    return 1;
}
void show()
{
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    freopen("BARCODE_REF.txt","w",stdout);
    for (n=1;n<=10;n++)
        {
            int cnt=1;
            for (int i=1;i<=n;i++) a[i]=i;
            gt[0]=1; for (int i=1;i<=n;i++) gt[i]=gt[i-1]*i;
            show();
            for (int i=2;i<=gt[n];i++)
            {
                next_permutation(a+1,a+n+1);
                if (ok())
                    {
                        show();
                        cnt++;
                    }
            }
            printf("------%d\n",cnt);
        }
}
