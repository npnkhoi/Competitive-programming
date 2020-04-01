//#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<long long, int> li;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task ""

const int A = 1e5 + 5;
int a[5];
long long dist[A], h;
priority_queue< li, vector<li>, greater<li> > heap;
void dijsktra() {
    REP(i, a[1]) dist[i] = h+1;
    dist[0] = 0;
    heap.push(mp(0, 0));
    while (!heap.empty()) {
        long long val = heap.top().first;
        int r = heap.top().second;
        //cerr << heap.size() << "\n";
        heap.pop();

        if (val > dist[r]) continue;

        FOR(i, 2, 3) {
            int r_ = (val + a[i]) % a[1];
            if (dist[r_] > val + a[i]) {
                dist[r_] = val + a[i];
                heap.push(mp(dist[r_], r_));
            }
        }
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%lld", &h);
    scanf("%d %d %d", &a[1], &a[2], &a[3]);
    dijsktra();
    //cerr << "ok\n";
    long long res = 0;
    REP(i, a[1]) if (dist[i] <= h)
        res += (h - dist[i] + a[1] - 1) / a[1];
    printf("%lld", res);
}
/// Expelliarmus !
