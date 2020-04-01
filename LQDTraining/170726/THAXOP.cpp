using namespace std;
#include <stdio.h>
#include <queue>
priority_queue<int, vector<int>, greater<int> > pq;
int n;
long long num, s;
int main() {
    freopen("THAXOP.inp", "r", stdin);
    freopen("THAXOP.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {

        if (!pq.empty()) {
            long long t = pq.top();
            pq.pop();
            pq.push(2*t);
        }

        scanf("%lld", &num);
        s += num;
        pq.push(num);
    }
    for (int i = 1; i <= n; i++) {
        s -= pq.top();
        pq.pop();
    }
    printf("%lld", -s);
}
