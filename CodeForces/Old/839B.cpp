using namespace std;
#include <stdio.h>
#include <algorithm>
#include <iostream>
const int N = 1e4 + 10;
int n, k, x, seat4, seat2, a[N], remain[4];
bool cmp(int a, int b) {
    if (a%2 != b%2) return a%2 == 0;
    return a > b;
}
int main() {
    scanf("%d %d", &n, &k);
    seat2 = seat4 = 4*n;
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    sort(a+1, a+k+1, cmp);
    //for (int i = 1; i <= k; i++) printf("%d ", a[i]); printf("\n");
    for (int i = 1; i <= k; i++) {
        x = a[i];
        printf("%d: ", a[i]);
        if (x > seat2) {
            x -= seat2;
            seat2 = 0;
            seat4 -= x/4*4;
            remain[x%4]++;
        }
        else {
            seat2 -= x/2*2;
            remain[x%2] ++;
        }
        if (seat2 < 0 || seat4 < 0) {printf("NO"); return 0;}
        else printf("%d %d\n", seat2, seat4);
    }
    cout << remain[1] << " " << remain[2] << " " << remain[3] << "\n";
    printf("%d %d\n", seat2, seat4);
    if (seat2 > 0)
        if (2*remain[1] <= seat2) {
            printf("YES");
            return 0;}
        else remain[1] -= seat2/2, seat2 = 0;
    if (seat2 == 0) {
        int tmp = min(remain[1], remain[2]);
        seat4 -= 4*tmp;
        remain[1] -= tmp;
        remain[2] -= tmp;

        seat4 -= 2*remain[1]/4*4;
        if (2*seat4 < 3*remain[2]) seat4 == -1;
        else seat4 = 1;

        seat4 -= 4*remain[3];
        if (seat2 < 0 || seat4 < 0) {printf("NO"); return 0;}
    }
    printf("YES");
}
