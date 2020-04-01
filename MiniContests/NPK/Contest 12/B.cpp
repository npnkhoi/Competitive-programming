#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 50;
int p[N], h[N], s[N];
int n, tmp1, tmp2, tmp3, res;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        char ch;
        scanf(" %c",&ch);
        p[i] = p[i-1] + (ch=='P');
        h[i] = h[i-1] + (ch=='H');
        s[i] = s[i-1] + (ch=='S');
    }
    for (int i = 1; i <= n; i++)
    {
        tmp1 = p[i] + max(h[n]-h[i], s[n]-s[i]);
        tmp2 = h[i] + max(p[n]-p[i], s[n]-s[i]);
        tmp3 = s[i] + max(h[n]-h[i], p[n]-p[i]);

        res = max( max(res, tmp1), max(tmp2, tmp3));
    }
    cout << res;
    return 0;
}
/**/

