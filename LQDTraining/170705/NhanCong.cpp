using namespace std;
#include <stdio.h>
#include <iostream>
#include <queue>
int n, a[1010];
priority_queue<int> pq;
long long s;
int main() {
    freopen("NHANCONG.inp", "r", stdin);
    freopen("NHANCONG.out", "w", stdout);
    scanf("%d", &n);
    for (int i  = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    for (int i = 1; i < n; i ++) pq.push(a[i]*a[i+1]-a[i]-a[i+1]);
    s += pq.top(); pq.pop();
    s += pq.top();
    cout << s;
}
