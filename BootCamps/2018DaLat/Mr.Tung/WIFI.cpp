using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

const int N = 505;

int n, m;
int l[N], r[N], L1[N], L2[N], R1[N], R2[N];

int main() {
    freopen("WIFI.inp", "r", stdin);
    freopen("WIFI.out", "w", stdout);
    scanf("%d%d", &n, &m);
    //cerr << n << " " << m << endl;
    char str[N];
    int flag1 = 0, flag2 = 0;
    FOR(i, 1, n) {
        l[i] = m+1; r[i] = 0;
        scanf("%s", str+1);
        FOR(j, 1, m) if (str[j] == '*') {
            //cout << "row " << i << "\n";
            l[i] = j;
            FORD(k, m, 1) if (str[k] == '*')
                { r[i] = k; break; }
            if (flag1 == 0) flag1 = i;
            flag2 = i;
            break;
        }
        //cerr << l[i] << " " << r[i] << endl;
    }
    //cerr << flag1 << " " << flag2 << "\n";

    L1[0] = L2[n+1] = m+1;
    FOR(i, 1, n) L1[i] = min(L1[i-1], l[i]);
    FORD(i, n, 1) L2[i] = min(L2[i+1], l[i]);
    FOR(i, 1, n) l[i] = max(L1[i], L2[i]);

    R1[0] = R2[n+1] = 0;
    FOR(i, 1, n) R1[i] = max(R1[i-1], r[i]);
    FORD(i, n, 1) R2[i] = max(R2[i+1], r[i]);
    FOR(i, 1, n) r[i] = min(R1[i], R2[i]);

    FOR(i, flag1+1, flag2) {
        if (l[i] > r[i-1]) {
            l[i] = r[i-1];
            if (r[i] == 0) r[i] = l[i];
        } else if (r[i] < l[i-1]) {
            r[i] = l[i-1];
            if (l[i] == m+1) l[i] = r[i];
        }
    }

    FOR(i, 1, n) {
        //cerr << l[i] << " " << r[i] << endl;
        if (l[i] > r[i]) {
            FOR(j, 1, m) printf(".");
        } else {
            FOR(j, 1, l[i]-1) printf(".");
            FOR(j, l[i], r[i]) printf("*");
            FOR(j, r[i]+1, m) printf(".");
        }
        printf("\n");
    }

    return 0;
}
/** Happy Coding ^^ */

