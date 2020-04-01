using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define For(i, a, b) for (int i = a; i <= b; i++)
#define F0r(i, b, a) for (int i = b; i >= a; i--)

typedef pair<int, int> ii;
typedef vector<int> vi;

using namespace std;

const int N = 2e3 + 10;
int k, n, a[N], b[N], res = 0;
set<int> data, ans;

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &k, &n);
    //data.insert(0);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
        if (data.find(a[i]) == data.end()) data.insert(a[i]);
    }

    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    for (int i = 1; i <= k; i++) {
        int x = b[1] - a[i];
        //printf("%d\n", x);
        if (ans.find(x) != ans.end()) continue;
        bool ok = 1;
        for (int j = 2; j <= n; j++) if (data.find(b[j]-x) == data.end())
            {   ok = 0; break; }
        res += ok;
        if (ok) ans.insert(x);
    }
    printf("%d", res);
    return 0;
}
/**/
