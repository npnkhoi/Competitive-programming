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

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = abs(a[i] - p);
    for (int i = 1; i <= k; i++) scanf("%d", &b[i]), b[i] = abs(b[i] - p);

    sort(1, n);
    return 0;
}
/**/
