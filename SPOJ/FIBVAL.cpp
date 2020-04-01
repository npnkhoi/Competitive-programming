using namespace std;
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
int tc, f[20], a[40];
int main() {
    f[0] = 1;
    f[1] = 1;
    FOR(i, 2, 16) {
        f[i] = (f[i-1] + f[i-2]) % 7;
        //cout << f[i] << " " ;
    }
    scanf("%d", &tc);
    while (tc --) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (v-u+1 >= 32) printf("%d\n", (v-u+1) - (v-u+1) % 16);
        else {
            int res = -1;
            FOR(i, u, v-1) if (f[i%16] == f[(i+1)%16]) res = 2;
            printf("%d\n", res);
        }
    }

}
