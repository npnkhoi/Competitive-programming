using namespace std;
#include <stdio.h>
#include <iostream>
#include <stack>
int n;
const int N =4e5+50;
int a[N],l[N],r[N];
long long res;
stack<int> st;
int main()
{
    freopen("weight.inp","r",stdin);
    freopen("weight.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        while ((!st.empty())&&a[st.top()]>=a[i]) st.pop();
        if (st.empty()) l[i]=0; else l[i]=st.top();
        st.push(i);
    }
    //---------------------------------------------
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--)
    {
        while ((!st.empty())&&a[st.top()]>a[i]) st.pop();
        if (st.empty()) r[i]=n+1; else r[i]=st.top();
        st.push(i);
    }
    for (int i=1;i<=n;i++) res-=1LL*a[i]*(i-l[i])*(r[i]-i);
    //---------------------------------------------
    while (!st.empty()) st.pop();
    for (int i=1;i<=n;i++)
    {
        while ((!st.empty())&&a[st.top()]<=a[i]) st.pop();
        if (st.empty()) l[i]=0; else l[i]=st.top();
        st.push(i);
    }
    //---------------------------------------------
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--)
    {
        while ((!st.empty())&&a[st.top()]<a[i]) st.pop();
        if (st.empty()) r[i]=n+1; else r[i]=st.top();
        st.push(i);
    }
    for (int i=1;i<=n;i++) res+=1LL*a[i]*(i-l[i])*(r[i]-i);
    cout << res;
}
