#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "peach"
const int N = 1e5 + 5;
int m, A, B;
long long res;
vector<int> apple[(int)1e5];
priority_queue<int> heap;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d%d", &m, &A, &B);
    FOR(i, 1, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        apple[x].pb(y);
    }
    FOR(i, 1, B-1) {
        REP(j, apple[i].size()) heap.push(apple[i][j]);
        if (i >= A && !heap.empty()) {
            res += heap.top();
            heap.pop();
        }
    }
    printf("%lld\n", res);
}
/** Happy Coding :D */
