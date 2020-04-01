#include <bits/stdc++.h>
using namespace std;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int a[N], n;
void show(int l, int r) {
    if (l > r) return;
    int x = l;
    for (int i = l+1; i <= r; ++i) if (a[i] > a[x]) x = i;
    show(l, x-1); show(x+1, r); printf("%d ", a[x]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i] = i;
    do {
        for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
        cout << "--> ";
        show(1, n);
        cout << "\n";
    } while (next_permutation(a+1, a+n+1));
}
*/
