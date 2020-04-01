using namespace std;
#include <stdio.h>
#include <algorithm>
const int N = 1e5 + 20;
const int A = 2e5 + 20;
int a[N], l[A], r[A], id[A];
int IT[4*A], f[A];
int n, q, m, ql, qr;
void debug(int a[], int n)
{
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}

int left(int p) { return p<<1; }
int right(int p) {return (p<<1) + 1; }

void build(int p, int l, int r)
{
    if (l==r) IT[p] = l;
    else
    {
        build(left(p), l, (l+r)/2);
        build(right(p), (l+r)/2+1, r);
        int p1 = IT[p<<1];
        int p2 = IT[(p<<1)+1];
        IT[p]= (f[p1] < f[p2])? p2:p1;
    }
}
int rm(int p, int l, int r, int L, int R)
{
    if (r<L || R<l) return -1;
    if (L<=l && r<=R) return IT[p];
    int p1 = rm( left(p), l, (l+r)/2, L, R);
    int p2 = rm( right(p), (l+r)/2+1, r, L, R);
    if (p1==-1) return p2;
    if (p2==-1) return p1;
    return (f[p1] > f[p2])? p1 : p2;
}
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    while (1)
    {
        scanf("%d",&n); if (n==0) break;
        scanf("%d",&q);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        ///////////////////////////////////////////////
        id[a[1]] = 1; m = 1;
        for (int i=2;i<=n;i++) if (a[i]!=a[i-1])
        {
            int x = id[a[i]] = ++m;
            r[x-1] = i-1;
            l[x] = i;
        }
        l[1] = 1; r[m] = n;
        for (int i = 1; i<=m;i++) f[i] = r[i]-l[i]+1;
        //debug(f,m);
        //printf("1");
        build(1,1,m);
        //debug(IT, 8);
        //printf("1");
        //printf("%d\n", rm(1,1,n,2,3));
        //==================================
        while (q--)
        {
            scanf("%d%d",&ql,&qr);
            int id_left = id[a[ql]];
            int id_right= id[a[qr]];
            //printf(" %d %d \n",id_left,id_right);
            int res = max(
                          min(qr, r[id_left]) - ql + 1,
                          qr - max(ql,l[id_right]) + 1
                          );
            if (id_right - id_left > 1) res = max(res, f[rm(1,1,m,id_left+1, id_right-1)]);
            printf("%d\n",res);
        }
    }
}
