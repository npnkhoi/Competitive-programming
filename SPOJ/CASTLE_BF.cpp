
#include <bits/stdc++.h>
#define ii pair<int, int>
#define X first
#define Y second
const int N = 5005;
using namespace std;
ii X[N], Y[N], a[N];
bool chk[N][N];
int vX[N], vY[N];
int n, cnt;
unsigned long long SMAX, CMAX, SMIN, CMIN, S;

int main()
{
    freopen("castle.inp", "r", stdin);
    freopen("castle.ans", "w", stdout);
    scanf("%d", &n);
    int i, j, x, y, d;
    for(i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        X[i] = ii(x, i);
        Y[i] = ii(y, i);
    }
    sort(X + 1, X + 1 + n); sort(Y + 1, Y + 1 + n);
    X[0].X = X[1].X - 1; Y[0].X = Y[1].X - 1;
    d = 0;
    for(i = 1; i <= n; i++) {
        if (X[i].X != X[i - 1].X) {
            d++; vX[d] = X[i].X;
        }
        a[X[i].Y].X = d;
    }
    d = 0;
    for(i = 1; i <= n; i++) {
        if (Y[i].X != Y[i - 1].X) {
            d++; vY[d] = Y[i].X;
        }
        a[Y[i].Y].Y = d;
    }
    for(i = 1; i <= n; i++) chk[a[i].X][a[i].Y] = true;
    SMAX = 0; SMIN = -1;
    for(i = 1; i < n; i++) for(j = i + 1; j <= n; j++)
    if (a[i].X != a[j].X && a[i].Y != a[j].Y && chk[a[i].X][a[j].Y] && chk[a[j].X][a[i].Y]) {
        cnt++; S = (unsigned long long)abs(vX[a[i].X] - vX[a[j].X]) * abs(vY[a[i].Y] - vY[a[j].Y]);
        if (SMAX < S) {SMAX = S; CMAX = 1;} else if (SMAX == S) CMAX++;
        if (SMIN > S || SMIN == -1) {SMIN = S; CMIN = 1;} else if (SMIN == S) CMIN++;
    }
    cout << cnt / 2 << endl;
    if (cnt > 0) {
        cout << SMAX << " " << CMAX / 2 << endl;
        cout << SMIN << " " << CMIN / 2;
    }
    return 0;
}
