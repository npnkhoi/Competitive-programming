 #include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[150],n,res,s;
bool ok;
int main()
{
    //freopen("00787.inp","r",stdin);
    //freopen("","w",stdout);
    while (scanf("%d",&a[1])!=EOF)
    {
        n=1;
        while (1)
        {
            //cout<<"reach";
            n++;
            scanf("%d",&a[n]);
            if (a[n]==-999999) break;
        }
        n--;

        //====================================
        s=0; res=0;
        for (int i=1;i<=n;i++)
        {
            s+=a[i];
            if (s<0) s=0;
            else res=max(res,s);
        }
        if (res>0) printf("%d\n",res);
        //===================================
        ok=false;
        if (res==0)
        {
            for (int i=1;i<=n;i++)
                if (a[i]==0)
            {
                ok=true;
                break;
            }
            if (ok) printf("0\n");
            else
            {
                res=a[1];
                for (int i=2;i<=n;i++) res=min(res,a[i]);
                printf("%d\n",res);
            }
        }
    //Big Integerrrrr!!!!!!!!
    }
}
