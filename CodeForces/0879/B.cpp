using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
int n;
ll k;
deque<int> dq;

int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d%lld", &n, &k);
    if (k >= n-1) printf("%d\n", n);
    else {
        int num;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num);
            dq.push_back(num);
        }
        int x = 0, y = 0;
        while (y < k) {
            int u = dq.front(); dq.pop_front();
            int v = dq.front(); dq.pop_front();
            if (u < v) swap(u, v);
            dq.push_front(u); dq.push_back(v);
            if (u == x) ++y;
            else x = u, y = 1;
        }
        printf("%d\n", x);
    }
    return 0;
}
/** Happy Coding ^^ */

