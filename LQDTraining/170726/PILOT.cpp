using namespace std;
#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
#define fi first
#define se second
const int N = 1e5 + 10;
typedef pair<int, int> ii;
int n;
priority_queue<int> pq;
map<int, int> data;
ii a[N];

void Insert(int x) {
    if (data.find(x) == data.end()) data[x] == 1;
    else data[x] ++;
}
void Erase(int x) {
    if (data[x] == 1) data.erase(x);
    else data[x] --;
}
int main() {
    long long s = 0;

    freopen("PILOT.inp", "r", stdin);
    freopen("PILOT.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int h, x, y;
        scanf("%d %d %d", &h, &x, &y);
        s += x;
        a[i].fi = h;
        a[i].se = x-y;
    }

    sort(a+1, a+n+1);

    for (int i = 1; i <= n; i++) {
        pq.push(a[i].se);
        if (i%2) s -= pq.top(), pq.pop();
    }
    printf("%lld", s);
}
