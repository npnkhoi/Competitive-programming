using namespace std;
#include <stdio.h>
#include <set>
#include <cmath>
#define mp make_pair
typedef pair<int, int> ii;

multiset<pair<ii, int> > data;
const int N = 1e3 + 10;
int x[N], y[N];
int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a%b);}

void simply(int &u, int &v) {
    if (u == 0) v = 1;
    else if (v == 0) u = 1;
    else {
        int t = gcd(abs(u), abs(v));
        u /= t; v /= t;
        if (v < 0) v = -v, u = -u;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        a[i] = i;
    }
    for (i = 1; i <= n; i++)
        swap(a[1], a[i]);
        sort(a+1, a+2*n+1, cmp);
    for (int i = n+1; i <= 2*n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        simply(x[i], y[i]);
        if (data.count(mp(mp(x[i], y[i]), 0)) >= 2) {
            int cnt = 0;
            for (int j = 1; j <= n && cnt <= 2; j++)
            if (x[j] == x[i] && y[j] == y[i]) printf("%d\n", j), cnt++;
            printf("%d\n", i);
            return 0;
        }
        if (data.count(mp(mp(x[i], y[i]), 0)) > 0
        && data.count(mp(mp(x[i], y[i]), 1)) > 0) {
            int j = 1;
            while (x[j] != x[i] || y[j] != y[i]) j++;
            printf("%d\n", j);
            j = n+1;
            while (x[j] != x[i] && y[j] != y[i]) j;;
            printf("%d\n", j);
            printf("%d\n", i);
            return 0;
        }
        data.insert(mp(mp(x[i], y[i]), 1));
    }
    printf("-1\n");
}
