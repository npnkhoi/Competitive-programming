using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
bool mark[5];
int n;
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d", &n);
    mark[1] = mark[2] = 1;
    FOR(i, 1, n) {
        int val;
        scanf("%d", &val);
        if (mark[val] == 0) {
            printf("NO");
            exit(0);
        } else {
            int lose;
            FOR(i, 1, 3) if (mark[i] == 1 && i != val) lose = i;
            FOR(i, 1, 3) mark[i] = 1;
            mark[lose] = 0;
        }
    }
    printf("YES\n");
    return 0;
}
/** Happy Coding :D */
