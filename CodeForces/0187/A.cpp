using namespace std;
#include <stdio.h>
#include <iostream>
const int N = 2e5 + 10;
int n, a[N], id[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        id[x] = i;
    }
    int t = 1;
    for (int i = 1; i < n; i++) if (id[a[i-1]] < id[a[i]]) t++;
    else break;
    cout << n - t;
}
/*
scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        id[x] = i;
    }
    int res = n, tmp = n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n-1; i >= 0; i--) {
        int x = id[a[i]];
        if (tmp < x) res = min(res, x);
        tmp = min(tmp, x);
    }
    cout << n - res;*/
