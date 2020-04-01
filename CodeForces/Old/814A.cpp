#include <stdio.h>
int n,m;
int a[200];
bool inc_seq;
int main()
{
    scanf("%d%d",&n,&m);
    if (m>1) printf("Yes");
    else
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int tmp;
        scanf("%d",&tmp);
        for (int i=0;i<n;i++) if (a[i]==0) a[i]=tmp;
        inc_seq=1;
        for (int i=1;i<n;i++) if (a[i-1]>=a[i]) inc_seq=0;
        (inc_seq) ? printf("No") : printf("Yes");
    }
}
