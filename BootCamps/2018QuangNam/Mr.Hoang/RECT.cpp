using namespace std;
#include <stack>
#include <stdio.h>
#include <iostream>
const int N = 5e5+10;
int n,m,a[N];
stack<int> st;
int l[N],r[N];
long long res;
int main()
{
    freopen("RECT.inp","r",stdin);
    freopen("RECT.out","w",stdout);
    scanf("%d%d",&m,&n);
    //cout << m << n << endl;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    //cout << 177 << endl;
    for (int i=1;i<=n;i++)
    {
        while ((!st.empty())&&(a[st.top()]>=a[i]))
                r[st.top()]=i, st.pop();

        //cout << st.empty() << "." << endl;
        if (st.empty()) l[i]=0; else l[i]=st.top();
        //cout << 2 << endl;
        st.push(i);
        //cout << 3 << endl;
    }

    while (!st.empty()) r[st.top()]=n+1, st.pop();
    for (int i=1;i<=n;i++) res=max(res,1LL*(r[i]-l[i]-1)*a[i]);
    //cout << 177 << endl;


    for (int i=1;i<=n;i++) a[i]=m-a[i];
    while (!st.empty()) st.pop();
    //cout << 177 << endl;

    for (int i=1;i<=n;i++)
    {
        while ((!st.empty())&&(a[st.top()]>=a[i]))
            r[st.top()]=i, st.pop();
        //cout << st.empty() << "." << endl;
        if (st.empty()) l[i]=0; else l[i]=st.top();
        st.push(i);
    }
    while (!st.empty()) r[st.top()]=n+1, st.pop();
    for (int i=1;i<=n;i++) res=max(res,1LL*(r[i]-l[i]-1)*a[i]);
    cout << res;

}
