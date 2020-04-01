using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
const int N = 4e6+50;
vector<int> a;
int IT[N], lazy[N];
char cmd;
int m,n;
char str[60];
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
void change(int p)
{
    if (cmd=='F') lazy[p] = 2;
    else if (cmd=='E') lazy[p] = 1;
    else
        switch(lazy[p])
        {
            case 1: lazy[p] = 2;
            case 2: lazy[p] = 1;
            case -1: lazy[p] = 0;
            case 0: lazy[p] = -1;
        }

}
void update(int p, int l, int r, int L, int R)
{
    if (r<L || R<l) return;
    if (lazy[p])
    {
        switch (lazy[p])
        {
            case 'E': IT[p] = 0;
            case 'F': IT[p] = r-l+1;
            case 'I': IT[p] = r-l+1 - IT[p];
        }
        change(p,left(p));
        change(p,right(p));

    }


    if (L<=l && r<=R)
    {
        change(left(p));
        change(right(p));
    }
    else
    {
        int mid = (l+r) / 2;
        update(left(p), l, mid, L, R);
        update(right(p), mid+1, r, L, R);
        IT[p]= IT[left(p)] + IT[right(p)];
    }
    switch (lazy[p])
        {
            case 1: IT[p] = 0;
            case 2: IT[p] = r-l+1;
            case -1: IT[p] = r-l+1 - IT[p];
        }
    lazy[p] = 0;
}
int ans(int p, int l, int r, int L, int R)
{
    if (r<L || R<l) return 0;
    if (L<=r && r<=R) return IT[p];
    int mid = (l+r)/2;
    return ans(left(p),l,mid,L,R) + ans(right(p),mid+1,r,L,R);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        scanf("%d",&m);
        while (m--)
        {
            scanf("%d %s",&n,str);
            for (int i=1;i<=n;i++)
            for (int j=0;j<strlen(str);j++) a.push_back(str[j]=='1');
        }
        n = a.size();
        for (int i=0;i<n;i++) printf("%d ",a[i]); cout << endl;
        build(1,0,n-1);
        for (int i=1;i<=2*n;i++) printf("%d ",IT[i]); cout << endl;
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
        }
        cout << "---------------" << endl;

    }

}
