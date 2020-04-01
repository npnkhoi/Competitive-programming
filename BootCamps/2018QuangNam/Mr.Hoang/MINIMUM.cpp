using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
const int N = 5e5 + 50;
int a[N];
long long res;
int n, x;
deque<int> dq;
int main()
{
    freopen("minimum.inp","r",stdin);
    freopen("minimum.out","w",stdout);
    scanf("%d %d", &n, &x);
    //cout << x << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        while ((!dq.empty()) && a[dq.back()]>=a[i]) dq.pop_back();
        if ((!dq.empty()) && (dq.front()<=i-x)) dq.pop_front();
        dq.push_back(i);
        //f[i] = a[dq.front()];
        //cout << f[i] << " ";
        if (i>=x) printf("%d\n",a[dq.front()]);
    }
}
/*using namespace std;
#include <stack>
#include <stdio.h>
#include <iostream>
int n,k;
const int N = 5e5 + 10;
int a[N],l[N],r[N],res[N];
stack<int> st;
int main()
{
    freopen("MINIMUM.inp","r",stdin);
    freopen("MINIMUM.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        while ((!st.empty())&&a[st.top()]>=a[i])
        {
            r[st.top()]=i; st.pop();
        }
        if (st.empty()) l[i]=0; else l[i]=st.top();
        st.push(i);
    }
    while (!st.empty()) r[st.top()]=n+1, st.pop();
    for (int i=1;i<=n;i++)
    {
        for (int j=l[i]+k;j<r[i];j++) if (j-k<i&&i<=j) res[j]=a[i];
    }
    for (int i=k;i<=n;i++) printf("%d\n",res[i]);
}
*/
