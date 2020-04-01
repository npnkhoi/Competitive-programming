#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

int lab[300];
int n, k, x;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    memset(lab, -1, sizeof lab);
    FOR(i, 1, n) {
        scanf("%d", &x);
        if (lab[x] == -1) {
            int tmp = x;
            FORD(i, x-1, max(x-k+1, 0))
                if (lab[i] == -1) tmp = i;
                else break;
            if (tmp > 0 && x - lab[tmp-1] + 1 <= k) tmp = lab[tmp-1];
            FOR(i, tmp, x) lab[i] = tmp;
            printf("%d ", tmp);
        } else printf("%d ", lab[x]);
    }
}
