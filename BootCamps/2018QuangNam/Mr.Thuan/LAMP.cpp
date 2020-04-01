// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================
const int N=1e5+50;
int a[N],n,x,y,q,s;

//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    freopen("","r",stdin);
    freopen("","w",stdout);
    scanf("%d%d",&n,&q);
    while (q--)
    {
        scanf("%d%d",&x,&y);
        a[x]++;
        a[y+1]++;
    }
    s=0;
    for (int i=1;i<=n;i++)
    {
        s+=a[i];
        printf("%d ",a[i]%2);
    }
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
