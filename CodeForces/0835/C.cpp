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

const int C = 12;
const int X = 110;
const int N = 1e5 + 10;

int a[C][X][X], x[N], y[N], s[N];
int main() {
    //freopen("test.inp","r",stdin);
    //freopen("","w",stdout);
    int n, q, c;
    scanf("%d %d %d", &n, &q, &c);
    for (int i = 1; i <= n; i++) scanf("%d %d %d", &x[i], &y[i], &s[i]);

    for (int t = 0; t <= c; t++) {
        for (int j = 1; j <= n; j++) a[t][x[j]][y[j]] += (s[j] + t) % (c+1);

        /*for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) cout << a[t][i][j] << " \n"[j == 10];
        cout << endl;*/

        for (int i = 1; i < X; i++)
        for (int j = 1; j < X; j++)
            a[t][i][j] += a[t][i-1][j] + a[t][i][j-1] - a[t][i-1][j-1];
    }

    /*for (int i = 0; i <= c; i++)
    for (int j = 1; j <= 10; j++)
    for (int k = 1; k <= 10; k++)
        cout << a[i][j][k] << " \n"[k == 10];*/


    while (q--) {
        int t, u, v, p, q;
        scanf("%d %d %d %d %d", &t, &p, &q, &u, &v);
        t %= (c+1);
        printf("%d\n", a[t][u][v] - a[t][p-1][v] - a[t][u][q-1] + a[t][p-1][q-1]);
    }
    return 0;
}
/**/
