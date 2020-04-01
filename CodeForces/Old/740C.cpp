using namespace std;
#include <stdio.h>
#include <algorithm>
int n, m, res;
int main() {
    scanf("%d %d", &n, &m);
    res = n;
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        res = min(res, v-u+1);
    }
    printf("%d\n", res);
    while (n--) printf("%d ", n%res);
}
