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

const int N = 1e5 + 10;
int a[N];

int main() {
    freopen("rmqsq.inp","r",stdin);
    freopen("rmqsq.ans","w",stdout);
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l++; r++;
        int res = a[l];
        for (int i = l+1; i <= r; i++) res = min(res, a[i]);
        printf("%d\n", res);
    }
    return 0;
}
/**/
