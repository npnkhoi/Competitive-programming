#include <bits/stdc++.h>
using namespace std;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
    x[n+1] = x[1]; y[n+1] = y[1];
    for (int i = 1; i <= n; i++) {
        a.push_back(angle(i));
        a.push_back(abs(x[i+1] - x[i] + y[i+1] - y[i]));
    }

}
