#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e6+50;
int n,a[N];
stack<int> s;
int leftmin[N],rightmin[N],leftmax[N],rightmax[N];
int r1,r2,l1,l2;
ll res;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    //=================================
    while (!s.empty()) s.pop();
    for (int i=1;i<=n;i++)
    {
        while (!s.empty()&&(a[s.top()]>=a[i])) s.pop();
        if (s.empty()) leftmin[i]=0;
        else leftmin[i]=s.top();
        s.push(i);
    }
    //=================================
    while (!s.empty()) s.pop();
    for (int i=n;i>=1;i--)
    {
        while (!s.empty()&&(a[s.top()]>a[i])) s.pop();
        if (s.empty()) rightmin[i]=n+1;
        else rightmin[i]=s.top();
        s.push(i);
    }
    //=================================
    while (!s.empty()) s.pop();
    for (int i=1;i<=n;i++)
    {
        while (!s.empty()&&(a[s.top()]<=a[i])) s.pop();
        if (s.empty()) leftmax[i]=0;
        else leftmax[i]=s.top();
        s.push(i);
    }
    //=================================
    while (!s.empty()) s.pop();
    for (int i=n;i>=1;i--)
    {
        while (!s.empty()&&(a[s.top()]<a[i])) s.pop();
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
        res+=1LL*a[i]*(1LL*(r2-i)*(i-l2)-1LL*(r1-i)*(i-l1));
        //cout << res << endl;
    }
    cout << res;
    return 0;
}
/* -----BACKUP -------------

*/

