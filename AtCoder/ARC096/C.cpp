using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define ll long long
#define ii pair<int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

const int N = 2e5 + 10;
int n, m;
int a[N][3];
int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >v) swap(u, v);
        if (u==1) a[v][0] = 1;
        if (v==n) a[u][1] = 1;
    }
    for (int i = 2; i < n; i++)
    if (a[i][0] && a[i][1]) {
        printf("POSSIBLE");
        return 0;
    }
    printf("IMPOSSIBLE");
    return 0;
}
/**/
