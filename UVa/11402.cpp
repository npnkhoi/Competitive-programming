using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
const int N = 4e6+50;
int a[N];
int IT[N], lazy[N];
char cmd;
int m,n;
char str[200];
int ql,qr,q,TC;

int left(int p) { return p<<1; }
int right(int p) { return (p<<1)+1; }

void build(int p, int l, int r)
{
    //printf("build %d %d\n",l,r);

    if (l==r) IT[p] = a[l];
    else
    {
        int mid = (l+r)/2;
        build(left(p), l, mid);
        build(right(p), mid + 1, r);
        IT[p] = IT[left(p)]+ IT[right(p)];
    }
}
void change(char lenh, int p)
{
    if (lenh!='I') lazy[p] = lenh;
    else
        if (lazy[p] == 'E') lazy[p] = 'F';
    else if (lazy[p] == 'F') lazy[p] = 'E';
    else if (lazy[p] == 'I') lazy[p] = 0;
    else lazy[p] = 'I';
    //printf("change %c %d %c\n",lenh,p,lazy[p]);
}
void check(int p, int l, int r)
{
    if (lazy[p]==0) return;
        if (lazy[p] == 'I')     IT[p] = r-l+1 - IT[p];
    else if (lazy[p] == 'F')    IT[p] = r-l+1;
                    else        IT[p] = 0;
    if (l!=r)
    {
        change(lazy[p], left(p));
        change(lazy[p], right(p));
    }
    lazy[p] = 0;
    /*for (int i=1;i<=2*n;i++) printf("%d ",IT[i]); cout << endl;
    for (int i=1;i<=2*n;i++) if (lazy[i]) printf("%c ",lazy[i]);
    else cout << 0 << " ";
    cout << endl;*/
}
void update(int p, int l, int r, int L, int R)
{
    //cerr << cmd << " " << p << " " << l << " " << r << " " << L << " " << R <<  endl;
    check(p, l, r);
    //-----------------------------------
    if (r<L || R<l || l>r) return;

    if (L<=l && r<=R)
    {
        if (cmd == 'I') IT[p] = r-l+1 - IT[p];
        else if (cmd == 'F') IT[p] = r-l+1;
        else IT[p] = 0;
        if (l!=r) change(cmd, left(p)), change(cmd, right(p));
        //cout << "update end: " << IT[p] << endl;
    }
    else
    {
        int mid = (l+r) / 2;
        update(left(p), l , mid, L, R);
        update(right(p), mid + 1, r, L, R);
        IT[p] = IT[left(p)] + IT[right(p)];
        //cout << "update recur: " << IT[p] << endl;
    }
    //cout << "--------------" << endl;

}
int ans(int p, int l, int r, int L, int R)
{
    //cerr << cmd << " " << p << " " << l << " " << r << " " << L << " " << R <<  endl;
    check(p, l, r);
    if (r<L || R<l || l>r) return 0;
    if (L<=l && r<=R) return IT[p];
    int mid = (l+r)/2;
    return ans(left(p),l,mid,L,R) + ans(right(p),mid+1,r,L,R);
}
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        n = 0;
        scanf("%d",&m);
        while (m--)
        {
            int re;
            scanf("%d %s",&re,str);
            //cout << re << " " << str << endl;
            while (re--)
            for (int j=0;j<strlen(str);j++,n++) a[n]=(str[j]=='1') ;
            //printf("n= %d\n",n);
        }

        //for (int i=0;i<n;i++) printf("%d ",a[i]); cout << endl;
        build(1,0,n-1);
        //for (int i=1;i<=2*n;i++) printf("%d ",IT[i]); cout << endl;
        //-------------------------
        memset(lazy,0,sizeof lazy);
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        int z = 0;
        while (q--)
        {
            scanf(" %c %d %d", &cmd, &ql, &qr);
            if (cmd=='S') printf("Q%d: %d\n",++z, ans(1,0,n-1,ql,qr));
            else update(1,0,n-1,ql,qr);
            /*for (int i=1;i<=2*n;i++) printf("%d ",IT[i]); cout << endl;
            for (int i=1;i<=2*n;i++) if (lazy[i]) printf("%c ",lazy[i]);
            else cout << 0 << " ";
            cout << endl;*/
        }
        //cout << "---------------" << endl;
    }
}
