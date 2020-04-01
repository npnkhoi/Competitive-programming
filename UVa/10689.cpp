using namespace std;
#include <stdio.h>

const int N = 1e7;
int s[N];
int a, b, n, m, md, i, period;


int main () {
    //freopen("test.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d %d", &a, &b, &n, &m);
        md = 1;
        while (m--) md *= 10;
        s[0] = a % md;
        s[1] = b % md;
        i = 1;
        while (i++) {
            s[i] = (s[i-1] + s[i-2]) % md;
            //printf("%d\n", s[i]);
            if (s[i] == s[1] && s[i-1] == s[0]) break;
        }
        period = i-1;
        printf("%d\n", s[n % period]);
        //printf("-----------\n");
    }
}
