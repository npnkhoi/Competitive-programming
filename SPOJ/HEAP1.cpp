// 1 day
// misunderstand problem!!
using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

priority_queue<ll, vector<ll>, greater<ll> > pq;
int n;

int main() {
    //freopen("test.inp", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        long long x;
        FOR(i, 1, n) scanf("%lld", &x), pq.push(x);

        long long s = 0;
        FOR(i, 1, n-1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            s += a+b;
            pq.push(a+b);
        }
        printf("%lld\n", s);
        pq.pop();
    }
}
