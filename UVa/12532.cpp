using namespace std;
#include <stdio.h>
#include <set>
#include <string.h>
#include <iostream>
const int N = 1e6 + 50;
int n, q;
int a[N],ft[N];
set<int> data;
void update(int i, int v)
{
    //printf("update %d\n",i);
    for (; i <=n+2; i+= (i&(-i))) ft[i]+=v;
}
int rsum(int x)
{
    //printf("rsum %d\n",x);
    int s = 0;
    for (; x; x -= (x&(-x))) s+= ft[x];
    //cout << "ok" << endl;
    return s;
}
int rsum(int l, int r)
{
    return rsum(r)- ((l==1) ? 0 : rsum(l-1));
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    while (scanf("%d %d",&n, &q)!=EOF)
    {
        memset(ft,0,sizeof(ft));
        data.clear();
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x<0) a[i] = -1;
            else if (x>0) a[i] = 1;
            //---------------------
            if (x<0) update(i, 1);
            if (x==0) data.insert(i);
        }
        //---------------------
        while (q--)
        {
            char ch;
            scanf(" %c", &ch);
            //cout << ch << "--\n";
            if (ch == 'C')
            {
                int i, v;
                scanf("%d %d",&i,&v);
                if (v<0) v=-1;
                else if (v>0) v=1;
                if (a[i] == v) continue;
                if (data.find(i)!=data.end() && v!=0) data.erase(i);
                else if (data.find(i)==data.end() && v==0) data.insert(i);
                //------------------
                if (a[i]<0 && v>=0) update(i, -1);
                else if (a[i]>=0 && v<0) update(i, 1);
                a[i] = v;
            }
            else
            {
                int l, r;
                scanf("%d %d",&l, &r);
                if (data.lower_bound(l)!=data.end()
                    && *data.lower_bound(l) <= r) printf("0");
                else if (rsum(l,r)%2) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
}
