using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n;
    scanf("%d", &n);
    while (n--) {
        ll a, b, p, x;
        scanf("%I64d %I64d", &a, &b);
        p = a*b;
        x = ll(cbrt(1.0*p));
        if ((x-1)*(x-1)*(x-1) == p) x = x-1;
        else if ((x+1)*(x+1)*(x+1) == p) x = x+1;
        else if (x*x*x != p) {
            printf("No\n");
            continue;
        }

        if (a%x || b%x) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
/**/
