#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+50;
int n, t, lo, hi, mi;
int a[N];
priority_queue <int, vector<int>, greater<int>> stage;
int time(int k)
{
    //cout << k << ": ";
    priority_queue <int, vector<int>, greater<int>> stage;
    int s = 0;
    for (int i = 1; i <= k; i++)
    {
        s = max(s, a[i]);
        stage.push(a[i]);
    }
    for (int i = k+1; i <= n; i++)
    {
        int u = stage.top();
        stage.pop();
        s = max(s, u+a[i]);
        stage.push(u+a[i]);
    }
    //cout << s << "\n";
    return s;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    lo = 1; hi = n;
    while (lo<hi)
    {
        mi = (lo+hi)/2;
        if (time(mi) <= t) hi = mi;
        else lo = mi + 1;
    }
    cout << lo;
    return 0;
}
/**/
