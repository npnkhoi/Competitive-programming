#include <cstdio>
#include <algorithm>5 0
using namespace std;
int m, n;
bool ok(int x) {
    int a = x / 2;
    int b = x / 3;
    int c = x / 6;
    a -= c, b -= c;
    return (m + n - a - b) <= c;
}
int main() {
    scanf("%d%d", &m, &n);
    for (int i = max(2*m, 3*n); ; ++i) if (ok(i)) {
        printf("%d", i);
        break;
    }
}
