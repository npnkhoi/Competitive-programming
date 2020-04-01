using namespace std;
#include <stdio.h>
#include <algorithm>
struct point { double X, Y;};
const int N = 2000 + 10;
const double EPS = 0.0000000000000001;
const double oo = 1e18;
point p[N];
double coe[N];
long long res;
int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf %lf", &p[i].X, &p[i].Y);
    for (int i = 1; i <= n-2; i++) {
        int m = n-i;
        for (int j = i+1; j <= n; j++)
        coe[j-i] = (p[j].Y - p[i].Y == 0) ? oo : (p[j].X - p[i].X) / (p[j].Y - p[i].Y);
        sort(coe+1, coe + m+1);
        int l = 1;
        for (int r = 2; r <= m; r++) if (coe[r] - coe[l] > EPS) {
            int t = r-l;
            if (t >= 2) res += 1LL*t*(t-1)/2;
            l = r;
        }
        if (m-l >= 1) res += 1LL*(m-l)*(m-l+1)/2;
    }
    printf("%lld", res);
}
