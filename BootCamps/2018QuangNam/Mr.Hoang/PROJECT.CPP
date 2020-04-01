using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
const int N = 1e6 + 50;
int a[N],b[N],f[N];
long long res;
int n, H, S, D;
deque<int> dq;
int main()
{
    freopen("project.inp","r",stdin);
    freopen("project.out","w",stdout);
    scanf("%d %d %d %d", &n, &H, &S, &D);
    int x = (H+D) / S;
    //cout << x << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        while ((!dq.empty()) && a[dq.back()]<=a[i]) dq.pop_back();
        if ((!dq.empty()) && (dq.front()<i-x)) dq.pop_front();
        dq.push_back(i);
        f[i] = a[dq.front()];
        //cout << dq.front() << " ";
    }
    for (int i=1;i<=x;i++)
    {
        if ((!dq.empty()) && (dq.front()+x<n+i)) dq.pop_front();
        f[n+i] = a[dq.front()];
        //cout << dq.front() << " ";
    }
    //cout << endl;
    res = 0; b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i-1] <= a[i]) b[i] = a[i];
            else b[i] = min(b[i-1], f[i+x]);
        //cout << b[i] << " ";
        if (b[i-1] < b[i]) res += 1LL * (b[i]-b[i-1]) * H;
        else res += 1LL * (b[i-1] - b[i]) * D;
        res += 1LL*b[i]*S;
    }
    //cout << endl;
    res += 1LL * b[n] * D;
    cout << res << endl;
    for (int i = 1; i <= n; i++) printf("%d ",b[i]);
}
/*using namespace std;

long long sol(int u, int v)
{

}
int main()
{
    scanf("%d %d %d %d", &n, &h, &s, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        while ((!st.empty()) && a[st.top()]<=a[i])
        {
            r[st.top()] = i;
            st.pop();
        }
        if (s.empty()) l[i] = 0; else l[i] = st.pop();
        st.push(i);
    }
    while (!st.empty())
    {
        r[st.top()] = n+1;
        st.pop();
    }
    //==============================================
    cout << sol(1,n);
}
*/
/*using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
const int N = 4e5 + 50;
int a[N], n, H, S, D;
int memo[N];
long long tran(int a, int b)
{
    if (a<b) return 1LL * (b-a) * H;
    else if (a>b) return 1LL * (a-b) * D;
    else return 0LL;
}
long long f(int u, int v, int h)
{
    //printf("f (%d, %d, %d): \n",u,v,h);
    if (u>v) return 0;
    long long Old, New, s;
    int i,j;
    Old = tran(a[u-1], h) + 1LL * S * h * (v-u+1) + tran(h, a[v+1]);
    //printf("Old = %lld+%lld+%lld\n",tran(a[u-1],h),1LL * S*(v-u+1),tran(h,a[v+1]));
    //======================================
    int MAX = a[u];
    for (int i=u+1;i<=v;i++) MAX = max (MAX, a[i]);
    //printf("MAX = %d\n",MAX);
    //----------------
    //printf("New = %lld+%lld+%lld\n",tran(a[u-1],MAX),1LL * S*(v-u+1),tran(MAX,a[v+1]));
    New = tran(a[u-1],MAX) + 1LL * S * MAX * (v-u+1) + tran(MAX,a[v+1]);
    //printf("%lld ~ %lld\n",Old,New);
    if (Old<=New)
    {
        for (int i = u; i <= v; i++)
        {
            memo[i] = h;
            //printf("(%d) ",h);
        }
        //cout << Old;
        //printf(" -- f (%d, %d, %d): \n",u,v,h);
        return Old;
    }
    else
    {
        i = u-1; s = 0;
        for (j = u; j <= v; j++)
            if (a[j] == MAX)
        {
            memo[j] = MAX;
            s += f(i+1, j-1, MAX) + S*MAX;
            //printf("%d, %d, %d, cal ->> %lld\n",u,v,h,s);
            i = j;
        }
        s += f(i+1, v, MAX);
        if (a[u] == MAX) s += tran(a[u-1],MAX);
        //printf("cal ->> %lld\n",s);
        if (a[v] == MAX) s += tran(MAX,a[v+1]);
        //printf("cal ->> %lld\n",s);
        //cout << s; printf(" -- f (%d, %d, %d): \n",u,v,h);
        return s;
    }
}
int main()
{
    freopen("project.inp","r",stdin);
    freopen("project.out","w",stdout);
    scanf("%d %d %d %d", &n, &H, &S, &D);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    cout << f(1,n,(int)1e6+2) << endl;
    for (int i = 1; i <= n; i++) printf("%d ", memo[i]);
}*/
