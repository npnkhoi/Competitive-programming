//#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task ""

const int N = 5e3 + 5;
const int A = 5e4 + 5;
const int oo = 1e9+7;
int n, m, a[N], dist[A];
priority_queue< ii, vector<ii>, greater<ii> > heap;
void dijsktra() {
    REP(i, a[1]) dist[i] = oo;
    dist[0] = 0;
    heap.push(mp(0, 0));
    while (!heap.empty()) {
        int val = heap.top().first;
        int r = heap.top().second;
        heap.pop();

        if (val > dist[r]) continue;

        FOR(i, 2, n) {
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
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    dijsktra();
    scanf("%d", &m);
    while (m--) {
        int val;
        scanf("%d", &val);
        if (val >= dist[val % a[1]]) printf("TAK\n");
        else printf("NIE\n");
    }
}
/// Expelliarmus !
