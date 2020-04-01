using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

int gcd(int a, int b) {
    //cout << a << " " << b << endl;
    return (b == 0) ? a : gcd(b, a % b); }

const int N = 1e3 + 10;
int n, a[N], res;
int main()
{
    //reopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    while (1) {
        int n = 0;
        while (1) {
            scanf("%d", &a[++n]);
            if (a[n] == 0) break;
        }
        if (n == 1) break;
        n--;

        for (int i = 1; i < n; i++) a[i] = abs(a[i] - a[n]);

        res = a[1];

        for (int i = 2; i < n; i++) res  = gcd(res, a[i]);
        printf("%d\n", res);
    }
    return 0;
}
/**/
