using namespace std;
#include <stdio.h>
#include <iostream>
#include <stack>
const int N = 1e3+50;
int m,n;
int a[N],l[N],r[N];
stack<int> st;
int res;
char ch;
int main()
{
    freopen("MAXRECT.inp","r",stdin);
    freopen("MAXRECT.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++)
    {
        while (!st.empty()) st.pop();
        for (int j=1;j<=n;j++)
        {
            scanf(" %c",&ch); //cout << ch;
            if (ch=='W') a[j]++; else a[j]=0;
            //-----------
            while ((!st.empty())&&a[st.top()]>=a[j])
                r[st.top()]=j, st.pop();
            if (st.empty()) l[j]=0; else l[j]=st.top();
            st.push(j);
        }
        while (!st.empty()) r[st.top()]=n+1, st.pop();
        /*for (int j=1;j<=n;j++) cout << a[j] << " "; cout << endl;
        for (int j=1;j<=n;j++) cout << l[j] << " "; cout << endl;
        for (int j=1;j<=n;j++) cout << r[j] << " "; cout << endl;
        cout << endl;*/
        for (int j=1;j<=n;j++) res=max(res,(r[j]-l[j]-1)*a[j]);
    }
    cout << res;
}
