// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================
const int N=4e5+50;
int n,a[N];
stack<int> s;
int leftmin[N],rightmin[N],leftmax[N],rightmax[N];
int r1,r2,l1,l2;
ll res;

//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    freopen("weight.inp","r",stdin);
    freopen("weight.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    //=================================
    while (!s.empty()) s.pop();
    for (int i=1;i<=n;i++)
    {
        while (!s.empty()&&(s.top()>=a[i])) s.pop();
        if (s.empty()) leftmin[i]=0;
        else leftmin[i]=s.top();
        s.push(i);
    }
    //=================================
    while (!s.empty()) s.pop();
    for (int i=n;i>=1;i--)
    {
        while (!s.empty()&&(s.top()>=a[i])) s.pop();
        if (s.empty()) rightmin[i]=n+1;
        else rightmin[i]=s.top();
        s.push(i);
    }
    //=================================
    while (!s.empty()) s.pop();
    for (int i=1;i<=n;i++)
    {
        while (!s.empty()&&(s.top()<=a[i])) s.pop();
        if (s.empty()) leftmax[i]=0;
        else leftmax[i]=s.top();
        s.push(i);
    }
    //=================================
    while (!s.empty()) s.pop();
    for (int i=n;i>=1;i--)
    {
        while (!s.empty()&&(s.top()<=a[i])) s.pop();
        if (s.empty()) rightmax[i]=n+1;
        else rightmax[i]=s.top();
        s.push(i);
    }
    res=0;
    for (int i=1;i<=n;i++)
    {
        r1=rightmin[i];
        r2=rightmax[i];
        l1=leftmin[i];
        l2=leftmax[i];
        //printf("%d %d %d %d\n",l1,r1,l2,r2);
        res+=a[i]*((r2-l2-2)-(r1-l1-2));
        //cout << res << endl;
    }
    printf("%lld",res);
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
